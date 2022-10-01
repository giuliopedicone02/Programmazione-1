#include <iostream>
using namespace std;

class Classe
{
    int *x;
    int n;

public:
    Classe(int _n) : n(_n)
    {
        x = new int[n];
        for (int i = 0; i < n; i++)
            x[i] = i + 1;
    }
    int getNum(int i) { return x[i]; }

    ~Classe() // Distruttore
    {
        delete[] x;
        cout << "Oggetto distrutto";
    }
};

int main()
{
    Classe *o = new Classe(3);
    delete o;
}