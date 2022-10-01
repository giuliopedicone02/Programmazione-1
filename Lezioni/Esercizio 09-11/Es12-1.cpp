/*
   Codificare un programma in linguaggio C++ nel quale si
    chiedano all’utente due numeri in virgola mobile (a e b) da
    tastiera.
    Il programma deve calcolare e stampare la somma, la media,
    ed il max tra i due numeri.
    Tutti gli output del programma dovranno essere in notazione
    scientifica, con una precisione di 4 cifre dopo la virgola.


*/

#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    double a = 0.0, b = 0.0;

    cout << "Inserisci primo numero: ";
    cin >> a;

    cout << "Inserisci secondo numero: ";
    cin >> b;

    cout << "Somma: " << fixed << setprecision(4) << scientific << a + b << endl;

    cout << "Media: " << (a + b) / 2 << endl;

    cout << "Massimo: " << max(a, b);
}