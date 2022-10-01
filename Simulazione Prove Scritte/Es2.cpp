/*[Esercizio 2] Scrivere un metodo che prenda in input un parametro formale matrice M di dimensioni n × m di puntatori
a stringhe, e che restituisca true se esiste almeno una colonna in M che abbia un egual numero di stringhe palindrome di una
delle righe di M.*/
#include <iostream>
#include <string.h>
using namespace std;

bool func(string ***M, int n, int m)
{
    string s1 = "", s2 = "", s3 = "", s4 = "";
    int count1 = 0, count2 = 0;
    int arr1[m], arr2[n];

    for (int i = 0; i < m; i++) // Colonne
    {
        count1 = 0;
        for (int j = 0; j < n; j++)
        {
            s1 = *M[j][i];
            s2 = "";

            for (int k = s1.length() - 1; k >= 0; k--)
            {
                s2 += s1[k];
            }

            if (s1 == s2)
            {
                count1++;
            }
        }

        arr1[i] = count1;
    }

    for (int i = 0; i < n; i++) // Righe
    {
        count2 = 0;
        for (int j = 0; j < m; j++)
        {
            s3 = *M[i][j];
            s4 = "";

            for (int k = s3.length() - 1; k >= 0; k--)
            {
                s4 += s3[k];
            }

            if (s3 == s4)
            {
                count2++;
            }
        }

        arr2[i] = count2;
    }

    for (int c = 0; c < m; c++)
    {
        for (int i = 0; i < n; i++)
        {

            if (arr1[c] == arr2[i] && arr1[c] != 0 && arr2[i] != 0)
            {
                return true;
            }
        }
    }

    return false;
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

    string parole[12] = {"anna", "Giorgio", "Albero", "Rossi", "Olio", "Limone", "Sale", "Olio", "Pelato", "Giallo", "Verde", "Blu"};
    int i = 0;

    for (int r = 0; r < 3; r++)
    {
        matrice[r] = new string *[4];
        for (int c = 0; c < 4; c++)
        {
            matrice[r][c] = new string(parole[i]);
            i++;
        }
    }

    print_strmat(matrice, 3, 4);
    cout << "Risultato: " << func(matrice, 3, 4);
}