/*12.Scrivere un metodo che prenda come parametri 
formali una matrice A di stringhe ed uno short w, e 
restituisca in output un bool che indichi se esiste una 
riga di A in cui siano presenti almeno due stringhe 
consecutive in cui i primi w caratteri della prima 
stringa siano uguali agli ultimi w caratteri della 
seconda stringa (nello stesso ordine).*/

#include <iostream>
using namespace std;

bool func(string **A, int rows, int cols, short w)
{
    for (int r = 0; r < rows; r++)
    {
        for (int c = 0; c < cols - 1; c++)
        {
            if (A[r][c].substr(0, w) == A[r][c + 1].substr(A[r][c + 1].length() - w, w))
            {
                return true;
            }
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

    string parole[9] = {"nepal", "Cane", "Albero", "Rossi", "Gelato", "Limone", "Sale", "Olio", "Pelato"};
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

    print_strmat(matrice, 3, 3);
    cout << "Risultato: " << func(matrice, 3, 3, 2); //(ne)pal === ca(ne)
}