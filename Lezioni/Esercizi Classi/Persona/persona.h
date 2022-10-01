#ifndef PERSONA_H
#define PERSONA_H
#include <iostream>
using namespace std;

class Persona
{
private:
    string nome, cognome;
    int eta;

public:
    Persona(string, string, int);
    void setNome(string);
    void setCognome(string);
    void setEta(int);

    string getNome();
    string getCognome();
    int getEta();

    void saluta();
    void dici_nome();
    void dici_eta();
    void invecchia();
    void saluta_persona(Persona);
};

#endif