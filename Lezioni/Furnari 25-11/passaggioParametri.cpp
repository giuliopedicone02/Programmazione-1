#include <iostream>
using namespace std;

void fun0(int x) //Passaggio per copia o valore
{
    x = 3;
}

void fun1(int &x) //Passaggio per riferimento o indirizzo
{
    x = 3;
}

void fun2(int *x) //passaggio per riferimento con uso di puntatori
{
    *x = 18;
}

void minmax(int x, int y, int &min, int &max)
{
    min = (x < y) ? x : y;
    max = (x > y) ? x : y;
}

// prende in input un array a interi (un puntatore)
// e un intero che rappresenta la lunghezza dell'array
void print_array(int *v, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << "[" << v[i] << "]";
    }

    /* uso della sintassi int v[] invece di int *v
         il risultato è il medesimo

        void print_array(int v[], int n) 
        {
             for(int i=0; i<n; i++) {
            cout << "[" << v[i] << "]";
        }*/
}

int main()
{
    int h = 7;

    cout << "Valore prima della funzione fun0(): " << h << endl;

    fun0(h);

    cout << "Valore dopo la funzione fun0(): " << h << endl;

    fun1(h);

    cout << "valore dopo la funzione fun1(): " << h << endl;

    fun2(&h); //Parametro passato per indirizzo e gestito dalla funzione tramite utilizzo di puntatori

    cout << "Valore dopo la funzione fun2(): " << h << endl;

    int x = 2;
    int y = 3;

    int min, max;

    minmax(x, y, min, max);

    cout << "Valore minimo: " << min << endl
         << "Valore massimo: " << max << endl;

    int arrx[]{0, 1, 2, 3};
    // usa la funzione
    print_array(arrx, 4);
}