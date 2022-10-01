/*Scrivere un metodo in linguaggio C++ che prenda in input una matrice quadrata S di dimensioni n × n di puntatori a interi
senza segno, un double w ed uno short k (si assuma k < n). Il metodo restituisca il valore booleano true se esistono almeno k
colonne in S che soddisfano il seguente requisito: la media aritmetica degli elementi della colonna stessa sia minore o uguale a
w. NB: si presti attenzione ai numeri mancanti..*/
#include <iostream>
using namespace std;

bool func(unsigned int ***S, int rows, int cols, double w, short k)
{
    int somma = 0, counter = 0;
    for (int i = 0; i < cols; i++)
    {
        somma = 0;
        for (int j = 0; j < rows; j++)
        {
            somma += *S[i][j];
        }

        if (somma / rows <= w)
        {
            counter++;
        }
    }

    if (counter >= k)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void print_dynamic(unsigned int ***x, int rows, int cols)
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

    unsigned int ***d = new unsigned int **[5]; // Creiamo una matrice 5x5
    for (int i = 0; i < 5; i++)
    {
        d[i] = new unsigned int *[5];
        for (int j = 0; j < 5; j++)
        {
            d[i][j] = new unsigned int(rand() % 9 + 1);
        }
    }

    cout << "\n\n************ MATRICE ******************\n\n";

    print_dynamic(d, 5, 5);

    cout << "Risultato: " << func(d, 5, 5, 3, 3);
}