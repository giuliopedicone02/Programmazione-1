/*2.Due stringhe si dicono sorelle se hanno lo stesso
numero di vocali. Scrivere un metodo che prenda in
input una matrice A di puntatori a stringhe, e
restituisca un boolean che indichi se esiste una
colonna di A in cui sono puntate almeno due stringhe
sorelle.*/

#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define R 3
#define C 5

using namespace std;

bool sorelle(string A[R][C])
{
    int vocali[C];
    int cont = 0;

    for (int c = 0; c < C; c++)
    {
        for (int r = 0; r < R; r++)
        {
            cont = 0;
            for (int x = 0; x < A[r][c].length(); x++)
            {
                if (A[r][c][x] == 65 || A[r][c][x] == 97 || A[r][c][x] == 69 || A[r][c][x] == 101 || A[r][c][x] == 73 || A[r][c][x] == 79 || A[r][c][x] == 85 || A[r][c][x] == 117)
                {
                    cont++;
                }
            }

            vocali[r] = cont;
        }

        for (int c = 0; c < C; c++)
        {
            for (int t = c + 1; t < C; t++)
            {
                if (vocali[c] == vocali[t])
                {
                    return true;
                }
            }
        }
    }

    return false;
}
int main()
{
    string A[R][C] = {"Arte",
                      "Ponte",
                      "Verde",
                      "Giallo",
                      "Auto",
                      "Carlo",
                      "Fratello",
                      "Sorella",
                      "Luca",
                      "Porto",
                      "Latte",
                      "Cereali",
                      "Giovanni",
                      "Maria",
                      "Farinella"};

    if (sorelle(A))
    {
        cout << "Esistono almeno due stringhe sorelle nella stessa colonna";
    }
    else
    {
        cout << "Non esistono almeno due stringhe sorelle nella stessa colonna";
    }
}