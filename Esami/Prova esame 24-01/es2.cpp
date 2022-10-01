#include <iostream>
#include <string>
using namespace std;
int func(string ***A, int n, int m, short k, short r, short s)
{
    int cont = 0, res = 0;
    string pal = "", temp = "";

    for (int j = 0; j < m; j++)
    {
        cont = 0;
        for (int i = 0; i < n; i++)
        {
            if (A[i][j])
            {
                temp = *A[i][j];
                pal = "";
                if (temp.length() <= s && temp.length() >= r)
                {
                    for (int c = temp.length() - 1; c >= 0; c--)
                    {
                        pal += temp[c];
                    }

                    if (temp == pal)
                    {
                        cont++;
                    }
                }
            }
        }
        if (cont >= k)
        {
            res++;
        }
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

    string parole[9] = {"anna", "Albero", "Gatto", "anna", "Gelato", "Limone", "anna", "Olio", "Pelato"};
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
    cout << func(matrice, 3, 3, 2, 2, 6);
}