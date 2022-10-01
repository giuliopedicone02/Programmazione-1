/* 

Descrivere un algoritmo in notazione NLS che prende in input
una matrice o array bidimensionale V di dimensioni N × M,
una seconda matrice W di dimensione L × Q che contiene
elementi distinti, ed un numero p.
L’algoritmo deve stampare tutti gli elementi della matrice
W che compaiono almeno p volte in V.


*/

#include <iostream>
using namespace std;

int main()
{
    int n = 0, m = 0, l = 0, q = 0, p = 0;

    cout << "Inserisci numero di righe della prima matrice: ";
    cin >> n;

    cout << "Inserisci numero di colonne della prima matrice: ";
    cin >> m;

    cout << "Inserisci numero di righe della seconda matrice: ";
    cin >> l;

    cout << "Inserisci numero di colonne della seconda matrice: ";
    cin >> q;

    cout << "Inserisci numero p: ";
    cin >> p;

    int V[n][m];
    int W[l][q];

    for (int r = 0; r < n; r++)
    {
        for (int c = 0; c < m; c++)
        {
            cout << "Inserisci valore riga " << r + 1 << " colonna " << c + 1 << " della prima matrice: ";
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

    for (int r = 0; r < l; r++)
    {
        for (int c = 0; c < q; c++)
        {
            cout << "Inserisci valore riga " << r + 1 << " colonna " << c + 1 << " della seconda matrice: ";
            cin >> W[r][c];
        }
    }

    cout << "\n\n*************************************\n";

    cout << "\nHai inserito la seguente matrice:\n\n";

    for (int r = 0; r < l; r++)
    {
        cout << "           ";

        for (int c = 0; c < q; c++)
        {
            cout << W[r][c] << "    ";
        }

        cout << endl;
    }

    cout << "\n*************************************\n\n";

    int cont = 0, i = 0;
    int ripetizioni[(n * m) + (l * q)], numRipetizioni[(n * m) + (l * q)];
    bool siRipete = false;

    for (int r1 = 0; r1 < n; r1++)
    {

        for (int c1 = 0; c1 < m; c1++)
        {

            cont = 0;
            siRipete = false;

            for (int r2 = 0; r2 < l; r2++)
            {
                for (int c2 = 0; c2 < q; c2++)
                {
                    if (V[r1][c1] == W[r2][c2])
                    {
                        cont++;
                    }
                }
            }

            if (cont >= p)
            {
                if (i == 0)
                {
                    ripetizioni[0] = V[r1][c1];
                    numRipetizioni[0] = cont;
                    i++;
                }
                else
                {
                    for (int t = 0; t < i; t++)
                    {
                        if (V[r1][c1] == ripetizioni[t])
                        {
                            siRipete = true;
                            break;
                        }
                    }

                    if (siRipete == false)
                    {
                        ripetizioni[i] = V[r1][c1];
                        numRipetizioni[i] = cont;
                        i++;
                    }
                }
            }
        }
    }

    for (int t = 0; t < i; t++)
    {
        cout << "Il numero " << ripetizioni[t] << " si ripete " << numRipetizioni[t] << " volte." << endl;
    }

    if (i == 0)
    {
        cout << "Le matrici inserite non hanno valori che si ripetono " << p << " o piu volte";
    }
}