/*28.Scrivere un metodo che prenda come parametro 
formale un array A di stringhe (tutte di lunghezza 
dispari), e restituisca in output la massima lunghezza 
delle stringhe palindrome contenute al centro delle 
stringhe di A.*/
#include <iostream>
#include <string>
using namespace std;

int func(string *A, int dim)
{
    int result = 0;

    for (int c = 0; c < dim; c++)
    {
        string s1 = A[c];
        string s2 = "";
        bool palindrome = true;

        for (int j = s1.length() - 1; j >= 0; j--)
        {
            s2 += s1[j];
        }

        int p1 = 0;

        while (p1 < s1.length())
        {
            if (s1[p1] != s2[p1])
            {
                palindrome = false;
            }

            p1++;
        }

        if (palindrome && s1.length() > result)
        {
            result = s1.length();
        }
    }

    return result;
}

void print_strmat(string *S, int cols)
{
    for (int j = 0; j < cols; j++)
    {
        cout << '\t' << S[j];
    }

    cout << endl;
}

int main()
{
    string *array = new string[9];

    string parole[9] = {"Nepal", "Latte", "ANNA", "Rossi", "Job", "Lemon", "Ascensore", "Kitty", "Pen"};
    int i = 0;

    for (int c = 0; c < 9; c++)
    {
        array[c] = parole[i];
        i++;
    }

    cout << "\n\n************ ARRAY *****************\n\n";

    print_strmat(array, 9);

    cout << "Risultato: " << func(array, 9);
}