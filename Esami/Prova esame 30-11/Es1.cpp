#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <iomanip>

using namespace std;

double **func(double **A, int m, int n)
{
    srand(time(NULL));

    double **B = new double *[n];

    for (int i = 0; i < n; i++)
    {
        B[i] = new double[m];

        for (int j = 0; j < m; j++)
        {
            double s = rand() / (double)RAND_MAX; // Genera numeri in virgola mobile compresi tra 0 e 1

            if (A[j][i] > s)
            {
                B[i][j] = A[j][i];
            }
            else
            {
                B[i][j] = A[i % m][j % n];
            }
        }
    }

    return B;
}

void print_dynamic(double **x, int rows, int cols)
{

    for (int r = 0; r < rows; r++)
    {
        cout << "           ";

        for (int c = 0; c < cols; c++)
        {
            cout << fixed << setprecision(2) << x[r][c] << "    ";
        }

        cout << endl;
    }
}

int main()
{
    srand(time(NULL));

    double **d = new double *[5]; // Creiamo una matrice 5x5
    for (int i = 0; i < 5; i++)
    {
        d[i] = new double[5];
        for (int j = 0; j < 5; j++)
        {
            d[i][j] = rand() / (double)RAND_MAX; //% 9 + 1;
        }
    }

    cout << "\n\n************ MATRICE 1 *****************\n\n";

    print_dynamic(d, 5, 5);
    double **B = func(d, 5, 5);

    cout << "\n\n************ MATRICE 2 *****************\n\n";

    print_dynamic(B, 5, 5);
}