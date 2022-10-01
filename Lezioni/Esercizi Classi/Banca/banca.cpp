#include "banca.h"
#include <iostream>
using namespace std;

ContoInBanca::ContoInBanca(int n, string p) : numeroDiConto(n), giacenza(0), proprietario(p){};

ContoInBanca::ContoInBanca(int n, double g, string p) : numeroDiConto(n), giacenza(g), proprietario(p){};

void ContoInBanca::setNumeroDiConto(int n)
{
    numeroDiConto = n;
}

void ContoInBanca::setGiacenza(double g)
{
    giacenza = g;
}

void ContoInBanca::setProprietario(string p)
{
    proprietario = p;
}

int ContoInBanca::getNumeroDiConto()
{
    return numeroDiConto;
}

double ContoInBanca::getGiacenza()
{
    return giacenza;
}

string ContoInBanca::getProprietario()
{
    return proprietario;
}

bool ContoInBanca::prelievo(double p)
{
    if (getGiacenza() - p >= 0)
    {
        setGiacenza(getGiacenza() - p);
        return true;
    }

    return false;
}

bool ContoInBanca::versamento(double v)
{
    setGiacenza(getGiacenza() + v);
    return true;
}

bool ContoInBanca::pagaImpostaDiBollo()
{
    if (getGiacenza() - 34.20 >= 0)
    {
        setGiacenza(getGiacenza() - 34.20);
        return true;
    }

    return false;
}

bool ContoInBanca::pagaMensile()
{
    if (getGiacenza() - 12.0 >= 0)
    {
        setGiacenza(getGiacenza() - 12.0);
        return true;
    }

    return false;
}