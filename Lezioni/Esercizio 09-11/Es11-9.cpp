/*
    Codificare in C++ un programma che chiede all’utente di
    inserire due numeri decimali maggiori di zero e diversi tra
    loro (ES: 10.2 e 24.7), ed un numero intero N.

    • il programma calcola lo arrotondamento per eccesso o
    per difetto di entrambi i numeri, a seconda che la parte
    decimale sia maggiore o uguale a 0.5 oppure minore di
    0.5 rispettivamente. Siano a e b i due numeri ottenuti,
    con a < b.

    • per ogni numero a ≤ p ≤ b, calcola e stampa la
    somma degli N-1 numeri minori di p e la somma dei
    2N numeri maggiori di p;
*/

#include <iostream>
#include <math.h>
using namespace std;

int main()
{
    double x, y, n = 0.0;

    cout << "Inserisci primo numero: ";
    cin >> x;

    cout << "Inserisci secondo numero: ";
    cin >> y;

    cout << "Inserisci numero n: ";
    cin >> n;

    if (x < 0 || y < 0 || x == y)
    {
        cerr << "Errore inserimento dati! Riprovare!";
        return -1;
    }

    int a = round(x);
    int b = round(y);

    if (b < a)
    {
        int c = b;
        b = a;
        a = c;
    }

    int somma1 = 0, somma2 = 0, cont1 = n - 1, cont2 = n * 2;

    for (int c = a; c <= b; c++)
    {
        somma1 = 0, somma2 = 0;

        cout << "\n\n****************************\n\n";

        for (int t = c; t > c - cont1; t--)
        {
            somma1 += t;
        }

        cout << "Somma dei " << cont1 << " numeri minori di " << c << ": " << somma1 << endl;

        for (int t = c; t < c + cont2; t++)
        {
            somma2 += t;
        }

        cout << "Somma dei " << cont2 << " numeri maggiori di " << c << ": " << somma2 << endl;
    }
}