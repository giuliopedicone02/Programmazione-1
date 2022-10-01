#ifndef MONETA_H
#define MONETA_H

class Moneta
{
private:
    double p;

public:
    Moneta();
    Moneta(double);
    void lancia();
    void setP(double);
    double getP();
};
#endif