/*
    Un falegname realizza scaffali di legno per ambienti interni o
    esterni. I clienti si recano presso il suo laboratorio con alcune
    richieste (input) in base alle quali il falegname opera alcune
    scelte:
    1. ambiente: esterno o interno
    2. massimo carico (in kg) che il singolo ripiano deve essere
    in grado di sopportare;
    3. lunghezza in metri di ogni ripiano;

    Il falegname dovr`a operare nel modo seguente:
    1. Se lo scaffale va sistemato all’esterno allora va impiegato
    legno di castagno, altrimenti legno di pino;
    2. lo spessore di ogni ripiano va calcolato in base alla
    formula S = [B + max(0, L − 1) × P] × Q, dove:
    • L `e la lunghezza (in metri) di ogni ripiano fornita dal
    cliente;
    • B = 0.018 metri se si usa il castagno, B = 0.02 metri
    se si usa il pino;
    • P = 0.02 per il castagno, P = 0.022 per il pino

    • Q = 1.1 se il legno scelto `e il castagno e se il
    massimo carico che il singolo ripiano deve supportare
    `e maggiore di 100 kg, altrimenti Q = 1.0;
    • Q = 1.2 se il legno scelto `e il pino e se il carico
    massimo che il singolo ripiano deve supportare `e
    maggiore di 80kg, altrimenti Q = 1.0.

    Descrivere una soluzione del problema tale che, dati in input i
    parametri ambiente, lunghezza L e carico massimo del singolo
    ripiano dello scaffale, produca in output:
    • essenza da usare (pino o castagno)
    • spessore ripiani.
    In particolare:
    1. Realizzare un diagramma di flusso (o a blocchi) per la
    risoluzione del problema del falegname;
    2. Codificare in C++ un programma che si base sul
    diagramma di flusso realizzato per il punto precedente;
    3. Testare il programma in C++ mediante hand tracing per i
    seguenti input:
    a Carico max 80kg, scaffale non destinato all’esterno,
    lunghezza ripiani 150cm;
    b Carico max 100kg, scaffale destinato all’esterno,
    lunghezza ripiani 100cm;
    c Carico max 120kg, scaffale non destinato all’esterno,
    lunghezza ripiani 100cm;

*/

#include <iostream>
#include <math.h>
using namespace std;

#define B_Castagno 0.018
#define B_Pino 0.02

#define P_Castagno 0.02
#define P_Pino 0.022

#define Q 1.0

#define Q_Castagno 1.1
#define Q_Pino 1.2

float calcolaSpessore(char luogo, float b, float l, float p, float q)
{
    float max = 0;

    (0 > l - 1 ? max = 0 : max = l - 1);

    return (b + max * p) * q;
}

int main()
{
    char luogo;
    float massimo_carico = 0;
    float lunghezza_ripiano = 0;
    float q = 0;

    cout << "Inserire luogo (i = interno, e = esterno): ";
    cin >> luogo;

    cout << "Inserire carico massimo del ripiano in kg: ";
    cin >> massimo_carico;

    cout << "Inserire lunghezza del ripiano in metri: ";
    cin >> lunghezza_ripiano;

    cout << "\n\n******** RISULTATO ********** \n\n";

    switch (luogo)
    {
    case 'i':
    {
        if (massimo_carico > 80)
        {
            q = Q_Pino;
        }
        else
        {
            q = Q;
        }

        cout << "Essenza da usare: "
             << "Pino" << endl;

        cout << "Spessore ripiano: " << calcolaSpessore(luogo, B_Pino, lunghezza_ripiano, P_Pino, q);
        break;
    }
    case 'e':
    {
        if (massimo_carico > 100)
        {
            q = Q_Castagno;
        }
        else
        {
            q = Q;
        }

        cout << "Essenza da usare: "
             << "Castagno" << endl;

        cout << "Spessore ripiano: " << calcolaSpessore(luogo, B_Castagno, lunghezza_ripiano, P_Castagno, q);
        break;
    }
    default:
    {
        cout << "Hai inserito un carattere errato!";
    }
    }
}
