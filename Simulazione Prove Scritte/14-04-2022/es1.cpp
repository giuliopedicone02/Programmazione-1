#include <iostream>
using namespace std;

void es1(int ****A, int n, short q)
{
    for (int i = 0; i < n; i++) // Facce
    {
        for (int j = 0; j < n; j++) // Righe
        {
            for (int k = 0; k < n; k++) // Colonne
            {
            }
        }
    }
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