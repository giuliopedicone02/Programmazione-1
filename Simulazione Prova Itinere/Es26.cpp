/*26.Scrivere un metodo che prenda in input una 
matrice quadrata Q di dimensioni n x n di puntatori a 
stringhe e due short m e k e restituisca il valore 
booleano true se la diagonale secondaria di Q contiene 
almeno m stringhe con un numero di vocali minore o 
uguale a k. NB: Si assuma m<=n. */
#include <iostream>
using namespace std;

bool func(string ***Q, int rows, int cols, short m, short k)
{
    int row = 0;
    int col = cols - 1;
    int counter = 0;

    do //Ricerca stringhe diagonale secondaria
    {
        string s1 = *Q[row][col];
        string s2 = "";

        for (int c = 0; c < s1.length(); c++) //Ricerca vocali
        {
            if (s1[c] == 'a' || s1[c] == 'e' || s1[c] == 'i' || s1[c] == 'o' || s1[c] == 'u' || s1[c] == 'A' || s1[c] == 'E' || s1[c] == 'I' || s1[c] == 'O' || s1[c] == 'U')
            {
                s2 += s1[c];
            }
        }

        if (s2.length() <= k)
        {
            counter++;
        }

        row++;
        col--;
        /* code */
    } while (col >= 0);

    if (counter >= m)
    {
        return true;
    }
    else
    {
        return false;
    }
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

int main()
{
    string ***matrice = new string **[3];

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

    cout << "\n\n************ MATRICE *****************\n\n";

    print_strmat(matrice, 3, 3);

    cout << "Risultato: " << func(matrice, 3, 3, 1, 2);
}