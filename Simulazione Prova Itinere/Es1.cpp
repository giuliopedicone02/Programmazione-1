/*1.Un santone induista si trova nella regione indiana del 
Rajasthan, quest'ultima simulata con una matrice 
quadrata di boolean in cui il valore true indica la 
presenza di un libro sacro. Scrivere un metodo che 
prenda in input una matrice di boolean e restituisca il 
numero di libri raccolti dal santone che, partendo dal 
centro della regione, esegue un movimento casuale 
unitario alla volta in una delle quattro direzioni prima 
che egli sia traviato dalle usanze oltre colonne. */

#include <iostream>
#include <stdlib.h>
#include <time.h>

#define C 5

using namespace std;

int santone(bool m[C][C])
{
    srand(time(NULL));

    int dir = rand() % 4;
    int r = C / 2;
    int c = C / 2;
    int libro = 0;

    do
    {
        dir = rand() % 4;

        switch (dir)
        {
        case 0: //Nord
        {
            if (m[r--][c])
            {
                libro++;
            }
            break;
        }
        case 1: //Sud
        {
            if (m[r++][c])
            {
                libro++;
            }
            break;
        }
        case 2: //Est
        {
            if (m[r][c++])
            {
                libro++;
            }
            break;
        }
        case 3: //Ovest
        {
            if (m[r][c--])
            {
                libro++;
            }
            break;
        }

        default:
        {
            break;
        }
        }
    } while (r >= 0 || c >= 0 || r >= C || c >= C);

    return libro;
}

int main()
{
    srand(time(NULL));

    bool matrice[C][C];

    for (int r = 0; r < C; r++)
    {
        for (int c = 0; c < C; c++)
        {
            matrice[r][c] = rand() % 2;
        }
    }

    cout << "\nHai inserito la seguente matrice:\n\n";

    for (int r = 0; r < C; r++)
    {
        cout << "           ";

        for (int c = 0; c < C; c++)
        {
            cout << matrice[r][c] << "    ";
        }

        cout << endl;
    }

    cout << "\n*************************************\n\n";

    cout << "Libri raccolti: " << santone(matrice);
}