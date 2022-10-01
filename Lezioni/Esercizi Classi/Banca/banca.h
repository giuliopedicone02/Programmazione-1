#ifndef BANCA_H
#define BANCA_H

#include <iostream>
using namespace std;

class ContoInBanca
{
private:
    int numeroDiConto;
    double giacenza;
    string proprietario;

public:
    ContoInBanca(int, double, string);
    ContoInBanca(int, string);
    void setNumeroDiConto(int);
    void setGiacenza(double);
    void setProprietario(string);
    int getNumeroDiConto();
    double getGiacenza();
    string getProprietario();
    bool prelievo(double);
    bool versamento(double);
    bool pagaImpostaDiBollo();
    bool pagaMensile();
};

#endif