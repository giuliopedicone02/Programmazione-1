/*32.Scrivere un metodo che prenda in input una
matrice quadrata di puntatori a stringhe e due caratteri
c1 e c2. Calcolare O1 come numero di occorrenze del
carattere c1 che figurano nella diagonale principale.
CalcolareO2 come numero di occorrenze del carattere
c2 che che figurano nella secondaria. Restituire il
rapportoO1/O2. NB: si faccia attenzione alle stringhe
mancante*/
#include <iostream>
#include <string.h>
using namespace std;

double func(string **A, int rows, int cols, char c1, char c2)
{
    int O1 = 0,
        O2 = 0;

    for (int c = 0; c < rows; c++)
    {
        string s1 = A[c][c];

        for (int i = 0; i < s1.length(); i++)
        {
            if (s1[i] == c1)
            {
                O1++;
            }
        }
    }

    int row = 0;
    int col = cols - 1;

    while (col >= 0)
    {
        string s1 = A[row][col];

        for (int i = 0; i < s1.length(); i++)
        {
            if (s1[i] == c2)
            {
                O2++;
            }
        }

        row++;
        col--;
    }

    return (double)O1 / O2;
}

void print_strmat(string **S, int rows, int cols)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            cout << '\t' << S[i][j];
        }
        cout << endl;
    }
}

int main()
{
    string **matrice = new string *[3];

    string parole[9] = {"Nepal", "Latte", "Cane", "Rossi", "Job", "Limone", "Sale", "Xeno", "Pelato"};
    int i = 0;

    for (int r = 0; r < 3; r++)
    {
        matrice[r] = new string[3];
        for (int c = 0; c < 3; c++)
        {
            matrice[r][c] = parole[i];
            i++;
        }
    }

    cout << "\n\n************ MATRICE *****************\n\n";

    print_strmat(matrice, 3, 3);

    cout << "Risultato: " << func(matrice, 3, 3, 'a', 'e');
}