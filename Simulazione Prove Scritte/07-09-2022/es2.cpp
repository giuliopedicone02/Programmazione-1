#include <iostream>
#include <cmath>
using namespace std;

int es2(string **A, int n, int &m)
{
    int cont = 0, res = 0;

    string a = *A[0];
    string b = *A[1];

    double avg = 0.0;

    for (int c = 1; c < n - 1; c++)
    {
        avg += a.length();
        avg += b.length();

        if (a.length() == b.length())
        {
            cont = 0;

            for (int i = 0; i < a.length() - 2; i += 2) // a pari
            {
                for (int j = 1; j < b.length() - 2; j += 2) // b dispari
                {
                    if (a[i] == b[j])
                    {
                        cont++;
                    }
                }
            }

            if (cont >= m)
            {
                res++;
            }
        }

        a = *A[c];
        b = *A[c + 1];
    }

    m = round(avg / n);

    return res;
}

void print_strmat(string **S, int cols)
{
    cout << "Array = [ ";

    for (int c = 0; c < cols; c++)
    {
        cout << *S[c] << " ";
    }

    cout << "]";
}

int main()
{
    string **array = new string *[12];

    string parole[12] = {"Anna", "Giorgio", "Albero", "Rossi", "Olio", "Limone", "Sale", "Olio", "Pelato", "Giallo", "Verde", "Blu"};

    for (int c = 0; c < 12; c++)
    {
        array[c] = new string(parole[c]);
    }

    print_strmat(array, 12);
    int es = 4; // Modificare il valore con 1 per ottenere un risultato
    cout << "\nNumero di coppie ordinate: " << es2(array, 12, es) << endl;
    cout << "m: " << es;
}