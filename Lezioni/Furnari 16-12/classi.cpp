#include <iostream>
using namespace std;

class Rettangolo
{
private:      // Non sarà possibile accedere a proprieta e metodi dall'esterno dell'oggetto
    int a, b; // Lati del rettangolo
    void set_values(int, int);

public: // Sarà possibile accedere a proprietà e metodi al di fuori dell'oggetto
    Rettangolo();
    Rettangolo(int);
    Rettangolo(int, int);
    int area();
    void setWidth(int);
    void setHeight(int);
    int getWidth();
    int getHeight();

    /*
    Rettangolo(int w, int h) // Costruttore con parametri, può essre richiamato solo una volta
    {
        a = w;
        b = h;
    }

    Rettangolo(int s) // Costruiamo un quadrato
    {
        a = s;
        b = s;
    }

    Rettangolo() // Costruttore senza parametri, può essere richiamato solo una volta
    {
        a = 0;
        b = 0;
    }

    void Rettangolo::setWidth(int w)
    {
        a = w;
    }

    void Rettangolo::setHeight(int h)
    {
        b = h;
    }

    int Rettangolo::getWidth()
    {
        return a;
    }

    int Rettangolo::getHeight()
    {
        return b;
    }

    void set_values(int w, int h) // Equivalente al costruttore
    {
        a = w;
        b = h;
    }

    int area()
    {
        return a * b;
    }*/
};

Rettangolo::Rettangolo(int w, int h) // Costruttore con parametri, può essre richiamato solo una volta
{
    a = w;
    b = h;
}

Rettangolo::Rettangolo(int s) // Costruiamo un quadrato
{
    a = s;
    b = s;
}

Rettangolo::Rettangolo() : a(0), b(0){}; // Costruttore senza parametri, può essere richiamato solo una volta

void Rettangolo::setWidth(int w)
{
    a = w;
}

void Rettangolo::setHeight(int h)
{
    b = h;
}

int Rettangolo::getWidth()
{
    return a;
}

int Rettangolo::getHeight()
{
    return b;
}

void Rettangolo::set_values(int w, int h) // Equivalente al costruttore
{
    a = w;
    b = h;
}

int Rettangolo::area()
{
    return a * b;
}

int main()
{
    Rettangolo r(3, 5);
    Rettangolo s(2);
    Rettangolo n; // Rettangolo n() ERRORE!

    cout << "Valore area del quadrato con lato " << s.getHeight() << ": " << s.area() << endl;

    cout << "Valore area del rettangolo con lati " << r.getWidth() << " e " << r.getHeight() << ": " << r.area() << endl;

    cout << "Valore area del rettangolo nullo: " << n.area() << endl;

    // r.set_values(5, 6); Errore! set_values() è un metodo privato ed è quindi inaccessibile

    r.setWidth(5);
    r.setHeight(6);

    cout << "Valore area del rettangolo con lati " << r.getWidth() << " e " << r.getHeight() << ": " << r.area() << endl;
}