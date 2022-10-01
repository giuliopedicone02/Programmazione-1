#include <iostream>
#include "cerchio.h"
using namespace std;

int main()
{
    Cerchio c1(12);

    cout << "Raggio del cerchio; " << c1.getRaggio() << endl;
    cout << "Perimetro del cerchio: " << c1.circonferenza() << endl;
    cout << "Area del cerchio: " << c1.area() << endl;
}

// Per compilare g++ main.cpp cerchio.cpp -o main.exe
//.\main.cpp