/*
    Codificare in C++ un programma per il metodo montecarlo
    per il calcolo (approssimato) del numero π sulla base che si
    basi sull’esempio E16.1.
    NB: Il numero di campionamenti deve essere scelto
    dall’utente a tempo di esecuzione
*/

#include <iostream>
#include <stdlib.h> /* srand, rand */
#include <time.h>
#include <math.h>
using namespace std;

int main()
{
    /* initialize random seed: */
    srand(time(NULL));

    int a = 0;

    cout << "Inserisci numero di campionamenti: ";
    cin >> a;

    double x = 0.0, y = 0.0;
    int successi = 0;

    for (int c = 0; c < a; c++)
    {
        x = (((double)rand()) / RAND_MAX);
        y = (((double)rand()) / RAND_MAX);

        if ((pow(x, 2) + pow(y, 2)) <= 1)
        {
            successi++;
        }
    }

    double risultato = (double)successi / a;
    cout << "Risultato: " << risultato * 4;
}