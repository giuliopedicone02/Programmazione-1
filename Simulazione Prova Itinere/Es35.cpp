/*35.Scrivere un metodo che prenda in input una
matrice Q di puntatori a int di dimensione n × m e due
float a e b e restituisca un array di float di dimensione
m tale che lo i-esimo elemento dello array contiene la
media dei soli elementi della colonna i-esima compresi
tra a e b (estremi inclusi). Nel confronto tra interi e
numeri in virgola mobile si consideri l’arrotondamento
di questi ultimi al numero intero più prossimo ad essi.
NB: Si presti attenzione ai numeri mancanti!*/
#include <iostream>
#include <math.h>
using namespace std;

float *func(int ***Q, int n, int m, float a, float b)
{
    float *result = new float[m];
    int somma = 0;

    for (int i = 0; i < m; i++)
    {
        somma = 0;
        for (int j = 0; j < n; j++)
        {
            if (j >= round(a) && j >= round(b))
            {
                somma += *Q[i][j];
            }
        }

        result[i] = (float)somma / (b - a);
    }

    return result;
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

void print_array(float *x, int dim)
{
    for (int c = 0; c < dim; c++)
    {
        cout << x[c] << "    ";
    }
}

int main()
{
    srand(time(NULL));

    float *result = new float[5];

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

    result = func(a, 5, 5, 2, 4);

    cout << "\n\n************ ARRAY *****************\n\n";
    print_array(result, 5);
}