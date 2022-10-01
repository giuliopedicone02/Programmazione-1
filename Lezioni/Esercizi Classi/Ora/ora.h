#include <iostream>
using namespace std;

class Ora
{
private:
    int ore, minuti, secondi;

public:
    Ora();
    Ora(int, int, int);
    void operator+(Ora);
    void setOra(int);
    void setMinuto(int);
    void setSecondo(int);
    int getOra();
    int getMinuto();
    int getSecondo();
    void visualizzaOrario();
    void sommaOrario(Ora);
};