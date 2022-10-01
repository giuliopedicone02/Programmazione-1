#include <iostream>
#include <string>
using namespace std;
class Animale // Classe astratta o funzione virtuale pura, almeno un metodo astratto
{
protected:
    string verso;

public:
    virtual void parla() = 0; // Se esiste una specializzazione del metodo parla() nelle classi "figlie" considera il metodo della classe "figlia"

    // virtual void parla() = 0 //Metodo astratto o metodo virtuale puro

    void corri()
    {
        cout << "Run run run" << endl;
    }
};

/* //Interfaccia se tutti i metodi al suo interno sono presenti solo funzioni virtuali pure
class Animale
{
public:
    virtual void parla() = 0;
    virtual void corri() = 0;
    virtual void dormi() = 0;
}*/

class Cane : public Animale
{
public:
    void parla() { cout << "bau" << endl; }
};

class Gatto : public Animale
{
public:
    void parla() { cout << "miao" << endl; }
};
int main()
{

    Animale *a = nullptr;
    string animale = "gatto";

    if (animale == "gatto")
        a = new Gatto();
    else if (animale == "cane")
        a = new Cane();
    else
        cerr << "Permessi solo cane e gatto";
    if (a)
        a->parla();
    a->corri();
}