#ifndef CERCHIO_H
#define CERCHIO_H

#include <iostream>
#include "../Rettangolo/rettangolo.h"
using namespace std;

class Cerchio
{
private:
    double r;

public:
    Cerchio(double);
    void setRaggio(double);
    double getRaggio();
    double area();
    double circonferenza();
    bool enclose(Rettangolo);
};
#endif