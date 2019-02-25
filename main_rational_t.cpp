/**
 * @file main_ractional_t.cpp
 *
 * @brief Main program page
 *
 * @ingroup PackageName
 *
 * @author Michal Ruzicka Ruzicka
 * Contact: alu0101305561@ull.edu.es
 */
 
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
    rational_t a(1, 2), b(3), c, d(3, 2);
    vector<rational_t> v; // Vector de tipo rational_t

    // Rellenamos el vector
    v.push_back(a);
    v.push_back(b);
    v.push_back(c);
    v.push_back(d);

    // Visualizamos los numeros racionales
    cout << "a: ";
    a.write();
    cout << "b: ";
    b.write();

    // Leemos por teclado un nuevo numero racional
    c.read();
    cout << "c: ";
    c.write();

    cout << "VALUES: " << endl;
    cout << "a.value()= " << a.value() << endl;
    cout << "b.value()= " << b.value() << endl;
    cout << "c.value()= " << c.value() << endl;

    // Prueba de la funcion search()
    cout << "Buscando el numero racional: ";
    c.write();

    if(search(v.data(), v.size(), c)) {
      cout << "Encontrado!" << endl;
    } else {
      cout << "El numero no se enuentra en el vector" << endl;
    }

    //v.erase(v.begin(), v.end());

    v.clear(); // Limpiamos el vector

    // Visualizamos el opuesto y reciproco de numeros racionales
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
    cout << "OPERACIONES CON NUMEROS RACIONALES: " << endl;
    cout << "a + b: " << a + b;

    cout << "b - a: " << b - a;

    cout << "a * b: " << a * b;

    cout << "a / b: ";
    a.divide(b).write();

    return 0;
}
