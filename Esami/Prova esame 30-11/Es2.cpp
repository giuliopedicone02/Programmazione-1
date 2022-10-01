#include <iostream>
#include <string.h>
using namespace std;

string func(string **A, int rows, int cols)
{
    string result = "", s1 = "", s2 = "";
    int length = 0;
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            s1 = A[i][j];
            s2 = A[j % rows][i % cols];

            length = s1.length() - s2.length();

            if (length >= i + j)
            {
                for (int c = 0; c < s1.length(); c++)
                {
                    if (s1[c] == 'a' || s1[c] == 'e' || s1[c] == 'i' || s1[c] == 'o' || s1[c] == 'u' || s1[c] == 'A' || s1[c] == 'E' || s1[c] == 'I' || s1[c] == 'O' || s1[c] == 'U')
                    {
                        result += s1[c];
                    }
                }
            }
        }
    }

    return result;
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

    cout << "Risultato: " << func(matrice, 3, 3);
}