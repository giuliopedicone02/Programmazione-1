#include "mazzo.h"
#include <cstdlib>
#include <ctime>

using namespace std;

// costruttore
Mazzo::Mazzo()
{
    ricomponi();    // ricompone il mazzo
    srand(time(0)); // imposta un seed
}

// pesca una carta
short Mazzo::pescaCarta()
{
    // se non ci sono più carte, restituisci -1
    if (contaCarte() == 0)
        return -1;
    // variabile che contiene l'indice della carta
    short carta;
    do
    {
        carta = rand() % 40;                // numero casuale intero tra 0 e 39
    } while (carte_pescate[carta] == true); // ripeti finché la carta scelta è già pescata
    carte_pescate[carta] = true;            // imposta la carta come pescata
    return carta + 1;                       // restituisci carta+1 (le carte vanno da 1 a 40, mentre gli inidici da 0 a 39)
}

// conta le carte non pescate del mazzo
short Mazzo::contaCarte()
{
    // inizializza una variabile contatore
    short num = 0;
    for (int i = 0; i < 40; i++)  // scorri il mazzo
        num += !carte_pescate[i]; // conta solo le carte non pescate
    return num;                   // restituisci il numero
}

// ricompone il mazzo
void Mazzo::ricomponi()
{
    // reimposta tutte le carte come non pescate
    for (int i = 0; i < 40; i++)
    {
        carte_pescate[i] = false;
    }
}