/*16.Due stringhe si dicono c-equivalenti se esse 
risultano uguali dopo aver eliminato da ambedue tutte 
le occorrenze del carattere c. Scrivere un metodo che 
prenda in input una matrice A di puntatori a stringhe 
ed un carattere c, e restituisca un boolean che indichi 
se esistono in A due stringhe c-equivalenti.*/
#include <iostream>
using namespace std;

string clear(string s1, char c)
{
    string result = s1;

    for (int i = 0; i < result.length(); i++)
    {
        if (result[i] == c)
        {
            result = s1.erase(i, 1);
        }
    }

    return result;
}

string **func(string ***A, int rows, int cols, char ch)
{
    string **result = new string *[rows];

    for (int r = 0; r < rows; r++)
    {
        result[r] = new string[cols];
        for (int c = 0; c < cols; c++)
        {
            result[r][c] = clear(*A[r][c], ch);
        }
    }

    return result;
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

void print_strmat2(string **S, int rows, int cols)
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

bool result(string **A, int rows, int cols)
{
    string s1 = "";
    for (int r = 0; r < rows; r++)
    {
        for (int c = 0; c < cols; c++)
        {
            s1 = A[r][c];

            for (int j = 0; j < rows; j++)
            {
                for (int k = 0; k < cols; k++)
                {
                    if (s1 == A[j][k] && j != r && k != c)
                    {
                        return true;
                    }
                }
            }
        }
    }

    return false;
}

int main()
{
    string ***matrice = new string **[3];

    string parole[9] = {"Nepal", "Cane", "Albero", "Rossi", "Gelato", "Canea", "Sale", "Olio", "Pelato"};
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

    cout << "\n\n************ MATRICE INIZIALE *****************\n\n";

    print_strmat(matrice, 3, 3);

    cout << "\n\n************ MATRICE FINALE *****************\n\n";

    string **risultato = func(matrice, 3, 3, 'a');
    print_strmat2(risultato, 3, 3);

    cout << "Risultato: " << result(risultato, 3, 3); //Cane == Canea
}