/* 

Descrivere un algoritmo in notazione NLS che prende in input una matrice V di dimensioni N × M ed uno array W di
dimensione L.
L’algoritmo dovr`a calcolare, per ogni riga di V, il numero di
elementi dello array W che sono compresi tra il minimo e
il massimo valore (estremi inclusi) della riga stessa

*/

#include <iostream>
using namespace std;

int main()
{
    int n = 0, m = 0, l = 0;

    cout << "Inserisci dimensione array: ";
    cin >> l;

    cout << "Inserisci numero di righe delle matrice: ";
    cin >> n;

    cout << "Inserisci numero di colonne delle matrice: ";
    cin >> m;

    int V[n][m];
    int W[l];

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

    for (int t = 0; t < l; t++)
    {
        cout << "Inserisci valore " << t + 1 << " dell Array: ";
        cin >> W[t];
    }

    cout << "\n*************************************\n\n";

    cout << "\nHai inserito il seguente Array:\n\n";

    cout << "W = [";
    for (int t = 0; t < l; t++)
    {
        cout << " " << W[t] << " ";
    }

    cout << "]";

    cout << "\n*************************************\n\n";

    int min = V[0][0], max = V[0][0], cont = 0;

    for (int r = 0; r < n; r++)
    {
        min = V[r][0], max = V[r][0], cont = 0;

        for (int c = 0; c < m; c++)
        {
            if (V[r][c] < min)
            {
                min = V[r][c];
            }

            if (V[r][c] > max)
            {
                max = V[r][c];
            }
        }

        for (int t = 0; t < l; t++)
        {
            if (W[t] <= max && W[t] >= min)
            {
                cont++;
            }
        }

        cout << "Nella riga " << r << " ci sono " << cont << " valori compresi tra " << min << " e " << max << endl;
    }
}