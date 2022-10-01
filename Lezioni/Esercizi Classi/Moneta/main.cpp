#include <iostream>
#include "moneta.h"
using namespace std;

int main()
{
    Moneta m1(0.7);
    Moneta m2;

    for (int c = 0; c < 1000; c++)
    {
        m1.lancia();
    }
}