/*
4.Scrivere un metodo che prenda in input una matrice
di puntatori a stringhe P di dimensioni nm, due short a
e b, ed una stringa s. Il metodo restituisca il valore
booleano true se esiste almeno una colonna in P tale
che la stringa s sia sottostringa di un numero
compreso tra a e b (inclusi) di stringhe della colonna
stessa. PS: Si assuma 0 < a b < n
*/

#include <iostream>
#include <cstring>
#include <iomanip>
using namespace std;

int func(string ***P, int rows, int cols, short a, short b, string s)
{
    int res = 0;
    for (int c = 0; c < cols; c++)
    {
        for (int r = 0; r < rows; r++)
        {
            string s1 = *P[r][c];

            if (s1.find(s) != string::npos)
            {
                res++;
            }
        }
    }

    if (res >= a && res <= b)
    {
        return res;
    }
    else
    {
        return -1;
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

    string parole[9] = {"Giorgio", "Albero", "Gatto", "Cane", "Gelato", "Limone", "Sale", "Olio", "Pepe"};
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
    cout << "Numero di stringhe che contengono org comprese tra 1 e 2: " << func(matrice, 3, 3, 1, 2, "org");
}