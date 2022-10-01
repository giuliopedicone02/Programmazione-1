/*9.Scrivere un metodo che prenda in input un 
parametro formale matrice A di interi di dimensioni 
nxn ed un double w, e restituisca un valore booleano 
true se esiste almeno una colonna della matrice A per 
cui il rapporto tra la somma degli elementi della 
colonna stessa e la somma degli elementi della 
diagonale principale di A sia maggiore di w. 
*/
#include <iostream>
using namespace std;

bool func(int **A, int rows, int cols, double w)
{
    int diagP = 0;
    int sum = 0;

    for (int c = 0; c < rows; c++)
    {
        diagP += A[c][c];
    }

    for (int c = 0; c < cols; c++)
    {
        sum = 0;

        for (int r = 0; r < rows; r++)
        {
            sum += A[r][c];
        }

        if (sum / diagP > w)
        {
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

    int **d = new int *[5]; //Creiamo una matrice 5x5
    for (int i = 0; i < 5; i++)
    {
        d[i] = new int[5];
        for (int j = 0; j < 5; j++)
        {
            d[i][j] = rand() % 9 + 1;
        }
    }

    print_dynamic(d, 5, 5);
    cout << "Risultato: " << func(d, 5, 5, 0.8);
}