/**
 * @file ractional_t.cpp
 *
 * @brief Function class page
 *
 * @ingroup PackageName
 *
 * @author Michal Ruzicka Ruzicka
 * Contact: alu0101305561@ull.edu.es
 */

#include <iostream>
#include <math.h>
#include <fstream>

#include "rational_t.hpp"

// Constructor
rational_t::rational_t(const int n, const int d)
{
    assert(d != 0); // Solo se puede representar numeros con Denominador != 0
    num_ = n, den_ = d;
}

// Devuelve el valor del numero en forma decimal
double rational_t::value() const
{
    return double(get_num()) / get_den();
}

// Devuelve el opuesto del numero racional
rational_t rational_t::opposite() const
{
    return rational_t((-1) * get_num(), get_den());
}

// Devuelve el reciproco del numero racional
rational_t rational_t::reciprocal() const
{
    return rational_t(get_den(), get_num());
}

// FUNCTIONES DE COMPARACION CON PRECISION

//Funcion de igualdad
 bool rational_t::equal(const rational_t& r, const double precision) const
{
    return fabs(value() - r.value()) < precision ? true : false;
}

// Funcion de superioridad
 bool rational_t::greater(const rational_t& r, const double precision) const
{
    return (value() - r.value()) > precision ? true : false;
}

// Funcion de inferioridad
bool rational_t::less(const rational_t& r, const double precision) const
{
    return fabs(r.value() - value()) > precision ? true : false;
}

// Funcion de cero
bool rational_t::cero_equal(const double precision) const
{
    return fabs(value()) < precision ? true : false;
}

// FUNCIONES PARA LOS OPERANDOS
// Se puede saber el Minimo comun multiplo entre dos numeros dividiendo
// uno cualquiera entre el el maximo comun divisor y multiplicandolo por el
// otro -> [(a / mcd(a,b)) * b]

// Maximo comun divisor
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

// Minimo comun divisor
int lcm(int a, int b)
{
    int temp = mcd(a, b);

    return temp ? (a / temp * b) : 0;
}

// FUNCIONES DE OPERACIONES

// Suma
 rational_t rational_t::add(const rational_t& r)
 {
   int min = lcm(get_den(), r.get_den());
   int new_nom = ((min / get_den()) * get_num())
                  + ((min / r.get_den()) * r.get_num());

   return rational_t (new_nom, min);
 }
// Resta
 rational_t rational_t::substract(const rational_t& r)
 {
   int min = lcm(get_den(), r.get_den());
   int new_nom = ((min / get_den()) * get_num())
                  - ((min / r.get_den()) * r.get_num());

    return rational_t (new_nom, min);
 }

// Producto
 rational_t rational_t::multiply(const rational_t& r)
 {
   return rational_t (get_num() * r.get_num(), get_den() * r.get_den());
 }

// Division
 rational_t rational_t::divide(const rational_t& r)
 {
   return rational_t (get_num() * r.get_den(), get_den() * r.get_num());
 }

// FUNCIONES POR SOBRECARGA DE OPEADORES
/**
 # @overload rational_t rational_t::operator+(const rational_t& r)
 *
 * @param r numero tipo rational_t
 */
 rational_t rational_t::operator+(const rational_t& r)
 {
   int min = lcm(get_den(), r.get_den());
   int new_nom = ((min / get_den()) * get_num())
                  + ((min / r.get_den()) * r.get_num());

   return rational_t (new_nom, min);
 }

 /**
  # @overload rational_t rational_t::operator-(const rational_t& r)
  *
  * @param r numero tipo rational_t
  */
 rational_t rational_t::operator-(const rational_t& r)
 {
   int min = lcm(get_den(), r.get_den());
   int new_nom = ((min / get_den()) * get_num())
                  - ((min / r.get_den()) * r.get_num());

    return rational_t (new_nom, min);
 }

 /**
  # @overload rational_t rational_t::operator*(const rational_t& r)
  *
  * @param r numero tipo rational_t
  */
 rational_t rational_t::operator*(const rational_t& r)
 {
   return rational_t (get_num() * r.get_num(), get_den() * r.get_den());
 }

 /**
  # @overload rational_t rational_t::operator/(const rational_t& r)
  *
  * @param r numero tipo rational_t
  */
 rational_t rational_t::operator/(const rational_t& r)
 {
   return rational_t (get_num() * r.get_den(), get_den() * r.get_num());
 }


// Funciones del flujo de salida
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
