#include <iostream>
using namespace std;

int main()
{
    int a[5] = {2, 3, 6, 8, 9};
    int *ptr = a; //Variabile puntatore che punta a a[0]

    int b = 2;
    int *ptr2 = &b; //variabile puntatore che punta all'indirizzo di b

    cout << a << endl;      //Stampa l'indirizzo di a[0]
    cout << *a + 1 << endl; //Stampa 3
    cout << ptr << endl;    //Equivalente a stampare 'a'
    cout << *ptr << endl;   //Stampa il contenuto della cella di memoria ptr ovvero 2

    cout << b << endl;    //Stampa 2
    cout << &b << endl;   //Stampa l'indirizzo di memoria della variabile b
    cout << ptr2 << endl; //Analogo ad &b
    cout << *ptr2;        //Stampa il contenuto della cella di memoria puntata (2)
}