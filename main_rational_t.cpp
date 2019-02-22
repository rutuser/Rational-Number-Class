
#include <iostream>
#include <cmath>
#include <vector>
#include "rational_t.hpp"

using namespace std;

// FASE III: función de búsqueda
bool search(const rational_t *v, const int n, const rational_t &x)
{
    for (int i = 0; i < n; i++)
    {
        if (v[i].value() == x.value())
        {
            return true;
        }
    }
    return false;
};

int main()
{
    rational_t a(1, 2), b(3), c, d(3);
    vector<rational_t> v;

    v.push_back(a);
    v.push_back(b);
    v.push_back(c);

    cout << "a.value()= " << a.value() << endl;
    cout << "b.value()= " << b.value() << endl;
    cout << "c.value()= " << c.value() << endl;

    cout << search(v.data(), v.size(), d) << endl;

    cout << "a: ";
    a.write();
    cout << "b: ";
    b.write();

    c.read();
    cout << "c: ";
    c.write();

    cout << "Opuesto de a: ";
    a.opposite().write();
    cout << "Recíproco de b: ";
    b.reciprocal().write();

    //FASE III: ejemplo
    // int n;
    // cout << "Introduce n: ";
    // cin >> n;
    // rational_t *v = new rational_t[n];
    // if (v != NULL) {
    //   for (int i = 0; i < n; i++) {
    //     v[i] = rational_t(1, pow(2, i));
    //     v[i].write();
    //   }

    //   rational_t x(1, pow(2, 3));
    //   bool b = search(v, n, x);
    //   cout << "Valor " << x.value() << (b ? "" : "no") << " encontrado" << endl;

    //   delete[] v;
    // }
    // else {
    //   cerr << "ERROR: no se ha podido reservar memoria dinámica" << endl;
    //   return 1;
    // }

    // FASE IV
    // cout << "a + b: ";
    // a.add(b).write();

    // cout << "b - a: ";
    // b.substract(a).write();

    // cout << "a * b: ";
    // a.multiply(b).write();

    // cout << "a / b: ";
    // a.divide(b).write();

    return 0;
}