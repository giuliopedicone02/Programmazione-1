/*
  Scrivere un programma in C++ nel quale si chiede all’utente di
    inserire due numeri N ed M entrambi maggiori di 1.
    Successivamente:
    • operare i soliti controlli ed eventuali arrotondamenti sui
    numeri inseriti dallo utente;
    • inizializzare la matrice con numeri a piacere in virgola mobile;
    • calcolare e stampare il prodotto di uno scalare scelto a piacere
    (es: 3.542) con la matrice;
    • definire una ulteriore matrice quadrata avente la dimensione
    della pi`u grande matrice quadrata che `e possibile ricavare
    dalla matrice esistente. ES: per una matrice 8x9 le dimensioni
    della nuova matrice saranno 8x8;
    • riempire la nuova matrice con i corrispondnti elementi della
    prima matrice.



*/

#include <iostream>
#include <math.h>
using namespace std;

int main()
{
    int n = 0, m = 0;
    double num = 0;

    cout << "Inserisci numero righe: ";
    cin >> n;

    cout << "Inserisci numero colonne: ";
    cin >> m;

    if (n < 1 || m < 1)
    {
        cerr << "Attenzione! Hai inserito un numero minore di 1!";
        return -1;
    }
    else
    {
        double matrice[n][m];

        for (int r = 0; r < n; r++)
        {
            for (int c = 0; c < m; c++)
            {
                cout << "Inserisci valore riga " << r + 1 << " colonna " << c + 1 << ": ";
                cin >> matrice[r][c];
            }
        }

        cout << "\n\n*************************************\n";

        cout << "\nHai inserito la seguente matrice:\n\n";

        for (int r = 0; r < n; r++)
        {
            cout << "           ";

            for (int c = 0; c < m; c++)
            {
                cout << matrice[r][c] << "    ";
            }

            cout << endl;
        }

        cout << "\n*************************************\n\n";

        cout << "Inserisci numero per prodotto scalare: ";
        cin >> num;

        cout << "\n\n*************************************\n";

        cout << "\nProdotto scalare della matrice con: " << num << "\n\n";

        for (int r = 0; r < n; r++)
        {
            cout << "           ";

            for (int c = 0; c < m; c++)
            {
                cout << matrice[r][c] * num << "    ";
            }

            cout << endl;
        }

        int num = min(n, m);
        double matriceQuadrata[num][num];

        for (int r = 0; r < num; r++)
        {
            for (int c = 0; c < num; c++)
            {

                matriceQuadrata[r][c] = matrice[r][c];
            }
        }

        cout << "\n\n*************************************\n";

        cout << "\nMatrice " << num << "*" << num << " quadrata ricavata:\n\n";

        for (int r = 0; r < num; r++)
        {
            cout << "           ";

            for (int c = 0; c < num; c++)
            {
                cout << matriceQuadrata[r][c] << "    ";
            }

            cout << endl;
        }

        cout << "\n*************************************\n\n";
    }
}