/*24.Scrivere un metodo che prenda in input una 
matrice di stringhe S di dimensioni n m, uno short k, 
ed una stringa w. Il metodo restituisca il valore 
booleano true se esiste almeno una riga in P tale che 
la stringa w sia sottostringa di un numero di stringhe 
della riga stessa che sia minore o uguale a k.*/
#include <iostream>
using namespace std;

bool func(string **S, int rows, int cols, short k, string w)
{
    int counter;
    for (int r = 0; r < rows; r++)
    {
        for (int c = 0; c < cols; c++)
        {
            string s1 = S[r][c];

            if (s1.find(w) != string::npos)
            {
                counter++;
            }
        }

        if (counter <= k)
        {
            return true;
        }
    }

    return false;
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

    cout << "Risultato: " << func(matrice, 3, 3, 1, "a");
}