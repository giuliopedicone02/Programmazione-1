/*33.Scrivere un metodo che prenda in input una
matrice quadrata A di puntatori ad interi e restituisca
un double calcolato come il rapporto tra la somma
degli elementi della diagonale principale di A e la
somma degli elementi della diagonale secondaria diA
stessa. NB: Si presti attenzione ai numeri mancanti! */
#include <iostream>
using namespace std;

double func(int ***A, int rows, int cols)
{
    int diagP = 0,
        diagS = 0;

    for (int c = 0; c < rows; c++)
    {
        diagP += *A[c][c];
    }

    int row = 0;
    int col = cols - 1;

    while (col >= 0)
    {
        diagS += *A[row][col];

        row++;
        col--;
    }

    return (double)diagP / diagS;
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

    int ***a = new int **[5];

    for (int i = 0; i < 5; i++)
    {
        a[i] = new int *[5];

        for (int j = 0; j < 5; j++)
        {
            a[i][j] = new int(rand() % 9 + 1);
        }
    }

    cout << "\n\n************ MATRICE *****************\n\n";
    print_dynamic(a, 5, 5);

    cout << "Risultato: " << func(a, 5, 5);
}