/*
   Codificare un programma in linguaggio C++ che calcoli e
    stampi l’ipotenusa di un triangolo rettangolo.
    L’utente dovr`a inserire i due cateti a e b da tastiera. Il
    programma dovr`a controllare che i valori inseriti siano positivi.


*/

#include <iostream>
#include <math.h>
using namespace std;

int main()
{
    double a = 0.0, b = 0.0;

    cout << "Inserisci valore primo cateto: ";
    cin >> a;

    cout << "Inserisci valore secondo cateto: ";
    cin >> b;

    if (a <= 0 || b <= 0)
    {
        cout << "Errore inserimento dati! Riprovare!";
        return -1;
    }

    cout << "Valore Ipotenusa: " << sqrt(pow(a, 2) + pow(b, 2));
}