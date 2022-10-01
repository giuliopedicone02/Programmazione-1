/*
    Estendere l’esercizio precedente in modo da conservare tutti
    i caratteri stampati in un oggetto stringstream. Infine,
    stampare la lunghezza della stringa contenuta in esso

*/

#include <iostream>
#include <string>
using namespace std;

int main()
{
    char t = 122;
    string ss;

    /**************************************
     *              CICLO FOR
     ***************************************/

    for (char c = 122; c >= 97; c--)
    {
        if (c != 97 && c != 101 && c != 105 && c != 111 && c != 117) //a,e,i,o,u in ASCII
        {
            cout << c << endl;
            ss += c;
        }
    }

    cout << "Dimensione Stringa: " << ss.size() << endl;

    /**************************************
     *              CICLO WHILE
     ***************************************/

    while (t >= 97)
    {
        if (t != 97 && t != 101 && t != 105 && t != 111 && t != 117) //a,e,i,o,u in ASCII
        {
            cout << t << endl;
            ss += t;
        }

        t--;
    }

    cout << "Dimensione Stringa: " << ss.size() << endl;
}