#include <iostream>
using namespace std;

/*L’allocazione dimanica permette di usare un’area di memoria condivisa dall’intero programma, detta heap. 
Per allocare una variabile dinamicamente, va usata la keyword new. 
La new restituirà un puntatore alla locazione di memoria definita nello heap. */

int **fun()
{
    int **v = new int *[3];

    for (int i = 0; i < 3; i++)
    {
        v[i] = new int[4];

        for (int j = 0; j < 4; j++)
        {
            v[i][j] = 0;
        }
    }
    return v;
}

int main()
{
    int *x = new int[3];
    x[0] = 0;
    x[1] = 1;
    x[2] = 2;

    int *y;
    {
        int *x = new int(5);
        y = x;
    }
    int z = 3;
    cout << *y << endl;

    /*Dato che le variabili allocate in maniera dinamica sono persistenti, 
    esse vanno eliminate esplicitamente mediante la parola chiave delete quando non più utili. 
    Questa operazione viene detta anche deallocazione.*/

    int *p = new int(2);
    cout << *p << endl;
    delete p;
    cout << *p << endl; //Non contiene il valore 2 ma un valore presente in memoria errato

    int *a = new int[5]{1, 2, 3, 4, 5};
    cout << a[2] << endl;

    /*Va notato che l’allocazione dinamica dell’array restituisce un puntatore a int.
    Questo si comporta come un array, ma non è un puntatore costante.
    Infatti, possiamo in qualsiasi momento cambiare il valore del puntatore ad esempio con : */

    a = nullptr;

    int *b = new int[5]{1, 2, 3, 4, 5};
    cout << b[2] << endl;

    /*Tuttavia, mentre a risiede nello heap, b risiede nello stack.
    La deallocazione di un array allocato dinamicamente si fa mediante la parola chiave delete[]:*/

    delete[] a;

    int s[3][3];
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            s[i][j] = i + j;
        }
    }

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cout << "s[" << i << "][" << j << "]=" << s[i][j] << endl;
        }
    }
}