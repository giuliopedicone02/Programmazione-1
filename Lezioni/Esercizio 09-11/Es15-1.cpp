/*
    Scrivere un programma in C++ nel quale si chiede all’utente un
    numero qualunque p. Successivamente:
    • Se il numero p `e minore di 1, stampare un messaggio di errore.
    • Se il numero p `e maggiore o uguale a 1, arrotondare il numero
    stesso allo intero pi`u vicino e allocare un array di quella
    dimensione.
    • Inizializzare lo array con valori a piacere per tre volte
    mediante un ciclo: i) con il costrutto for, ii) con il costrutto
    while, iii) con il costrutto do-while.
    • Stampare tutti i valori dello array con un ciclo usando un
    costrutto a scelta.


*/

#include <iostream>
#include <math.h>
using namespace std;

int main()
{
    double p = 0.0;
    int x = 0;

    cout << "Inserisci un numero: ";
    cin >> p;

    if (p < 1)
    {
        cerr << "Attenzione! Numero minore di 1!";
        return -1;
    }
    else
    {
        int b = round(p);
        int array[b];

        for (int c = 0; c < b; c++)
        {
            cout << "Inserisci valore " << c + 1 << ": ";
            cin >> array[c];
        }

        cout << "\n*************************************\n";

        cout << "\nHai inserito il seguente Array:\n\n";

        cout << "Array con For = [";

        for (int t = 0; t < b; t++)
        {
            cout << " " << array[t] << " ";
        }

        cout << "]";

        cout << "\n\n*************************************\n\n";

        while (x < b)
        {
            cout << "Inserisci valore " << x + 1 << ": ";
            cin >> array[x];
            x++;
        }

        cout << "\n*************************************\n";

        cout << "\nHai inserito il seguente Array:\n\n";

        cout << "Array con While = [";

        for (int t = 0; t < b; t++)
        {
            cout << " " << array[t] << " ";
        }

        cout << "]";

        x = 0;

        cout << "\n\n*************************************\n\n";

        do
        {
            cout << "Inserisci valore " << x + 1 << ": ";
            cin >> array[x];
            x++;
        } while (x < b);

        cout << "\n*************************************\n";

        cout << "\nHai inserito il seguente Array:\n\n";

        cout << "Array con Do While = [";

        for (int t = 0; t < b; t++)
        {
            cout << " " << array[t] << " ";
        }

        cout << "]";

        cout << "\n\n*************************************\n\n";
    }
}