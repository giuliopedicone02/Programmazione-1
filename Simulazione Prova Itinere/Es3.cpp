/*3.Scrivere un metodo che prenda in input un 
parametro formale matrice quadrata Q di interi ed un 
double w, e restituisca un valore booleano true se 
esiste almeno una colonna della matrice Q tale che il 
rapporto tra la somma degli elementi della colonna 
stessa e la somma degli elementi della diagonale 
secondaria di Q sia maggiore di w.*/

#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

bool func(int **Q, int rows, int cols, double w)
{
    int somma = 0;
    int diagonale = 0;

    int row = 0;
    int col = cols - 1;

    while (col >= 0) //Calcolo diagonale secondaria
    {
        diagonale += Q[row][col];
        row++;
        col--;
    }

    for (int c = 0; c < cols; c++)
    {
        somma = 0;
        for (int r = 0; r < rows; r++)
        {
            somma += Q[r][c];
        }

        if (somma / diagonale > w)
        {
            return 1;
        }
    }

    return 0;
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
    cout << func(d, 5, 5, 0.3);
}