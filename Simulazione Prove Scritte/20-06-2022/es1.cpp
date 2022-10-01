#include <iostream>
using namespace std;

int **es1(bool ****A, int m, int n, int q, unsigned int l)
{
    int **res = new int *[m];
    int cont = 0;
    int seqLen = 0;

    for (int i = 0; i < m; i++)
    {
        res[i] = new int[n];
        for (int j = 0; j < n; j++)
        {
            for (int x = 0; x < q; x++)
            {
                if (A[i][j][x])
                {
                    for (int y = x + 1; y < q - 1; y++)
                    {
                        if (A[i][j][y])
                        {
                            if (*A[i][j][y - 1] == true && *A[i][j][y] == true)
                            {
                                cout << *A[i][j][y - 1] << " " << *A[i][j][y] << endl;
                                seqLen++;
                            }
                        }
                    }
                }

                if (seqLen == l)
                {
                    cont++;
                }

                seqLen = 0;
            }

            res[i][j] = cont;
            cont = 0;
        }
    }

    return res;
}

void print_dynamic(bool ****x, int faces, int rows, int cols)
{
    for (int f = 0; f < faces; f++)
    {
        cout << "Faccia " << f << endl;
        for (int r = 0; r < rows; r++)
        {
            cout << "           ";

            for (int c = 0; c < cols; c++)
            {
                cout << *x[f][r][c] << "    ";
            }

            cout << endl;
        }

        cout << endl;
    }
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

    cout << endl;
}

int main()
{
    srand(time(NULL));

    bool ****a = new bool ***[2];

    for (int i = 0; i < 2; i++)
    {
        a[i] = new bool **[5];

        for (int j = 0; j < 5; j++)
        {
            a[i][j] = new bool *[5];
            for (int q = 0; q < 5; q++)
            {
                a[i][j][q] = new bool(rand() % 2);
            }
        }
    }

    cout << "\n\n************ MATRICE *****************\n\n";
    print_dynamic(a, 2, 5, 5);

    int **res = es1(a, 2, 5, 5, 2);

    cout << "\n\n************ MATRICE RISULTANTE *****************\n\n";

    print_dynamic(res, 2, 5);
}