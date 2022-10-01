#include <iostream>
#include <cmath>
using namespace std;

int es2(string **A, int n, int &m)
{
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

    cout << "\nNumero di coppie ordinate: " << es2(array, 12, es) << endl;
}