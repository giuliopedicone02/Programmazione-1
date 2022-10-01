/*
5.Scrivere un metodo che prenda come parametri 
formali una matrice A n×m di long ed un long x, e 
restituisca in output l’indice della colonna di A con il 
maggior numero di occorrenze di x
*/
#include <iostream>
#include <stdlib.h>
#include <math.h>
using namespace std;

int func(long **A, int rows, int cols, long x)
{
    int max = -1, col = 0;

    for (int c = 0; c < cols; c++)
    {
        for (int r = 0; r < rows; r++)
        {
            if (x == A[r][c])
            {
                if (x > max)
                {
                    max = x;
                    col = c;
                }
            }
        }
    }

    if (max >= 0)
    {
        return col;
    }
    else
    {
        return -1;
    }
}

void print_dynamic(long **x, int rows, int cols)
{

    for (int r = 0; r < rows; r++)
    {
        cout << "           ";

        for (int c = 0; c < cols; c++)
        {
            cout << x[r][c] << "    ";
        }

        cout << endl;
    }
}

int main()
{
    srand(time(NULL));

    long **d = new long *[5]; //Creiamo una matrice 5x3
    for (int i = 0; i < 5; i++)
    {
        d[i] = new long[3];
        for (int j = 0; j < 3; j++)
        {
            d[i][j] = rand() % 9 + 1;
        }
    }

    print_dynamic(d, 5, 3);
    cout << "Colonna con maggior numero di occorrenze di 2: " << func(d, 5, 3, 2);
}