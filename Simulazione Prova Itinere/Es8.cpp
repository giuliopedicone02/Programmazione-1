/*
8.Scrivere un metodo che prenda in input una matrice 
quadrata di puntatori a stringhe Q ed una stringa s. Il 
metodo restituisca il valore booleano true se e solo se 
il numero di stringhe che contengono s, presenti nella 
diagonale principale di Q, e maggiore del numero di 
stringhe che contengono s presenti nella diagonale 
secondaria di Q. */

#include <iostream>
#include <cstring>
using namespace std;

bool func(string ***S, int rows, int cols, string s)
{
    int diagP = 0;
    int diagS = 0;

    for (int c = 0; c < rows; c++)
    {
        string s1 = *S[c][c];

        if (s1.find(s) != string::npos)
        {
            diagP++;
        }
    }

    int row = 0;
    int col = cols - 1;

    while (col >= 0) //Calcolo diagonale secondaria
    {
        string s1 = *S[row][col];

        if (s1.find(s) != string::npos)
        {
            diagS++;
        }

        row++;
        col--;
    }

    if (diagP > diagS)
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

    string parole[9] = {"Giorgio", "Albero", "Gatto", "Cane", "Gelato", "Limone", "Sale", "Olio", "Pelato"};
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

    print_strmat(matrice, 3, 3);
    cout << "Risultato : " << func(matrice, 3, 3, "ela");
}