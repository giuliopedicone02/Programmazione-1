#ifndef SERBATOIO_H // Se la costante SERBATOIO_H non è stata definita esegui il codice sottostante
#define SERBATOIO_H

#include <string>
using namespace std;

class Serbatoio
{
private:
    double capienza;
    double carburanteContenuto;

public:
    Serbatoio(string);
    double getCapienza();
    double getCarburanteContenuto();
    void inserisciCarburante(double);
    void consuma(double);
};

#endif