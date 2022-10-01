/*Scrivere un metodo che prenda in input una matrice A di stringhe di dimensioni n × m
ed una matrice B di puntatori a
stringhe di dimensioni m × l.
Il metodo restituisca un vettore di booleani C di dimensione l in cui cj = true se e solo se `e
possibile trovare almeno una stringa, nella colonna j −esima di B (sia bkj ),
la quale sia sottostringa della corrispondente stringa
presente nella riga j − esima di A (sia ajk). Si assuma n ≥ l.
NB: si presti attenzione alle stringhe mancanti in B*/
#include <iostream>
#include <string>
using namespace std;

bool *func(string **A, int n, int m, string ***B, int l)
{
    bool *C = new bool[l];

    for (int j = 0; j < m; j++)
    {
        for (int k = 0; j < n; k++)
        {
            string s1 = *B[k][j];
            string s2 = A[j][k];

            if (s1.find(s2) != string::npos)
            {
                C[j] = true;
            }
            else
            {
                C[j] = false;
            }
        }
    }

    return C;
}

int main()
{
}