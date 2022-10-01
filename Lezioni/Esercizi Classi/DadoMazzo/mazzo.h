class Mazzo
{
    bool carte_pescate[40]; // indica se la carta di indice i è stata pescata
public:
    Mazzo();            // costruttore
    short pescaCarta(); // pesca una carta
    short contaCarte(); // conta le carte non pescate
    void ricomponi();   // ricompone il mazzo recuperando le carte pescate
};