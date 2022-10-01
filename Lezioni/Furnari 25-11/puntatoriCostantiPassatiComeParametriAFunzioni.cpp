#include <iostream>
using namespace std;
/*Dato che gli array vengono sempre passati per riferimento, 
le funzioni possono di norma modificarne i valori.
 Ciò non è sempre una caratteristica desiderabile. Consideriamo il seguente esempio:*/

void print(int x[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << "x[" << i << "]=" << x[i] << endl;
        x[i] = 0;
    }
}

void print2(const int x[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << "y[" << i << "]=" << x[i] << endl;
        //x[i] = 0; //questa funzione darebbe un errore!
    }
}
int main()
{
    int x[]{1, 2, 3};
    print(x, 3);
    print(x, 3);

    /*La prima delle due invocazioni a print stamperà il contenuto dell’array.
     Tuttavia, a dispetto del nome, la funzione modifica anche il contenuto di x.
      Pertanto, la seconda invocazione di print stamperà solo zeri.
       Questo comportamento non è desiderato e può confondere.
    Infatti, guardando solo il main, ci si aspetterebbe che le due invocazioni a print
     dessero lo stesso risultato.
      Possiamo assicurarci che la funzione non modifichi in alcun modo l’array in input, 
      definendo il parametro come const:*/

    int y[]{1, 2, 3};
    print2(y, 3);
}