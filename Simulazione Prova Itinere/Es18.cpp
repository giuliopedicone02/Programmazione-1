/*18.Scrivere un metodo che prenda in input una 
matrice di puntatori a stringhe M e due numeri short 
senza segno, k ed s, e restituisca il numero di colonne 
contenenti almeno k stringhe con un numero di lettere 
vocali minore di s.*/
#include <iostream>
using namespace std;

int func(string ***M, int rows, int cols, unsigned short k, unsigned short s)
{
    int counter = 0;
    int ris = 0;

    for (int c = 0; c < cols; c++)
    {
        counter = 0;

        for (int r = 0; r < rows; r++)
        {
            string s1 = *M[r][c];
            string s2 = "";

            for (int c = 0; c < s1.length(); c++) //Ricerca vocali
            {
                if (s1[c] == 65 || s1[c] == 97 || s1[c] == 69 || s1[c] == 101 || s1[c] == 73 || s1[c] == 105 || s1[c] == 79 || s1[c] == 111 || s1[c] == 85 || s1[c] == 117)
                {
                    s2 += s1[c];
                }
            }

            if (s2.length() < s)
            {
                counter++;
            }
        }

        if (counter >= k)
        {
            ris++;
        }
    }

    return ris;
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

    string parole[9] = {"Nepal", "Work", "Albero", "Rossi", "Job", "Limone", "Sale", "Xeno", "Pelato"};
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

    cout << "\n\n************ MATRICE *****************\n\n";

    print_strmat(matrice, 3, 3);

    cout << "Risultato: " << func(matrice, 3, 3, 2, 3); //Numero di colonne contenenti almeno 2 stringhe con meno di 3 vocali
}