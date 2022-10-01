/*23.Scrivere un metodo che prenda in input un 
parametro formale matrice K di double di dimensioni n 
x m e due interi a e b, e restituisca un array A di short 
di dimensione m, in cui l'elemento A[i] e calcolato 
come il numero di elementi della colonna i-esima di K 
tali che, approssimati all'intero più vicino, siano 
compresi tra a e b (inclusi). NB: si assuma a < b. */
#include <iostream>
#include <math.h>
using namespace std;

short *func(double **K, int rows, int cols, int a, int b)
{
    short *result = new short[cols];
    int counter = 0;
    for (int c = 0; c < cols; c++)
    {
        counter = 0;

        for (int r = 0; r < rows; r++)
        {
            if (round(K[r][c]) >= a && round(K[r][c] <= b))
            {
                counter++;
            }
        }

        result[c] = counter;
    }

    return result;
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

void print_array(short *x, int cols)
{
    cout << "result[] = ";
    for (int c = 0; c < cols; c++)
    {
        cout << x[c] << "    ";
    }

    cout << endl;
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

    cout << "\n\n************ ARRAY RISULTANTE *****************\n\n";

    short *result = func(a, 5, 5, 2, 3);
    print_array(result, 5); //Numero di elementi delle colonne compresi tra 2 e 3
}