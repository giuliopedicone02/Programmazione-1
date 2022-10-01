#include <iostream>
using namespace std;

int *getFibonacci(int n)
{
    int *F = new int[n];
    //int F[n]; Allocazione statica: WARNING in fase di compilazione!
    if (n > 0)
        F[0] = 0;
    if (n > 1)
        F[1] = 1;
    if (n > 2)
        for (int i = 2; i < n; i++)
            F[i] = F[i - 1] + F[i - 2];
    return F;
}

int main()
{
    int n = 10;
    int *x = getFibonacci(n); //Con allocazione statica restituirebbe un indirizzo non valido

    for (int i = 0; i < n; i++)
        cout << x[i] << endl;
}