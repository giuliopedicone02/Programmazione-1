/*[Esercizio 5] Scrivere un metodo che prenda in input un parametro formale array A di interi di dimensioni n×m di elementi
distinti ed un array B di double di dimensioni k × n, e restituisca un array di n interi nel quale lo i-esimo elemento sia uguale
alla media aritmetica degli elementi presenti sia nella riga i-esima di A che nella colonna i-esima di B. NB: per decidere se un
elemento int della matrice A `e uguale ad un elemento double della matrice B si calcoli l’approssimazione all’intero pi`u vicino di
quest’ultimo.*/

#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <iomanip>
using namespace std;

double *func(int **A, int n, int m, double **B, int k)
{
    double *C = new double[n];
    int riga = 0, colonna = 0;
    double media = 0.0;

    for (int i = 0; i < n; i++)
    {
        riga = 0, colonna = 0, media = 0.0;

        for (int j = 0; j < m; j++)
        {
            riga += A[i][j];
        }

        for (int j = 0; j < k; j++)
        {
            colonna += B[j][i];
        }

        media = (double)(riga + colonna) / (m + k);

        C[i] = media;
    }

    return C;
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

void print_array(double *x, int cols)
{
    cout << "result[] = ";
    for (int c = 0; c < cols; c++)
    {
        cout << fixed << setprecision(2) << x[c] << "    ";
    }

    cout << endl;
}

int main()
{
    srand(time(NULL));

    int **a = new int *[5];
    double **b = new double *[5];

    for (int i = 0; i < 5; i++)
    {
        a[i] = new int[5];
        b[i] = new double[5];

        for (int j = 0; j < 5; j++)
        {
            a[i][j] = rand() % 9 + 1;
            b[i][j] = rand() % 9 + 1;
        }
    }

    cout << "\n\n************ MATRICE 1 *****************\n\n";
    print_dynamic(a, 5, 5);

    cout << "\n\n************ MATRICE 2 *****************\n\n";
    print_dynamic(b, 5, 5);

    cout << "\n\n************ ARRAY RISULTANTE *****************\n\n";

    double *result = func(a, 5, 5, b, 5);
    print_array(result, 5); // Numero di elementi delle colonne compresi tra 2 e 3
}