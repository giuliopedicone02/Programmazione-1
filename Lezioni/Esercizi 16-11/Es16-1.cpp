/*
    Scrivere un programma in C++ che permetta di simulare
    una sequenza di N lanci di una coppia di dadi, dove N `e un
    numero scelto dall’utente oppure una costante scelta a tempo
    di compilazione. Il programma dovr`a stampare le sequenze
    dei due numeri (output primo dado e output secondo dado)
    in due colonne separate
*/

#include <iostream>
#include <stdlib.h> /* srand, rand */
#include <time.h>
using namespace std;

int main()
{
    /* initialize random seed: */
    srand(time(NULL));

    int a;

    cout << "Inserisci numero di lanci: ";
    cin >> a;

    int dado1[a], dado2[a];

    for (int c = 0; c < a; c++)
    {
        dado1[c] = rand() % 6 + 1;
        dado2[c] = rand() % 6 + 1;
    }

    for (int c = 0; c < a; c++)
    {
        cout << dado1[c] << "\t" << dado2[c] << endl;
    }
}