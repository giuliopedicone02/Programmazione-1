#include "cerchio.h"
#include "../Rettangolo/rettangolo.h"
#include <iostream>
#include <cmath>
using namespace std;

Cerchio::Cerchio(double raggio) : r(raggio){};

void Cerchio::setRaggio(double raggio)
{
    r = raggio;
}

double Cerchio::getRaggio()
{
    return r;
}

double Cerchio::area()
{
    return r * r * 3.14159265358979323846;
}

double Cerchio::circonferenza()
{
    return 2 * r * 3.14159265358979323846;
}

bool Cerchio::enclose(Rettangolo r1)
{
    if (r1.area() <= area())
    {
        return true;
    }
    else
    {
        return false;
    }
}