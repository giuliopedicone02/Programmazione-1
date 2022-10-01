/*
    Codificare in linguaggio C++ un algoritmo che stampi a ritroso la sequenza di caratteri da ’a’ a ’z’, ma non le vocali.
    Codificare due versioni differenti nelle quali si fa uso del
    costrutto for e del costrutto while rispettivamente.

*/

#include <iostream>
using namespace std;

int main()
{
    char t = 122;

    /**************************************
     *              CICLO FOR
     ***************************************/

    for (char c = 122; c >= 97; c--)
    {
        if (c != 97 && c != 101 && c != 105 && c != 111 && c != 117) //a,e,i,o,u in ASCII
        {
            cout << c << endl;
        }
    }

    /**************************************
     *              CICLO WHILE
     ***************************************/

    while (t >= 97)
    {
        if (t != 97 && t != 101 && t != 105 && t != 111 && t != 117) //a,e,i,o,u in ASCII
        {
            cout << t << endl;
        }

        t--;
    }
}