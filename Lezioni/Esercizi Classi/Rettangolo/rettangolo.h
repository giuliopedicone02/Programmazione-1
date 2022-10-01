#ifndef RETTANGOLO_H
#define RETTANGOLO_H

#include <iostream>
using namespace std;

class Rettangolo
{
private:
    double base;
    double altezza;

public:
    Rettangolo();
    Rettangolo(double);
    Rettangolo(double, double);
    void setBase(double);
    double getBase();
    void setAltezza(double);
    double getAltezza();
    double perimetro();
    double area();
};

#endif