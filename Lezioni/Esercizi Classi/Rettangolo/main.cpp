#include "rettangolo.h"
#include "../Cerchio/cerchio.h"
#include <iostream>
using namespace std;

int main()
{
    Rettangolo r1(2, 3);
    Cerchio c1(0.5); // 1 o più come parametro per enclose() true

    cout << "Base del rettangolo: " << r1.getBase() << endl;
    cout << "Altezza del rettangolo: " << r1.getAltezza() << endl;
    cout << "Perimetro del rettangolo: " << r1.perimetro() << endl;
    cout << "Area del cerchio: " << r1.area() << endl;

    cout << "Funzione enclose(): " << c1.enclose(r1);
}

// Per compilare g++ main.cpp rettangolo.cpp -o main.exe
// Per compilare esercizio 2 g++ main.cpp rettangolo.cpp ../Cerchio/cerchio.cpp -o main.exe
//  .\main.exe