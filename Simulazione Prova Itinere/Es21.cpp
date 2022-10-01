/*21.Scrivere un metodo che prenda in input una 
matrice di double D ed un intero a, e restituisca il 
valore booleano true se esiste almeno una colonna in 
D nella quale la somma di una qualsiasi coppia di 
elementi adiacenti, approssimata all'intero piu vicino, 
sia uguale ad a.*/
#include <iostream>
#include <math.h>
using namespace std;

bool func(double **D, int rows, int cols, int a)
{
    for (int c = 0; c < cols; c++)
    {
        for (int r = 0; r < rows - 1; r++)
        {
            if (round(D[r][c] + D[r + 1][c]) == a)
            {
                return true;
            }
        }
    }

    return false;
}

void print_dynamic(double **x, int rows, int cols)
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

    double **a = new double *[5];

    for (int i = 0; i < 5; i++)
    {
        a[i] = new double[5];

        for (int j = 0; j < 5; j++)
        {
            a[i][j] = rand() % 9 + 1;
        }
    }

    cout << "\n\n************ MATRICE *****************\n\n";
    print_dynamic(a, 5, 5);

    cout << "Risultato: " << func(a, 5, 5, 2);
}