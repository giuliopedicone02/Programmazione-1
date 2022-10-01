/*
    Codificare in linguaggio C++ un algoritmo che stampi a ritroso i numeri pari minori o uguali a mille; Il loop deve comunque
    terminare se la somma dei numeri precedentemente stampati
    `e maggiore o uguale a centomila.
*/

#include <iostream>
using namespace std;

int main()
{
    int somma = 0;

    for (int c = 1000; c >= 0; c--)
    {
        if (c % 2 == 0 && somma < 100000)
        {
            cout << c << endl;
            somma += c;
        }
    }
}