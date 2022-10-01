#include <iostream>
using namespace std;

void print1(int x[], int n)
{
    for (int i = 0; i < n; i++)
        cout << "x[" << i << "]=" << x[i] << endl;
    cout << endl;
}

void print2(int *x, int n)
{
    for (int i = 0; i < n; i++)
        cout << "x[" << i << "]=" << x[i] << endl;
    cout << endl;
}

int main()
{
    int s[] = {1, 2, 3}; //Modalità statica
    print1(s, 3);
    print2(s, 3);

    int *d = new int[3]{1, 2, 3}; //Modalità dinamica
    print1(d, 3);
    print2(d, 3);
}