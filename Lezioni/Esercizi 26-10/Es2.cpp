/* 

Descrivere un algoritmo in notazione NLS che prende in input
una matrice o array bidimensionale V di dimensione N × M
ed un numero p.
L’algoritmo dovr`a calcolare e stampare le medie aritmetiche
di tutti i valori minori o uguali a p per le sole righe di
V che hanno indice dispari. 

*/

#include <iostream>
using namespace std;

int main()
{
    int n = 0, m = 0, p = 0, somma = 0, med = 0;

    cout << "Inserisci numero p: ";
    cin >> p;

    cout << "Inserisci numero di righe delle matrice: ";
    cin >> n;

    cout << "Inserisci numero di colonne delle matrice: ";
    cin >> m;

    int V[n][m];

    for (int r = 0; r < n; r++)
    {
        for (int c = 0; c < m; c++)
        {
            cout << "Inserisci valore riga " << r + 1 << " colonna " << c + 1 << ": ";
            cin >> V[r][c];
        }
    }

    cout << "\n\n*************************************\n";

    cout << "\nHai inserito la seguente matrice:\n\n";

    for (int r = 0; r < n; r++)
    {
        cout << "           ";

        for (int c = 0; c < m; c++)
        {
            cout << V[r][c] << "    ";
        }

        cout << endl;
    }

    cout << "\n*************************************\n\n";

    for (int r = 0; r < n; r++)
    {
        if (r % 2 == 0)
        {
            for (int c = 0; c < m; c++)
            {
                if (V[r][c] <= p)
                {
                    somma += V[r][c];
                    med++;
                }
            }
        }
    }

    cout << "La media dei valori minori o uguali a " << p << " delle sole righe con indice dispari: " << (float)somma / med;
}