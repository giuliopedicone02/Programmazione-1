#include <iostream>
#include <cstdlib>
#include <ctime>
#include "dado.h"
using namespace std;

Dado::Dado()
{
    // imposta il seed di default
    srand(time(0));
    lancia(); // lanciamo il dado appena creato
}

Dado::Dado(time_t seed)
{
    srand(seed); // impostiamo il seed ricevuto in input
    lancia();    // lanciamo il dado appena creato
}

void Dado::lancia()
{
    valore = rand() % 6 + 1; // numero casuale tra 1 e 6
}

int Dado::getValore()
{
    return valore;
}