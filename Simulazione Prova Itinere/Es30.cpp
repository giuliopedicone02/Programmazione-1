/*30.Scrivere un metodo che prenda in input una 
matrice di stringhe A e due numeri short senza segno, 
k ed s, e restituisca il valore booleano true se esiste 
almeno una riga di A contenente almeno k stringhe 
ognuna contenente un numero di lettere maiuscole 
minore di s.*/
#include <iostream>
using namespace std;

bool func(string **A, int rows, int cols, unsigned short k, unsigned short s)
{
    int counter = 0;
    for (int r = 0; r < rows; r++)
    {
        for (int c = 0; c < cols; c++)
        {
            string s1 = A[r][c];
            string s2 = "";
            for (int k = 0; k < s1.length(); k++)
            {
                if (isupper(s1[k])) //Troviamo le lettere maiuscole
                {
                    s2 += s1[k];
                }

                if (s2.length() < s)
                {
                    counter++;
                }
            }
        }

        if (counter >= k)
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

    cout << "Risultato: " << func(matrice, 3, 3, 2, 2); //Cambiare l'ultimo parametro da 1 a 2 per verificare il corretto funzionamento
}