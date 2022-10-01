/*[Esercizio 1] Scrivere un metodo che prenda in input un parametro formale array A di interi di dimensione k × n × n
ed un double w, e restituisca il valore di verit`a true se esiste un valore dell’indice relativo alla prima dimensione (k) tale che,
nella corrispondente matrice quadrata di dimensioni n × n, la media tra il valore minimo ed il valore massimo della diagonale
principale sia minore o uguale a w.
*/

#include <iostream>
using namespace std;

bool func(int ***A, int k, int n, double w)
{
    int min = A[0][0][0];
    int max = A[0][0][0];
    double med = 0.0;
    for (int i = 0; i < k; i++)
    {
        min = A[i][0][0];
        max = A[i][0][0];

        for (int j = 0; j < n; j++)
        {
            if (A[i][j][j] > max)
            {
                max = A[i][j][j];
            }

            if (A[i][j][j] < min)
            {
                min = A[i][j][j];
            }
        }

        med = (double)min + max / 2.0;

        if (med <= w)
        {
            return true;
        }
    }

    return false;
}

void print_dynamic(int ***x, int face, int rows, int cols)
{

    for (int r = 0; r < face; r++)
    {
        cout << endl
             << "Faccia " << r + 1 << "             " << endl;

        for (int c = 0; c < rows; c++)
        {
            cout << endl;
            for (int i = 0; i < cols; i++)
            {
                cout << x[r][c][i] << "    ";
            }
        }

        cout << endl;
    }
}

int main()
{
    srand(time(NULL));

    int ***d = new int **[6]; // Creiamo una matrice 6x5x5
    for (int i = 0; i < 6; i++)
    {
        d[i] = new int *[5];
        for (int j = 0; j < 5; j++)
        {
            d[i][j] = new int[5];
            for (int k = 0; k < 5; k++)
            {
                d[i][j][k] = rand() % 9 + 1;
            }
        }
    }

    print_dynamic(d, 6, 5, 5);
    cout << "Risultato: " << func(d, 6, 5, 4);
}