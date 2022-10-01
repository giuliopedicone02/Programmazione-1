/*15.Scrivere un metodo che prenda in input tre matrici 
A, B e C di boolean con le stesse dimensioni, e 
restituisca un boolean che indichi se una diagonale in 
A, soprastante la diagonale principale, è presente 
anche in B e C (nella stessa posizione e con la stessa 
sequenza di valori!).*/
#include <iostream>
using namespace std;

bool func(int **A, int **B, int **C, int rows, int cols)
{
    int counter = 0;
    for (int c = 1; c < cols; c++)
    {
        if (A[c - 1][c] == B[c - 1][c] && A[c - 1][c] == C[c - 1][c])
        {
            counter++;
        }
    }

    if (counter == cols - 1)
    {
        return true;
    }
    else
    {
        return false;
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

int main()
{
    srand(time(NULL));

    int **a = new int *[5]; //Creiamo tre matrici di interi 5x5
    int **b = new int *[5];
    int **c = new int *[5];
    for (int i = 0; i < 5; i++)
    {
        a[i] = new int[5];
        b[i] = new int[5];
        c[i] = new int[5];
        for (int j = 0; j < 5; j++)
        {
            a[i][j] = rand() % 9 + 1;
            b[i][j] = rand() % 9 + 1;
            c[i][j] = rand() % 9 + 1;
        }
    }

    cout << "\n\n************ MATRICE A *****************\n\n";
    print_dynamic(a, 5, 5);

    cout << "\n\n************ MATRICE B *****************\n\n";
    print_dynamic(b, 5, 5);

    cout << "\n\n************ MATRICE C *****************\n\n";
    print_dynamic(c, 5, 5);
    cout << "Risultato: " << func(a, b, c, 5, 5);
}