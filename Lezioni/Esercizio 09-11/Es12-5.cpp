/*
  Codificare un programma in linguaggio C++ che chieda
    all’utente di inserire il raggio di un cerchio.
    Il programma dovr`a calcolare e stampare l’area e la
    circonferenza del cerchio.


*/

#include <iostream>
#include <math.h>
using namespace std;

int main()
{
    double r = 0.0;

    cout << "Inserisci valore del raggio: ";
    cin >> r;

    if (r <= 0)
    {
        cout << "Errore inserimento dati! Riprovare!";
        return -1;
    }

    cout << "Valore Area: " << pow(r, 2) * 3.14;
}