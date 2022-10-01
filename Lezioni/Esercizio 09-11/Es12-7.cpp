/*
    Tre vasche A, B e C raccolgono acqua da 15 tubi differenti.
    • La vasca A riceve l’acqua convogliata nei tubi 1,5,6,10.
    • La vasca B riceve l’acqua convogliata nei tubi da 2 a 4 e da 7
    a 9.
    • La vasca C riceve l’acqua convogliata nei rimanenti tubi.
    Inoltre, i tubi con numero dispari hanno una portata di 60 litri al
    minuto, mentre quelli con numero pari hanno una portata di 120
    litri al minuto.

    Codificare un programma in linguaggio C++ che esegua le seguenti
    operazioni:

    • il programma chiede in input all’utente 5 numeri distinti, compresi
    tra 1 e 15. Tali numeri rappresentano 5 differenti tubi. NB: il
    programma deve operare un controllo sulla validit`a dell’input (ad
    esempio che i numeri siano tutti differenti tra loro);
    • il programma chiede all’utente il numero totale di minuti (M)
    durante i quali i tubi specificati forniranno acqua alla rispettiva
    vasca. NB: il programma deve operare un controllo sulla validit`a
    dello input, ad esempio che il numero immesso sia positivo.
    • il programma calcola e stampa la quantit d’acqua raccolta in ogni
    vasca dopo gli M minuti speficicati dall’utente.

*/

#include <iostream>
#include <math.h>
#include <iomanip>
using namespace std;

#define PARI 120
#define DISPARI 60

int main()
{
    int a = 0, b = 0, c = 0, d = 0, e = 0, m = 0;

    cout << fixed << setprecision(2);

    do
    {
        cout << "Inserisci primo numero (compreso tra 1 e 15): ";
        cin >> a;

        if (a < 1 || a > 15)
        {
            cerr << "\nDevi inserire un numero compreso tra 1 e 15, riprova!\n\n";
        }

    } while (a < 1 || a > 15);

    do
    {
        cout << "Inserisci secondo numero (compreso tra 1 e 15): ";
        cin >> b;

        if (b < 1 || b > 15)
        {
            cerr << "\nDevi inserire un numero compreso tra 1 e 15, riprova!\n\n";
        }

    } while (b < 1 || b > 15);

    do
    {
        cout << "Inserisci terzo numero (compreso tra 1 e 15): ";
        cin >> c;

        if (c < 1 || c > 15)
        {
            cerr << "\nDevi inserire un numero compreso tra 1 e 15, riprova!\n\n";
        }

    } while (c < 1 || c > 15);

    do
    {
        cout << "Inserisci quarto numero (compreso tra 1 e 15): ";
        cin >> d;

        if (d < 1 || d > 15)
        {
            cerr << "\nDevi inserire un numero compreso tra 1 e 15, riprova!\n\n";
        }

    } while (d < 1 || d > 15);

    do
    {
        cout << "Inserisci quinto numero (compreso tra 1 e 15): ";
        cin >> e;

        if (e < 1 || e > 15)
        {
            cerr << "\nDevi inserire un numero compreso tra 1 e 15, riprova!\n\n";
        }

    } while (e < 1 || e > 15);

    do
    {
        cout << "Inserisci numero di minuti: ";
        cin >> m;

        if (m < 0)
        {
            cerr << "\nDevi inserire un numero maggiore di 0, riprova!\n\n";
        }

    } while (m < 0);

    int dati[] = {a, b, c, d, e};

    /***********************************
        Controllo dei dati inseriti
    ************************************/

    for (int c = 0; c < 5; c++)
    {
        for (int i = 0; i < 5; i++)
        {
            if (dati[c] == dati[i] && c != i)
            {
                cerr << "I numeri inseriti sono stati ripetuti una o piu volte, si prega di riprovare!";
                return -1;
            }
        }
    }

    cout << "\n\n****************************\n\n";

    int vasca_A = 0, vasca_B = 0, vasca_C = 0;

    for (int c = 0; c < 5; c++)
    {
        switch (dati[c])
        {
        case 1:
        case 5:
        case 6:
        case 10:
        {
            if (dati[c] % 2 == 0)
            {
                vasca_A += PARI * m;
            }
            else
            {
                vasca_A += DISPARI * m;
            }

            break;
        }
        case 2:
        case 3:
        case 4:
        case 7:
        case 8:
        case 9:
        {
            if (dati[c] % 2 == 0)
            {
                vasca_B += PARI * m;
            }
            else
            {
                vasca_B += DISPARI * m;
            }

            break;
        }
        default:
        {
            if (dati[c] % 2 == 0)
            {
                vasca_C += PARI * m;
            }
            else
            {
                vasca_C += DISPARI * m;
            }

            break;
        }
        }
    }

    cout << "In " << m << " minuti le vasche A,B e C contengono rispettivamente: " << endl;

    cout << "A: " << vasca_A << " litri" << endl;
    cout << "B: " << vasca_B << " litri" << endl;
    cout << "C: " << vasca_C << " litri" << endl;
}