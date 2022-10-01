/*

Descrivere un algoritmo in notazione NLS che prende in input
una matrice o array bidimensionale V di dimensione N × N.
L’algoritmo dovr`a calcolare e stampare la media aritmetica
dei valori differenza calcolati tra ogni valore della diagonale principale e il corrispondente valore della diagonale
secondaria.

*/

#include <iostream>
using namespace std;

int main()
{
    int n = 0;
    float somma = 0;

    cout << "Inserisci ordine delle matrice quadrata (n x n): ";
    cin >> n;

    int V[n][n];
    int DP[n];
    int DS[n];
    int Differenza[n];

    for (int r = 0; r < n; r++)
    {
        for (int c = 0; c < n; c++)
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

        for (int c = 0; c < n; c++)
        {
            cout << V[r][c] << "    ";
        }

        cout << endl;
    }

    cout << "\n*************************************\n\n";

    for (int c = 0; c < n; c++)
    {
        DP[c] = V[c][c]; //Valori della Diagonale Principale
    }

    int k = n - 1;

    for (int r = 0; r < n; r++)
    {
        DS[r] = V[r][k];
        k--;
    }

    for (int c = 0; c < n; c++)
    {
        Differenza[c] = DP[c] - DS[c]; //Differenza dei valori della Diagonale principale con quella Secondaria
    }

    cout << "Differenza = [";
    for (int t = 0; t < n; t++)
    {
        cout << " " << Differenza[t] << " ";
    }

    cout << "]";

    for (int c = 0; c < n; c++)
    {
        somma += Differenza[c];
    }

    cout << "Risultato: " << somma / n;
}