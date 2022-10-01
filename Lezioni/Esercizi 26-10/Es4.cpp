/* 

Descrivere un algoritmo in notazione NLS che prende in input
una matrice o array bidimensionale V di dimensioni N × M,
un array A di dimensione k, ed un numero w < M.
L’algoritmo stampa il valore di verit`a true se esiste almeno
una riga della matrice V che contiene almeno w elementi
maggiori di ogni elemento in A.


*/

#include <iostream>
using namespace std;

int main()
{
    int n = 0, m = 0, k = 0, w = 0;
    int controllo = 0;
    bool ris = false;

    cout << "Inserisci dimensione array : ";
    cin >> k;

    cout << "Inserisci numero di righe delle matrice: ";
    cin >> n;

    cout << "Inserisci numero di colonne delle matrice: ";
    cin >> m;

    do
    {
        cout << "Inserisci un numero minore di " << m << ": ";
        cin >> w;

        if (w > m)
        {
            cerr << "\nIl numero che hai inserito e' maggiore di " << m << "!!!" << endl
                 << endl;
        }
    } while (w > m);

    int V[n][m];
    int A[k];

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

    for (int t = 0; t < k; t++)
    {
        cout << "Inserisci valore " << t + 1 << " dell Array: ";
        cin >> A[t];
    }

    cout << "\n*************************************\n\n";

    cout << "\nHai inserito il seguente Array:\n\n";

    cout << "A = [";
    for (int t = 0; t < k; t++)
    {
        cout << " " << A[t] << " ";
    }

    cout << "]";

    cout << "\n*************************************\n\n";

    for (int r = 0; r < n; r++)
    {
        controllo = 0; //Ogni volta che cambiamo riga resettiamo il contatore dei numeri maggiori A[t]

        for (int c = 0; c < m; c++)
        {
            for (int t = 0; t < k; t++)
            {
                if (V[r][c] > A[t])
                {
                    controllo++;

                    if (controllo == w)
                    {
                        ris = true;
                        break;
                    }
                    break;
                }
            }
        }
    }

    cout << "Risultato algoritmo: " << (bool)ris;
}