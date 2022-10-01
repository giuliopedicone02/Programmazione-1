/*[Esercizio 4] Scrivere un metodo che prenda in input due parametri formali: una matrice A di dimensioni n × m ed una
matrice B di dimensioni k × n entrambe di interi positivi. Il metodo restituisca un array C di double di dimensione n nel quale
lo i-esimo elemento dello array C sia uguale al rapporto tra la somma degli elementi della riga i-esima di A e il prodotto degli
elementi della colonna i-esima di B*/

#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <iomanip>
using namespace std;

double *func(int **A, int n, int m, int **B, int k)
{
    double *C = new double[n];
    int riga = 0, colonna = 0;
    double rapporto = 0.0;

    for (int i = 0; i < n; i++)
    {
        riga = 0, colonna = 0, rapporto = 0.0;

        for (int j = 0; j < m; j++)
        {
            riga += A[i][j];
        }

        for (int j = 0; j < k; j++)
        {
            colonna += B[j][i];
        }

        rapporto = (double)riga / colonna;

        C[i] = rapporto;
    }

    return C;
}

void print_dynamic(int **x, int rows, int cols)
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

void print_array(double *x, int cols)
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

    int **a = new int *[5];
    int **b = new int *[5];

    for (int i = 0; i < 5; i++)
    {
        a[i] = new int[5];
        b[i] = new int[5];

        for (int j = 0; j < 5; j++)
        {
            a[i][j] = rand() % 9 + 1;
            b[i][j] = rand() % 9 + 1;
        }
    }

    cout << "\n\n************ MATRICE 1*****************\n\n";
    print_dynamic(a, 5, 5);

    cout << "\n\n************ MATRICE 2*****************\n\n";
    print_dynamic(b, 5, 5);

    cout << "\n\n************ ARRAY RISULTANTE *****************\n\n";

    double *result = func(a, 5, 5, b, 5);
    print_array(result, 5); // Numero di elementi delle colonne compresi tra 2 e 3
}