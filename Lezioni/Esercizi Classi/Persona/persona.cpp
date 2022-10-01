#include "persona.h"
#include <stdlib.h>
#include <time.h>
#include <iostream>
using namespace std;

Persona::Persona(string n, string c, int e) : nome(n), cognome(c), eta(e){};

void Persona::setNome(string n)
{
    nome = n;
}

void Persona::setCognome(string c)
{
    cognome = c;
}

void Persona::setEta(int e)
{
    eta = e;
}

string Persona::getNome()
{
    return nome;
}

string Persona::getCognome()
{
    return cognome;
}

int Persona::getEta()
{
    return eta;
}

void Persona::saluta()
{
    srand(time(NULL));

    int n = rand() % 3 + 1;

    switch (n)
    {
    case 1:
    {
        cout << "Buongiorno";
        break;
    }

    case 2:
    {
        cout << "Buonasera";
        break;
    }

    case 3:
    {
        cout << "Ciao";
        break;
    }
    default:
        break;
    }
}

void Persona::dici_nome()
{
    cout << "Mi chiamo: " << getNome() << " " << getCognome();
}

void Persona::dici_eta()
{
    cout << "La mia eta e: " << getEta();
}

void Persona::invecchia()
{
    setEta(getEta() + 1);
}

void Persona::saluta_persona(Persona p2)
{
    string saluto = "";

    if (p2.getEta() > getEta())
    {
        saluto = "Buongiorno ";
    }
    else
    {
        saluto = "Ciao ";
    }

    cout << saluto << p2.getNome() << " " << p2.getCognome() << " piacere di conoscerti!";
}