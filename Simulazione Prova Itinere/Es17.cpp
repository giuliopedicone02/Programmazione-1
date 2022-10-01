/*17.Scrivere un metodo che prenda in input una 
matrice A di numeri interi e due double w e v, e 
restituisca il valore booleano true se esiste almeno una 
colonna di A in cui la media dei suoi elementi e 
compresa tra w e v. NB: Si assuma che w <=v. */
#include <iostream>
using namespace std;

bool func(int **A, int rows, int cols, double w, double v)
{
    int sum = 0;
    float med = 0;

    for (int c = 0; c < cols; c++)
    {
        sum = 0;
        for (int r = 0; r < rows; r++)
        {
            sum += A[r][c];
        }

        med = (float)sum / cols;

        if (med >= w && med <= v)
        {
            cout << "Valore media: " << med << endl;
            return true;
        }
    }

    return false;
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

int main()
{
    srand(time(NULL));

    int **a = new int *[5];

    for (int i = 0; i < 5; i++)
    {
        a[i] = new int[5];

        for (int j = 0; j < 5; j++)
        {
            a[i][j] = rand() % 9 + 1;
        }
    }

    cout << "\n\n************ MATRICE *****************\n\n";
    print_dynamic(a, 5, 5);

    cout << "Risultato: " << func(a, 5, 5, 2.0, 3.0);
}