/*
    Sulla base degli esempi precedenti, codificare un
    ciclo while in linguaggio C++ nel quale:
    • il loop si ferma quando il capitale o montante
    raggiunge o supera la cifra target definita in una
    costante T;

    • tuttavia il periodo di accumulo di interessi sul
    montante non deve in ogni caso superare il
    numero di anni definito in una costante N.

*/

#include <iostream>
using namespace std;

#define T 1500
#define N 5
#define Tasso_Interesse 0.1

int main()
{
    double capitale = 1000.0;
    int anno = 0;

    while (capitale < T && anno <= N)
    {
        capitale += capitale * Tasso_Interesse;
        anno++;
    }

    cout << "Risultato: " << capitale;
}