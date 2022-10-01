/*14.Scrivere un metodo che prenda come parametri 
formali una matrice A di stringhe ed un intero k, e 
restituisca in output una copia di A in cui tutte le 
stringhe della colonna k-esima siano state epurate 
dalle lettere non italiane.*/
#include <iostream>
#include <string>
using namespace std;

string clear(string s1)
{
    string result = s1;

    for (int c = 0; c < s1.length(); c++)
    {
        //J,K,j,k,W,X,Y,w,x,y in ASCII
        if (result[c] == 74 || result[c] == 75 || result[c] == 106 || result[c] == 107 || result[c] == 87 || result[c] == 88 || result[c] == 89 || result[c] == 119 || result[c] == 120 || result[c] == 121)
        {
            result = s1.erase(c, 1); //Posizione della lettera da rimuovere, numero di caratteri da rimuovere
        }
    }
    return result;
}
string **func(string **A, int rows, int cols, int k)
{
    string **result = new string *[rows];

    for (int r = 0; r < rows; r++) //creo una copia di A
    {
        result[r] = new string[cols];
        for (int c = 0; c < cols; c++)
        {
            result[r][c] = A[r][c];
        }
    }

    for (int r = 0; r < rows; r++)
    {
        result[r][k] = clear(result[r][k]);
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

    string parole[9] = {"Nepal", "Work", "Albero", "Rossi", "Job", "Limone", "Sale", "Xeno", "Pelato"};
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

    cout << "\n\n************ MATRICE INIZIALE *****************\n\n";

    print_strmat(matrice, 3, 3);

    cout << "\n\n************ MATRICE FINALE *****************\n\n";

    string **result = func(matrice, 3, 3, 1);
    print_strmat(result, 3, 3);
}