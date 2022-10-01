/*22.Scrivere un metodo che prenda in input una 
matrice quadrata Q di stringhe e restituisca il valore 
booleano true se la stringa piu lunga della diagonale 
principale di Q contiene un numero di vocali minore 
della stringa piu corta della diagonale stessa. NB: Si 
assuma che le stringhe della diagonale principale 
abbiano lunghezze differenti e sempre maggiori di 
zero.*/
#include <iostream>
using namespace std;

bool func(string **Q, int rows, int cols)
{
    string max = Q[0][0], min = Q[0][0];

    for (int c = 0; c < rows; c++)
    {
        if (Q[c][c] < min)
        {
            min = Q[c][c];
        }

        if (Q[c][c] > max)
        {
            max = Q[c][c];
        }
    }

    string s1 = "";
    string s2 = "";

    for (int c = 0; c < min.length(); c++)
    {
        if (min[c] == 65 || min[c] == 97 || min[c] == 69 || min[c] == 101 || min[c] == 73 || min[c] == 105 || min[c] == 79 || min[c] == 111 || min[c] == 85 || min[c] == 117)
        {
            s1 += min[c]; //Vocali stringa minore
        }
    }

    for (int c = 0; c < max.length(); c++)
    {
        if (max[c] == 65 || max[c] == 97 || max[c] == 69 || max[c] == 101 || max[c] == 73 || max[c] == 105 || max[c] == 79 || max[c] == 111 || max[c] == 85 || max[c] == 117)
        {
            s2 += max[c]; //Vocali stringa maggiore
        }
    }

    if (s1 > s2)
    {
        return true;
    }
    else
    {
        return false;
    }
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

    string parole[9] = {"Salvo", "Work", "Albero", "Rossi", "Unico", "Limone", "Sale", "Xeno", "Coltello"};
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

    cout << "Risultato: " << func(matrice, 3, 3);
}