/*19.Scrivere un metodo che prenda in input una 
matrice quadrata M di short e restituisca il valore 
booleano true se M e una matrice triangolare inferiore 
o superiore.*/
#include <iostream>
using namespace std;

/*
Ragionamento utilizzato:
Una matrice si dice triangolare inferiore se il numero di zeri è uguale all'indice della riga.
Es: nella riga 0 non devono esserci zeri, nella riga 1 uno zero all'inizio, nella riga 2 due zeri iniziali...

Per controllare se i valori controllati sono tutti 0, interrompo il ciclo for delle colonne al valore di r.
Un flag si occuperà di verificare eventuali valori diversi da 0 e ritornare o meno true.

Per controllare se una matrice è triangolare superiore controlliamo se il numero di zeri di una colonna è pari all'indice della stessa.
Es: nella colonna 0 non devono esserci zeri, nella colonna 1 uno zero all'inizio...

Verifichiamo eventuali valori diversi da zero e restituiamo false. True altrimenti.
*/
bool func(short **M, int rows, int cols)
{
    bool fl = true;

    for (int r = 0; r < rows; r++) //Ricerca matrice triangolare inferiore
    {
        for (int c = 0; c < r; c++)
        {
            if (M[r][c] != 0)
            {
                fl = false;
            }
        }
    }

    if (fl)
    {
        return true;
    }
    else
    {
        for (int c = 0; c < cols; c++) //Ricerca matrice triangolare superiore
        {
            for (int r = 0; r < c; r++)
            {
                if (M[r][c] != 0)
                {
                    return false;
                }
            }
        }

        return true;
    }

    return false;
}

void print_dynamic(short **x, int rows, int cols)
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
    short mat[16] = {1, 0, 0, 0, 1, 1, 0, 0, 1, 1, 1, 0, 1, 1, 1, 1};
    short **a = new short *[4];
    int c = 0;

    for (int i = 0; i < 4; i++)
    {
        a[i] = new short[4];

        for (int j = 0; j < 4; j++)
        {
            a[i][j] = mat[c];
            c++;
        }
    }

    cout << "\n\n************ MATRICE *****************\n\n";
    print_dynamic(a, 4, 4);

    cout << "Risultato: " << func(a, 4, 4);
}