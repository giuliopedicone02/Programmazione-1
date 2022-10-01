/*
Codificare un programma in linguaggio C++ che chieda
all’utente di inserire tre numeri da tastiera. L’utente pu`o
inserire numeri interi o decimali.
Il programma dovr`a calcolare e stampare l’arrotondamento al
valore intero pi`u vicino di ogni numero inserito dallo utente.
*/

#include <iostream>
#include <math.h>
using namespace std;

int main()
{
    double a = 0.0, b = 0.0, c = 0.0;

    cout << "Inserisci primo numero: ";
    cin >> a;

    cout << "Inserisci secondo numero: ";
    cin >> b;

    cout << "Inserisci terzo numero: ";
    cin >> c;

    cout << "\n\n****************************\n\n";

    cout << "Primo numero arrotondato: " << round(a) << endl;

    cout << "Secondo numero arrotondato: " << round(b) << endl;

    cout << "Terzo numero arrotondato: " << round(c) << endl;
}