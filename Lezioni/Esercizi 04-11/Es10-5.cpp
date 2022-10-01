/*
    Codificare un programma in C++ che chiede all’utente di
    inserire un carattere. Il programma dovr`a dare il seguente
    output:
    • Se il carattere `e una vocale minuscola, stampa il
    numero che rappresenta la sua codifica;
    • Se il carattere `e una vocale maiuscola, stampa il
    carattere stesso sullo standard output;
    • Se il carattere `e un numero compreso tra 1 e 3, stampa
    il numero stesso moltiplicato 10;

*/

#include <iostream>
#include <sstream>
using namespace std;

int main()
{
    char a;
    stringstream ss;

    cout << "Inserisci un carattere: ";
    cin >> a;

    if (a <= 122 && a >= 97)
    {
        cout << "Carattere ASCII: " << (int)a;
    }
    else if (a <= 90 && a >= 65)
    {
        cout << a;
    }
    else if (a <= 51 && a >= 49)
    {
        int y = 0;

        ss << a;
        ss >> y;

        cout << y * 10; //Cercare conversione char to int
    }
    else
    {
        cout << "Hai inserito un numero non compreso tra 1 e 3 o un carattere speciale";
    }
}
