/*25.Scrivere un metodo che prenda in input una 
matrice di interi M di dimensioni nx m, uno short k ed 
un double x, e restituisca il valore booleano true se 
esiste almeno una colonna in M contenente 
esattamente k coppie di elementi adiacenti tali che il 
rapporto tra il primo elemento ed il secondo elemento 
di ogni coppia sia minore di x. NB: Si assuma k <= n -
1 e si presti attenzione alle divisioni per zero!*/
#include <iostream>
#include <math.h>
using namespace std;

bool func(int **M, int rows, int cols, short k, double x)
{
    double div = 0;
    int counter = 0;
    for (int c = 0; c < cols; c++)
    {
        for (int r = 0; r < rows - 1; r++)
        {
            div = M[r][c] / M[r + 1][c];
            if (div < x)
            {
                counter++;
            }
        }

        if (counter == x)
        {
            return true;
        }
    }

    return false;
}

void print_dynamic(int **x, int rows, int cols)
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

    int **a = new int *[5];

    for (int i = 0; i < 5; i++)
    {
        a[i] = new int[5];

        for (int j = 0; j < 5; j++)
        {
            a[i][j] = rand() % 9 + 1;
        }
    }

    cout << "\n\n************ MATRICE *****************\n\n";
    print_dynamic(a, 5, 5);

    cout << "Risultato: " << func(a, 5, 5, 3, 3);
}