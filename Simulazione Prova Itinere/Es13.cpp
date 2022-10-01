/*13.Scrivere un metodo che prenda come parametri 
formali una matrice quadrata A n×n di puntatori a char 
e restituisca in output un bool che indichi se esiste una 
colonna in A identica alla diagonale principale di A.*/

#include <iostream>
using namespace std;

bool func(char ***A, int rows, int cols)
{
    char array[rows];
    int counter = 0;

    for (int c = 0; c < rows; c++) //Diagonale Principale
    {
        array[c] = *A[c][c];
    }

    for (int c = 0; c < cols; c++)
    {
        counter = 0;

        for (int r = 0; r < rows; r++)
        {
            if (*A[r][c] == array[r])
            {
                counter++;
            }
        }

        if (counter == rows)
        {
            return true;
        }
    }

    return false;
}

void print_strmat(char ***S, int rows, int cols)
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
int main()
{
    char ***matrice = new char **[3];

    char lettere[9] = {'a', 'b', 'c', 'e', 'e', 'f', 'i', 'h', 'i'};
    int i = 0;

    for (int r = 0; r < 3; r++)
    {
        matrice[r] = new char *[3];
        for (int c = 0; c < 3; c++)
        {
            matrice[r][c] = new char(lettere[i]);
            i++;
        }
    }

    print_strmat(matrice, 3, 3);
    cout << "Risultato: " << func(matrice, 3, 3);
}