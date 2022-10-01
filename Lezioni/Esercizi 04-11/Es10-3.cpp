/*
     Siano s1, s2 ed s3 tre oggetti di tipo string e mys un
    altro oggetto di tipo string.

    • Se (A) la lunghezza di una delle tre stringhe s1, s2, s3 `e
    maggiore di 10 e se (B) almeno una di esse `e lunga almeno
    20 caratteri, allora copia nella variabile di tipo string
    denominata mys la concatenazione dei primi tre caratteri in
    s2 e degli ultimi tre caratteri in s3.

    • Se la condizione A `e verificata ma non la B, allora copia in
    mys la concatenazione delle tre stringhe, in ordine.

    • In tutti gli altri casi stampa la somma delle lunghezze delle
    tre stringhe.


*/

#include <iostream>
#include <string>
using namespace std;

int main()
{
    string a, b, c, mys;

    cout << "Inserisci prima parola: ";
    cin >> a;

    cout << "Inserisci seconda parola: ";
    cin >> b;

    cout << "Inserisci terza parola: ";
    cin >> c;

    if ((a.size() > 10 || b.size() > 10 || c.size() > 10) && (a.size() > 20 || b.size() > 20 || c.size() > 20))
    {
        mys = b.substr(0, 3) + c.substr(c.size() - 3, 3);
        cout << "mys: " << mys << endl;
    }
    else if ((a.size() > 10 || b.size() > 10 || c.size() > 10))
    {
        mys = a + b + c;
        cout << "mys: " << mys << endl;
    }
    else
    {
        cout << "Somma lunghezze: " << a.size() + b.size() + c.size() << endl;
    }
}