#include "moneta.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

Moneta::Moneta() : p(0.5)
{
    srand(time(NULL));
};

Moneta::Moneta(double pr) : p(pr)
{
    srand(time(NULL));
};

void Moneta::setP(double pr)
{
    p = pr;
}

double Moneta::getP()
{
    return p;
}
void Moneta::lancia()
{

    double rnd = double(rand()) / RAND_MAX;
    if (rnd > 1 - getP())
    {
        cout << "Croce" << endl;
        return;
    }

    cout << "Testa" << endl;
    return;
}