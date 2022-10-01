#include <iostream>
using namespace std;

class Contatore
{
    static int contatore; // variabile di isntanza, condivisa tra tutti gli oggetti
    int x;                // variabile di istanza: ogni oggetto avrà la sua copia
public:
    Contatore() : x(0) { contatore++; }
    int getX() const { return x; }
    void setX(int _x) { x = _x; }
    int getCount() { return contatore; }
    static int getCount2() { return contatore; }
};

int Contatore::contatore = 0;

int fun()
{
    static int c = 0;
    return ++c;
}

int main()
{
    /*Contatore c1(1);
    Contatore c2(2);
    Contatore c3(3);

    cout << c1.getX() << endl;
    cout << c2.getX() << endl;
    cout << c3.getX() << endl;

    cout << c1.getCount() << endl;
    cout << c2.getCount() << endl;
    cout << c3.getCount() << endl;*/

    cout << Contatore::getCount2() << endl; // Richiamabile senza istanziare prima un oggetto
}