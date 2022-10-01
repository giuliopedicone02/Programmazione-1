#ifndef DADO_H
#define DADO_H
#include <iostream>
#include <ctime>
using namespace std;

class Dado
{
private:
    short valore;

public:
    Dado();
    Dado(time_t); // time_t imposta un seed
    void lancia();
    int getValore();
};
#endif