/*31.Scrivere un metodo che prenda in input una
matrice M di puntatori a double di dimensione n × m e
due interi a e b e restituisca un array unidimensionale
di booleani di lunghezza 2m tale che l’elemento
dell’array di posizione 2i contiene True se e solo se la
media dei soli elementi della colonna i-esima di M
compresi tra a e b(estremi inclusi) è maggiore di
(a+b)/2. Gli elementi dell’array di indice dispari devono
essere inizializzati a False. NB: Si presti attenzione ai
numeri mancanti!*/
#include <iostream>
using namespace std;

bool *func(double ***M, int n, int m, int a, int b)
{
    bool *result = new bool[2 * m];
    double somma = 0;

    for (int c = 0; c < 2 * m; c++) // Inizializzazione posizione dispari a false
    {
        if (c % 2 != 0)
        {
            result[c] = false;
        }
    }

    for (int i = 0; i < m; i++)
    {
        somma = 0;

        for (int j = 0; j < n; j++)
        {
            if (j >= a && j <= b)
            {
                somma += *M[i][j];
            }
        }

        if ((somma / (b - a)) > ((a + b) / 2))
        {
            result[2 * i] = true;
        }
        else
        {
            result[2 * i] = false;
        }
    }

    return result;
}

void print_dynamic(double ***x, int rows, int cols)
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

void print_array(bool *x, int dim)
{
    for (int c = 0; c < dim; c++)
    {
        cout << x[c] << "    ";
    }
}

int main()
{
    srand(time(NULL));

    double ***a = new double **[5];
    bool *result = new bool[10];

    for (int i = 0; i < 5; i++)
    {
        a[i] = new double *[5];

        for (int j = 0; j < 5; j++)
        {
            a[i][j] = new double(rand() % 9 + 1);
        }
    }

    cout << "\n\n************ MATRICE *****************\n\n";
    print_dynamic(a, 5, 5);

    result = func(a, 5, 5, 2, 4);

    cout << "\n\n************ Array *****************\n\n";

    print_array(result, 10);
}