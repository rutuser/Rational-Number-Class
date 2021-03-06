/**
 * @file ractional_t.hpp
 *
 * @brief Class program page
 *
 * @ingroup PackageName
 *
 * @author Michal Ruzicka Ruzicka
 * Contact: alu0101305561@ull.edu.es
 */
 
#pragma once

#include <iostream>
#include <cassert>
#include <cmath>
#include <fstream>

#define EPSILON 1e-6

using namespace std;

class rational_t
{
  int num_, den_;

public:
  rational_t(const int = 0, const int = 1);
  ~rational_t() {}

  int get_num() const
  {
    return num_;
  }

  int get_den() const
  {
    return den_;
  }

  void set_num(const int n)
  {
    num_ = n;
  }

  void set_den(const int d)
  {
    assert(d != 0), den_ = d;
  }

  double value(void) const;
  rational_t opposite(void) const;
  rational_t reciprocal(void) const;

  // FASE II
  bool equal(const rational_t &r, const double precision = EPSILON) const;
  bool greater(const rational_t &r, const double precision = EPSILON) const;
  bool less(const rational_t &r, const double precision = EPSILON) const;
  bool cero_equal(const double precision) const;

  int mcd(int a, int b);
  int mcm(int a, int b);


  // FASE IV
   rational_t add(const rational_t&);
   rational_t substract(const rational_t&);
   rational_t multiply(const rational_t&);
   rational_t divide(const rational_t&);

  // Sobrecarga de operadores
   rational_t operator+(const rational_t&);
   rational_t operator-(const rational_t&);
   rational_t operator*(const rational_t&);
   rational_t operator/(const rational_t&);

  void write(ostream &os = cout) const;
  void read(istream &is = cin);

  friend ostream &operator<<(ostream &os, const rational_t&);
};
