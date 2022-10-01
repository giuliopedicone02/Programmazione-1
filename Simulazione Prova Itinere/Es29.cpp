/*29.Scrivere un metodo che prenda in input una 
matrice quadrata A di numeri interi ed un double w, e 
restituisca il valore booleano true se il rapporto tra il 
minimo ed il massimo valore della diagonale 
secondaria di A e minore o uguale a w. */
#include <iostream>
using namespace std;

bool func(int **A, int rows, int cols, double w)
{
    int min = A[0][0], max = A[0][0];

    int row = 0;
    int col = cols - 1;

    while (col >= 0)
    {
        if (A[row][col] < min)
        {
            min = A[row][col];
        }
        else if (A[row][col] > max)
        {
            max = A[row][col];
        }

        row++;
        col--;
    }

    if ((double)min / max <= w)
    {
        return true;
    }
    else
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

    cout << "Risultato: " << func(a, 5, 5, 0.3);
}