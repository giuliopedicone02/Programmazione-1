/*
 Scrivere un programma in C++ finalizzato al calcolo dei valori di
dosaggio per la ricetta di un dolce.

Il programma chiede all’utente di inserire un numero compreso tra 2 e 16
che rappresenta il numero di persone che mangeranno il dolce.
Il programma chiede all’utente di inserire un valore che indica se tra i
commensali ci sono diabetici.

    Il programma calcola il dosaggio nel seguente modo:
    A dosaggio “base”, per un numero di persone compreso tra 2 e 4
    (estremi inclusi): 0.3kg di farina, 4 uova, 0.1kg di zucchero.

    B dosaggio “medio”, per un numero di persone compreso tra 5 e 8
    (estremi inclusi). 2 volte e mezzo il dosaggio base per la farina e le
    uova, 1 volta e mezzo il dosaggio base di zucchero.
    C dosaggio “esteso”, per un numero di persone compreso tra 9 e 16
    (estremi inclusi): in questo caso il dosaggio andr¸alcolato come la
    somma dei dosaggi dei due casi precedenti (medio e base).
    Inoltre:
    • se ci sono diabetici tra i commensali, usare il fruttosio al posto dello
    zucchero, e la dose sar`a la seguente:
    dosaggio Fruttosio = 2/3 × dosaggio Zucchero.
    • il numero di uova vanno arrotondati sempre per eccesso (es:
    2.1 → 3, 2.9 → 3, 9.45 → 10).
*/

#include <iostream>
#include <math.h>
#include <iomanip>
using namespace std;

#define FARINA 0.3
#define UOVA 4
#define ZUCCHERO 0.1

int main()
{
    int persone = 0;
    bool diabetici = false;

    cout << fixed << setprecision(2);

    do
    {
        cout << "Inserisci numero commensali (tra 2 e 16): ";
        cin >> persone;

        if (persone < 2 || persone > 16)
        {
            cerr << "\nDevi inserire un numero compreso tra 2 e 16, riprova!\n\n";
        }

    } while (persone < 2 || persone > 16);

    cout << "Ci sono diabetici tra i commensali? (Si=1, No=0): ";
    cin >> diabetici;

    switch (persone)
    {
    case 2:
    case 3:
    case 4:
    {
        cout << "Dosaggio Base" << endl;

        cout << "Farina: " << FARINA << " kg" << endl;
        cout << "Uova: " << UOVA << endl;

        if (diabetici)
        {
            cout << "Fruttosio: " << (ZUCCHERO * 2) / 3 << " kg" << endl;
        }
        else
        {
            cout << "Zucchero: " << ZUCCHERO << " kg" << endl;
        }

        break;
    }
    case 5:
    case 6:
    case 7:
    case 8:
    {
        cout << "Dosaggio Medio" << endl;

        cout << "Farina: " << FARINA * 2.5 << " kg" << endl;
        cout << "Uova: " << ceil(UOVA * 2.5) << endl;

        if (diabetici)
        {
            cout << "Fruttosio: " << ((ZUCCHERO * 1.5) * 2) / 3 << " kg" << endl;
        }
        else
        {
            cout << "Zucchero: " << ZUCCHERO * 1.5 << " kg" << endl;
        }

        break;
    }
    default:
    {
        cout << "Dosaggio Esteso" << endl;

        cout << "Farina: " << FARINA + (FARINA * 2.5) << " kg" << endl;
        cout << "Uova: " << ceil(UOVA + (UOVA * 2.5)) << endl;

        if (diabetici)
        {
            cout << "Fruttosio: " << ((ZUCCHERO + (ZUCCHERO * 1.5)) * 2) / 3 << " kg" << endl;
        }
        else
        {
            cout << "Zucchero: " << ZUCCHERO + (ZUCCHERO * 1.5) << " kg" << endl;
        }

        break;
    }
    }
}