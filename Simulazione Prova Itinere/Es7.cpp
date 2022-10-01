/*
7.Scrivere un metodo che prenda in input un 
parametro formale matrice A di puntatori ad interi di 
dimensione nxm, due double d1 e d2 ed uno short s, e 
restituisca il numero di colonne di A nelle quali 
esistano almeno s coppie di elementi contigui (ES: 
A[1][1] e A[2][1]) tali che il rapporto tra il primo ed il 
secondo elemento sia compreso tra d1 e d2. NB: Si 
assuma a priori che s<=n-1 e che d1 < d2. Si presti 
attenzione ai numeri "mancanti"nella matrice A.*/
#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;

int func(int ***A, int rows, int cols, double d1, double d2, short s)
{
    int cont = 0;
    int res = 0;
    for (int c = 0; c < cols; c++)
    {
        cont = 0;
        for (int r = 0; r < rows - 1; r++)
        {
            if ((*A[r][c] / *A[r + 1][c]) >= d1 && (*A[r][c] / *A[r + 1][c]) <= d2)
            {
                cont++;
            }
        }

        if (cont >= s)
        {
            res++;
        }
    }

    return res;
}

void print_dynamic(int ***x, int rows, int cols)
{

    for (int r = 0; r < rows; r++)
    {
        cout << "           ";

        for (int c = 0; c < cols; c++)
        {
            cout << *x[r][c] << "    ";
        }

        cout << endl;
    }
}

int main()
{
    srand(time(NULL));

    int ***d = new int **[5]; //Creiamo una matrice di puntatori ad interi 5x5
    for (int i = 0; i < 5; i++)
    {
        d[i] = new int *[5];
        for (int j = 0; j < 5; j++)
        {
            d[i][j] = new int(rand() % 9 + 1);
        }
    }

    print_dynamic(d, 5, 5);
    cout << "Numero di colonne in cui ci sono almeno 2 valori contigui il cui rapporto e' compreso tra 0.3 e 1.5: " << func(d, 5, 5, 0.3, 1.5, 2);
}