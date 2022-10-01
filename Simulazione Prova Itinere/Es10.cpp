/*10.Scrivere un metodo che prenda in input tre 
parametri formali: una matrice di puntatori a stringhe 
A di dimensioni nxm, uno short k ed una stringa s. Il 
metodo restituisca un array di bool di dimensione n in 
cui il singolo elemento di indice i assume valore true se 
la stringa s e sottostringa di almeno k stringhe della 
riga i-esima della matrice A.*/
#include <iostream>
#include <string>
using namespace std;

bool *func(string ***A, int rows, int cols, short k, string s)
{
    bool *res = new bool[rows];
    int cont = 0;
    for (int r = 0; r < rows; r++)
    {
        cont = 0;
        int i = 0;
        for (int c = 0; c < cols; c++)
        {
            string s1 = *A[r][c];

            if (s1.find(s) != string::npos)
            {
                cont++;
            }
        }

        if (cont >= k)
        {
            res[i] = true;
            cout << res[i] << endl;
        }
        else
        {
            res[i] = false;
            cout << res[i] << endl;
        }

        i++;
    }

    return res;
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
    bool *q = func(matrice, 3, 3, 2, "ela");
}