/*
6.Scrivere un metodo che prenda come parametro 
formale un cubo (array tridimensionale) C di stringhe, 
e restituisca in output una stringa contenente tutte le 
desinenze di due caratteri delle stringhe sulla faccia 
superiore del cubo C.
*/
#include <iostream>
using namespace std;

string func(string ***C, int rows, int cols, int prof)
{
    string result = "";

    for (int r = 0; r < rows; r++)
    {
        cout << endl
             << "Faccia " << r << endl
             << endl;

        for (int c = 0; c < cols; c++)
        {
            for (int p = 0; p < prof; p++)
            {
                cout << "C[" << r << "][" << c << "][" << p << "] = " << C[r][c][p] << endl;

                if (r == 0)
                {
                    result += C[r][c][p].substr(C[r][c][p].size() - 2, C[r][c][p].size() - 1);
                }
            }
        }
    }

    return result;
}

int main()
{
    string ***z = new string **[6];
    for (int i = 0; i < 6; i++)
    {
        z[i] = new string *[3];
        for (int j = 0; j < 3; j++)
        {
            z[i][j] = new string[3];
            for (int k = 0; k < 3; k++)
            {
                z[i][j][k] = "Hello";
            }
        }
    }

    cout << func(z, 6, 3, 3);
}