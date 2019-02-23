#include <iostream>
#include <math.h>
#include <fstream>

#include "rational_t.hpp"

rational_t::rational_t(const int n, const int d)
{
    assert(d != 0);
    num_ = n, den_ = d;
}

double rational_t::value() const
{
    return double(get_num()) / get_den();
}

rational_t rational_t::opposite() const
{
    return rational_t((-1) * get_num(), get_den());
}

rational_t rational_t::reciprocal() const
{
    return rational_t(get_den(), get_num());
}

 bool rational_t::equal(const rational_t& r, const double precision) const
{
    return fabs(value() - r.value()) < precision ? true : false;
}

 bool rational_t::greater(const rational_t& r, const double precision) const
{
    return (value() - r.value()) > precision ? true : false;
}

bool rational_t::less(const rational_t& r, const double precision) const
{
    return fabs(r.value() - value()) > precision ? true : false;
}

bool rational_t::cero_equal(const double precision) const
{
    return fabs(value()) < precision ? true : false;
}

int mcd(int a, int b)
{
    for (;;)
    {
        if (a == 0) return b;
        b %= a;
        if (b == 0) return a;
        a %= b;
    }
}

int lcm(int a, int b)
{
    int temp = mcd(a, b);

    return temp ? (a / temp * b) : 0;
}

 rational_t rational_t::add(const rational_t& r)
 {
   int min = lcm(get_den(), r.get_den());
   int new_nom = ((min / get_den()) * get_num())
                  + ((min / r.get_den()) * r.get_num());

   return rational_t (new_nom, min);
 }

 rational_t rational_t::substract(const rational_t& r)
 {
   int min = lcm(get_den(), r.get_den());
   int new_nom = ((min / get_den()) * get_num())
                  - ((min / r.get_den()) * r.get_num());

    return rational_t (new_nom, min);
 }

 rational_t rational_t::multiply(const rational_t& r)
 {
   return rational_t (get_num() * r.get_num(), get_den() * r.get_den());
 }

 rational_t rational_t::divide(const rational_t& r)
 {
   return rational_t (get_num() * r.get_den(), get_den() * r.get_num());
 }

 rational_t rational_t::operator+(const rational_t& r)
 {
   int min = lcm(get_den(), r.get_den());
   int new_nom = ((min / get_den()) * get_num())
                  + ((min / r.get_den()) * r.get_num());

   return rational_t (new_nom, min);
 }

 rational_t rational_t::operator-(const rational_t& r)
 {
   int min = lcm(get_den(), r.get_den());
   int new_nom = ((min / get_den()) * get_num())
                  - ((min / r.get_den()) * r.get_num());

    return rational_t (new_nom, min);
 }

 rational_t rational_t::operator*(const rational_t& r)
 {
   return rational_t (get_num() * r.get_num(), get_den() * r.get_den());
 }

 rational_t rational_t::operator/(const rational_t& r)
 {
   return rational_t (get_num() * r.get_den(), get_den() * r.get_num());
 }



void rational_t::write(ostream &os) const
{
    os << get_num() << "/" << get_den() << "=" << value() << endl;
}

void rational_t::read(istream &is)
{
    cout << "Numerador: ";
    is >> num_;
    cout << "Denominador: ";
    is >> den_;
    assert(den_ != 0);
}

ostream &operator<<(ostream &os, const rational_t &r)
{
    os << r.get_num() << "/" << r.get_den() << "=" << r.value() << endl;
    return os;
}
