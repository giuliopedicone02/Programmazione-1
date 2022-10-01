/*11.Scrivere un metodo che prenda come parametri 
formali una matrice quadrata A n×n di puntatori ad int 
e restituisca in output un bool che indichi se la somma 
degli elementi puntati dalla diagonale sottostante la 
diagonale secondaria è divisibile per n.*/
#include <iostream>
#include <stdlib.h>
#include <math.h>
using namespace std;

bool func(int ***A, int rows, int cols)
{
    int row = 0;
    int col = cols - 1;
    int somma = 0;

    while (col > 0) //Calcolo diagonale secondaria
    {
        somma += *A[row + 1][col];
        row++;
        col--;
    }

    if (somma % rows == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
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

    int ***d = new int **[5]; //Creiamo una matrice di puntatori ad interi 5x5
    for (int i = 0; i < 5; i++)
    {
        d[i] = new int *[5];
        for (int j = 0; j < 5; j++)
        {
            d[i][j] = new int(rand() % 9 + 1);
        }
    }

    print_dynamic(d, 5, 5);
    cout << "Risultato: " << func(d, 5, 5);
}