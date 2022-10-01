#include <iostream>
#include "persona.h"
using namespace std;

int main()
{
    Persona p1("GM", "F", 54);
    Persona p2("Antonio", "Furnari", 48);
    Persona p3("Vincenzo", "Cutello", 86);

    p1.saluta_persona(p2);
    cout << endl;
    p2.saluta_persona(p3);
}
