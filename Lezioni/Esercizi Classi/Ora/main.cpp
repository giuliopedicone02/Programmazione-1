#include <iostream>
#include "ora.h"
using namespace std;

int main()
{
    Ora x;
    Ora y(12, 30, 00);
    Ora z(12, 0, 30);

    x.visualizzaOrario();

    cout << endl;
    y.visualizzaOrario();

    cout << endl;

    z.visualizzaOrario();

    cout << endl;

    // y.sommaOrario(z);

    y + z;
}