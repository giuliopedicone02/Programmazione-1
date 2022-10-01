/*27.Scrivere un metodo che prenda come parametro 
formale una matrice A n×m di puntatori ad intero, e 
restituisca in output un bool che indichi se esistono 
due elementi in A che puntano allo stesso valore intero 
(anche in locazioni differenti).*/
#include <iostream>
using namespace std;

bool func(int ***A, int rows, int cols)
{
    for (int r = 0; r < rows; r++)
    {

        for (int c = 0; c < cols; c++)
        {
            int *pos = A[r][c];

            for (int j = 0; j < rows; j++)
            {
                for (int k = 0; k < cols; k++)
                {
                    if (pos == A[j][k])
                    {
                        return true;
                    }
                }
            }
        }
    }

    return false;
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