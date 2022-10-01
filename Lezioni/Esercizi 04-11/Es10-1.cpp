/*
    Siano a,b,c tre variabili di tipo int. Trovare il massimo dei tre numeri usando l'operatore condizionale
*/

#include <iostream>
using namespace std;

int main()
{
    int a, b, c;

    cout << "Inserisci primo numero: ";
    cin >> a;

    cout << "Inserisci secondo numero: ";
    cin >> b;

    cout << "Inserisci terzo numero: ";
    cin >> c;

    cout << "Numero maggiore: " << (a > b ? (a > c ? a : (b > c ? b : c)) : (b > c ? b : c));
}