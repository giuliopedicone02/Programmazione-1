
/* 

Descrivere un algoritmo in notazione NLS che prende in input
una matrice o array bidimensionale V di dimensioni N × M
e due numeri s e z.
L’algoritmo deve costruire un nuovo array W di dimensione M, in cui il generico elemento di W – sia i il suo indice
all’interno di W – sar`a uguale ad 1 se all’interno della colonna i-esima della matrice V esiste almeno una sequenza di
valori adiacenti di lunghezza minore o uguale a z la cui
somma sia maggiore o uguale ad s, altrimenti sar`a uguale
a 0.


*/

#include <iostream>
using namespace std;

int main()
{
    int n = 0, m = 0, s = 0, z = 0;

    cout << "Inserisci numero di righe della matrice: ";
    cin >> n;

    cout << "Inserisci numero di colonne della matrice: ";
    cin >> m;

    cout << "Inserisci numero s: ";
    cin >> s;

    do
    {
        cout << "Inserisci un numero z minore o uguale di " << n << ": ";
        cin >> z;

        if (z > n)
        {
            cout << "\nIl numero che hai inserito e' maggiore di " << n << "!!!" << endl
                 << endl;
        }
    } while (z > n);

    int V[n][m];
    int W[m];
    int somma = 0, i = 0, t1 = 0;

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

    for (int c = 0; c < m; c++)
    {
        somma = 0;
        t1 = 0;

        cout << "Colonna " << c + 1 << " = [ ";
        for (int r = 0; r < n; r++)
        {

            cout << V[r][c] << " ";

            if (t1 < z)
            {
                somma += V[r][c];
                t1++;
            }
        }
        cout << "]";

        cout << "\nSomma dei primi " << z << " numeri della colonna " << c + 1 << ": " << somma << endl
             << endl;

        if (somma >= s)
        {
            W[i] = 1;
        }
        else
        {
            W[i] = 0;
        }

        i++;
    }

    cout << "\n*************************************\n\n";

    cout << "Array W (Colonne la cui somma dei primi " << z << " valori adiacenti e' uguale o maggiore di " << s << ") = [";

    for (int i = 0; i < m; i++)
    {
        cout << " " << W[i] << " ";
    }

    cout << "]" << endl;
}
