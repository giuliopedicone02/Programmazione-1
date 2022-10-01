/*34.Scrivere un metodo che prenda in input una
matrice di puntatori a stringhe S di dimensioni n×m,
una stringa x ed un array di double W di dimensione
m; il metodo restituisca un array di bool R di
dimensione m tale che l’i-esimo elemento di R sarà
true se e solo se il rapporto tra il numero di stringhe
della i-esima colonna di S delle quali x è sottostringa
ed il numero n è minore o uguale dello i-esimo
elemento di W. NB: Si presti attenzione alle stringhe
mancanti!*/
#include <iostream>
#include <time.h>
#include <stdlib.h>
#include <string>

using namespace std;

bool *func(string ***S, int n, int m, string x, double *W)
{
    bool *R = new bool[m];
    int counter = 0;

    for (int i = 0; i < m; i++)
    {
        counter = 0;

        for (int j = 0; j < n; j++)
        {
            string s1 = *S[i][j];

            if (s1.find(x) != string::npos)
            {
                counter++;
            }
        }

        if (counter / n <= W[i])
        {
            R[i] = true;
        }
        else
        {
            R[i] = false;
        }
    }

    return R;
}

void print_strmat(string ***S, int rows, int cols)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            cout << '\t' << *S[i][j];
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

void print_array(double *x, int dim)
{
    for (int c = 0; c < dim; c++)
    {
        cout << x[c] << "    ";
    }
}

int main()
{

    srand(time(NULL));

    string ***matrice = new string **[3];
    double *array = new double[3];
    bool *result = new bool[3];

    string parole[9] = {"Nepal", "Latte", "Cane", "Rossi", "Job", "Limone", "Sale", "Xeno", "Pelato"};
    int i = 0;

    for (int r = 0; r < 3; r++)
    {
        matrice[r] = new string *[3];
        for (int c = 0; c < 3; c++)
        {
            matrice[r][c] = new string(parole[i]);
            i++;
        }
    }

    for (int j = 0; j < 5; j++)
    {
        array[j] = rand() % 9 + 1;
    }

    cout << "\n\n************ MATRICE *****************\n\n";

    print_strmat(matrice, 3, 3);

    cout << "\n\n************ ARRAY *****************\n\n";

    print_array(array, 3);

    result = func(matrice, 3, 3, "la", array);

    cout << "\n\n************ RISULTATO *****************\n\n";

    print_array(result, 3);
}