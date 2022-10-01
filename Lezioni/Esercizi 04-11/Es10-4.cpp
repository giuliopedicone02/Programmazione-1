/*
    Scrivere del codice C++ per testare le seguenti
    disuguaglianze:
    "sale" < "sole"?
    "uova" < "suola"?
    "Marco" < "marco"?
    "asta" < "canasta"?
    "123prova" < "Abaco"?

*/

#include <iostream>
using namespace std;

int main()
{
    string a, b;

    cout << "Inserisci prima parola: ";
    cin >> a;

    cout << "Inserisci seconda parola: ";
    cin >> b;

    cout << a << " ha " << a.size() << " caratteri" << endl;
    cout << b << " ha " << b.length() << " caratteri" << endl;

    if (a == b)
    {
        cout << "Hai inserito due parole uguali" << endl;
    }

    if (a < b)
    {
        cout << a << " minore di " << b << endl;
    }
    else
    {

        cout << a << " maggiore di " << b << endl;
    }

    if (a.size() < b.size())
    {
        cout << a << " e' piu' piccolo di " << b << endl;
    }
    else if (a.size() > b.size())
    {
        cout << a << " e' piu' grande di " << b << endl;
    }
    else
    {
        cout << "Le due stringhe hanno lo stesso numero di caratteri";
    }
}