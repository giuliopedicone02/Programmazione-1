/*
    Codificare in linguaggio C++ un algoritmo che produca la
    somma dei numeri interi dispari da 1 a 99, facendo uso del
    costrutto for. Dalla somma vanno esclusi i numeri divisibili
    per tre.
*/

#include <iostream>
using namespace std;

int main()
{
    for (int c = 1; c <= 99; c++)
    {
        if (c % 2 != 0 && c % 3 != 0)
        {
            cout << c << endl;
        }
    }
}