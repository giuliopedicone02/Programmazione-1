#include <iostream>
using namespace std;

class Classe
{
    int x;

public:
    Classe() : x(0) {}
    Classe(int _x) : x(_x) {}
    void setX(int _x) { x = _x; }
    int getX() { return x; }

    int getX2() const { return x; }
};

void print(const Classe &o) // Definito come reference, il const è una garanzia che il valore non verrà mai modificato
{
    // cout << o.getX() << endl; //Errore stiamo utilizzando una funzione senza modificatore const
    cout << o.getX2() << endl;
}

void print_ptr(const Classe *o) // In questo caso il puntatore è costante ma non ci garantisce che il valore verrà modificato all'interno della funzione, meglio quindi usare le reference
{
    cout << o->getX2() << endl;
}

int main()
{
    Classe o;
    Classe o2(-2);
    Classe &ref_o = o; //&ref_o possiede l'indirizzo di o
    Classe *ptr_o = &o;

    ref_o.setX(2);

    cout << o.getX();     // Stampa 2
    cout << ref_o.getX(); // Stampa anch'esso 2 perchè ref_o è un alias di o
    cout << ptr_o->getX();

    ptr_o = &o2;
    o.setX(-18); // Adesso ptr_o punta ad o2 quindi verrà stampato il valore di o2
    cout << endl
         << ptr_o->getX();

    ref_o = o2;  // Equivalente ad o = o2
    o.setX(-18); // Le reference sono statiche non possono cambiare oggetto al quale puntano
    cout << endl
         << ref_o.getX() << endl;

    // Classe &r; // Una reference deve essere sempre inizializzata, non può puntare a nullptr

    int x = 8;
    const int &r = x;
    cout << r << endl;

    // r=-2; //Impossibile sovrascrivere, il modificatore const rende la reference di sola lettura

    const Classe &ref = o;

    // ref.setX(0); // Impossibile sovrascrivere, il modificatore const rende la reference di sola lettura

    // cout << ref.getX(); //Anche questa da errore perchè il compilatore non sa se il metodo getX() va a modificare il valore nel corso della funzione

    cout << ref.getX2(); // Adesso funziona perchè è stato specificato che il metodo è di tipo const

    print(ref);
}
