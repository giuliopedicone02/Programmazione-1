#include <iostream>
#include <cmath>
#include "dado.h"
#include "mazzo.h"

using namespace std;

int main()
{
    Dado d1, d2, d3;

    d1.lancia();
    d2.lancia();
    d3.lancia();

    int dado1 = d1.getValore();
    int dado2 = d1.getValore();
    int dado3 = d3.getValore();
    int maxd = dado1;

    while (dado1 == dado2 || dado1 == dado3 || dado2 == dado3)
    {
        d1.lancia();
        d2.lancia();
        d3.lancia();

        dado1 = d1.getValore();
        dado2 = d1.getValore();
        dado3 = d3.getValore();
    }

    // maxd = max(dado1, dado2, dado3);

    cout << dado1 << dado2 << dado3;
}