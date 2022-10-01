/*
    Siano a, b e c tre variabili di tipo int ed str una variabile
    di tipo string. Se a `e diverso da c e la lunghezza della stringa str
    `e minore di 8, allora copia in b la somma di a e c; Se a `e uguale a
    c e la lunghezza della stringa str `e minore di 8, allora copia in a
    il valore c − b; in tutti gli altri casi poni a, b e c a zero.

*/

#include <iostream>
#include <string>
using namespace std;

int main()
{
    int a, b, c;
    string str;

    cout << "Inserisci primo numero: ";
    cin >> a;

    cout << "Inserisci secondo numero: ";
    cin >> b;

    cout << "Inserisci terzo numero: ";
    cin >> c;

    cout << "Inserisci stringa: ";
    cin >> str;

    if (a != c && str.size() < 8)
    {
        b = a + c;
    }
    else if (a == c && str.size() < 8)
    {
        a = c - b;
    }
    else
    {
        a = b = c = 0;
    }

    cout << "A: " << a << endl
         << "B: " << b << endl
         << "C: " << c;
}