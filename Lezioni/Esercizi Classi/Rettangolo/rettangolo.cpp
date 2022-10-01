#include "rettangolo.h"
#include <iostream>
using namespace std;

Rettangolo::Rettangolo() : base(0), altezza(0){};

Rettangolo::Rettangolo(double a) : base(a), altezza(a){};

Rettangolo::Rettangolo(double a, double b) : base(a), altezza(b){};

void Rettangolo::setBase(double a)
{
    base = a;
}

void Rettangolo::setAltezza(double b)
{
    altezza = b;
}

double Rettangolo::getBase()
{
    return base;
}

double Rettangolo::getAltezza()
{
    return altezza;
}

double Rettangolo::perimetro()
{
    return (base * 2) + (altezza * 2);
}

double Rettangolo::area()
{
    return base * altezza;
}