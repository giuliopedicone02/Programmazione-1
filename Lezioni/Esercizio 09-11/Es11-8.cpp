/*
  Codificare in linguaggio C++ un algoritmo che stampi le prime N potenze di 2, dove N `e un parametro scelto dall’utente
    (input da tastiera).


*/

#include <iostream>
#include <math.h>
using namespace std;

int main()
{
    int n = 0;

    cout << "Inserisci numero n: ";
    cin >> n;

    for (int c = 0; c < n; c++)
    {
        cout << pow(2, c) << endl;
    }
}