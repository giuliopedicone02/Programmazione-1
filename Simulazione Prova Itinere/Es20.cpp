/*20.Scrivere un metodo che prenda in input una 
matrice di puntatori a stringhe S di dimensione nm, 
una stringa s1 ed uno short k, e restituisca la 
percentuale di stringhe, tra quelle presenti nelle prime 
k colonne di S, che siano piu lunghe di s1. NB: si 
assuma k<=m.*/

#include <iostream>
#include <iomanip>
using namespace std;

float func(string ***S, int rows, int cols, string s1, short k)
{
    int counter = 0;

    //counter : rows*k = x : 100
    //x = counter * 100 / rows*k

    for (int c = 0; c < k; c++) //[...] nelle prime k colonne...
    {
        for (int r = 0; r < rows; r++)
        {
            string s = *S[r][c];
            if (s.length() > s1.length())
            {
                counter++;
            }
        }
    }
    cout << fixed << setprecision(2);
    return (float)(counter * 100) / (rows * k);
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

    string parole[9] = {"Nepal", "Sole", "Albero", "Rossi", "Verde", "Limone", "Sale", "Olio", "Pelato"};
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

    cout << "Risultato: " << func(matrice, 3, 3, "City", 2) << "%" << endl;
}