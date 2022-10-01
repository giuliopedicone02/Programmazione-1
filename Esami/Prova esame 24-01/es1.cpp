#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int ***func(int ***A, int n, int m, int a, int b, short s)
{
    srand(time(NULL));
    int temp = 0, cont = 0;

    int ***B = new int **[n];
    for (int i = 0; i < n; i++)
    {
        B[i] = new int *[m];
        for (int j = 0; j < m; j++)
        {
            if (!A[i][j])
            {
                B[i][j] = nullptr;
            }
            else
            {
                cont = 0;
                temp = *A[i][j];

                for (int c = 0; c < n; c++)
                {
                    if (temp == *A[c][j])
                    {
                        cont++;
                    }
                }

                if (cont >= s)
                {
                    B[i][j] = new int(-1 * (rand() % (b - a + 1) + a));
                }
                else
                {
                    B[i][j] = new int(temp);
                }
            }
        }
    }

    return B;
}
void print_dynamic(int ***S, int rows, int cols)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            cout << '\t' << *S[i][j];
        }
        cout << endl;
    }
}
int main()
{
    srand(time(NULL));

    int ***d = new int **[4]; // Creiamo una matrice 4x5
    int ***r = new int **[4];
    for (int i = 0; i < 4; i++)
    {
        d[i] = new int *[5];
        r[i] = new int *[5];
        for (int j = 0; j < 5; j++)
        {
            d[i][j] = new int(rand() % 9 + 1);
            r[i][j] = nullptr;
        }
    }

    print_dynamic(d, 4, 5);
    r = func(d, 4, 5, 3, 7, 2);
    cout << endl;
    print_dynamic(r, 4, 5);
}