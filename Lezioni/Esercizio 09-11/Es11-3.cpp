/*
    Codificare un programma completo in linguaggio C++ in cui:
    • l’utente deve inserire da tastiera il capitale iniziale (C), il
    tasso di interesse (TI), il target (T) e numero di anni (N);

    • se uno tra T ed N `e un numero minore o uguale a zero,
    allora il programma non dovr`a tener conto di tale
    parametro; nel caso in cui sia T che N siano minori o
    uguali a zero allora il programma terminer`a con un
    messaggio di errore;


    • il programma dar`a in output il capitale finale ed il numero
    totale di anni di accumulo; come nello esercizio
    precedente, l’accumulo degli interessi sul montante si
    interrompe quando il capitale raggiunge o supera la cifra
    target T e comunque il numero di anni di accumulo non
    deve superare N.


*/

#include <iostream>
using namespace std;

int main()
{
    double capitale = 0.0, Tasso_Interesse = 0.0, T = 0.0;
    int N = 0, anno = 0;

    cout << "Inserisci il Capitale Iniziale (C): ";
    cin >> capitale;

    cout << "Inserisci il Tasso di Interesse (TI): ";
    cin >> Tasso_Interesse;

    cout << "Inserisci il Target (T): ";
    cin >> T;

    cout << "Inserisci il numero di anni (N): ";
    cin >> N;

    if (T <= 0 && N <= 0)
    {
        cerr << "Errore inserimento dati!" << endl;
        return -1;
    }
    else if (T <= 0)
    {
        while (anno <= N)
        {
            capitale += capitale * Tasso_Interesse;
            anno++;
        }

        cout << "Risultato: " << capitale << endl
             << "Numero di anni di accumulo: " << anno;
    }
    else if (N <= 0)
    {
        while (capitale < T)
        {
            capitale += capitale * Tasso_Interesse;
            anno++;
        }

        cout << "Risultato: " << capitale << endl
             << "Numero di anni di accumulo: " << anno;
    }
    else
    {
        while (capitale < T && anno <= N)
        {
            capitale += capitale * Tasso_Interesse;
            anno++;
        }

        cout << "Risultato: " << capitale << endl
             << "Numero di anni di accumulo: " << anno;
    }
}