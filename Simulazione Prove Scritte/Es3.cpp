/*[Esercizio 3] Scrivere un metodo che prenda in input tre parametri formali: una matrice di stringhe S di dimensioni n×m,
un array di caratteri C che contiene elementi distinti, ed un float w. Il metodo restituisca true se esiste almeno una riga o una
colonna della matrice tale che la percentuale di caratteri di C presenti in essa `e maggiore di w.*/

#include <iostream>
using namespace std;

bool func(string **S, int n, int m, char *C, int d, double w)
{
    int counter = 0;
    double percentage = 0.0;

    for (int i = 0; i < n; i++) // Righe
    {
        counter = 0;
        percentage = 0.0;

        for (int j = 0; j < m; j++)
        {
            string s1 = S[i][j];

            for (int k = 0; k < s1.length() - 1; k++)
            {
                for (int c = 0; c < d; c++)
                {
                    if (C[c] == s1[k])
                    {
                        counter++;
                    }
                }
            }
        }

        // counter:d=x:100   x=counter*100/d
        percentage = (double)(counter * 100) / d;
        if (percentage > w)
        {
            return true;
        }
    }

    for (int i = 0; i < m; i++) // Colonne
    {
        counter = 0;
        percentage = 0.0;

        for (int j = 0; j < n; j++)
        {
            string s1 = S[j][i];

            for (int k = 0; k < s1.length() - 1; k++)
            {
                for (int c = 0; c < d; c++)
                {
                    if (C[c] == s1[k])
                    {
                        counter++;
                    }
                }
            }
        }

        // counter:d=x:100   x=counter*100/d
        percentage = (double)(counter * 100) / d;
        if (percentage > w)
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
    char *array = new char[5];
    string parole[12] = {"Nepal", "Cane", "Albero", "Rossi", "Gelato", "Limone", "Sale", "Olio", "Pelato", "Giallo", "Verde", "Blu"};
    char vocali[12] = {'a', 'e', 'i', 'o', 'u'};

    int i = 0;

    for (int r = 0; r < 3; r++)
    {
        matrice[r] = new string[4];
        for (int c = 0; c < 4; c++)
        {
            matrice[r][c] = parole[i];
            i++;
        }
    }

    for (int i = 0; i < 5; i++)
    {
        array[i] = vocali[i];
    }

    print_strmat(matrice, 3, 4);
    cout << "Risultato: " << func(matrice, 3, 4, array, 5, 20);
}
