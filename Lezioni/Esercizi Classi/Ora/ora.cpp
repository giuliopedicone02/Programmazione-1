#include "ora.h"
#include <iostream>
using namespace std;

Ora::Ora() : ore(0), minuti(0), secondi(0){};

Ora::Ora(int o, int m, int s) : ore(o), minuti(m), secondi(s){};

void Ora::setOra(int o)
{
    ore = o;
}

void Ora::setMinuto(int m)
{
    minuti = m;
}

void Ora::setSecondo(int s)
{
    secondi = s;
}

int Ora::getOra()
{
    return ore;
}

int Ora::getMinuto()
{
    return minuti;
}

int Ora::getSecondo()
{
    return secondi;
}

void Ora::visualizzaOrario()
{
    cout << getOra() << " : " << getMinuto() << " : " << getSecondo();
}

void Ora::operator+(Ora x)
{
    int ora = x.getOra();
    int minuto = x.getMinuto();
    int secondo = x.getSecondo();

    int o = getOra(), m = getMinuto(), s = getSecondo(), d = 0;

    cout << ora << minuto << secondo << endl;

    if (secondo != 0)
    {
        for (int c = secondo; c > 0; c--)
        {
            s++;

            if (s > 59)
            {
                m++;
                s = 0;
            }

            if (m > 59)
            {
                o++;
                m = 0;
            }

            if (o > 23)
            {
                d++;
                o = 0;
            }
        }
    }

    if (minuto != 0)
    {
        for (int c = minuto; c > 0; c--)
        {
            m++;

            if (m > 59)
            {
                o++;
                m = 0;
            }

            if (o > 23)
            {
                d++;
                o = 0;
            }
        }
    }

    if (ora != 0)
    {

        for (int c = ora; c > 0; c--)
        {
            o++;

            if (o > 23)
            {
                d++;
                o = 0;
            }
        }
    }
    if (d == 0)
    {
        cout << o << " : " << m << " : " << s;
    }
    else
    {
        cout << o << " : " << m << " : " << s << " + " << d << " giorno/i";
    }
}