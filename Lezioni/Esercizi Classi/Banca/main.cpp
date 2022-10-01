#include <iostream>
#include "banca.h"
using namespace std;

int main()
{
    ContoInBanca c1(00001, 5000.0, "GMF");
    ContoInBanca c2(00002, "VC");

    cout << " Importo attuale: " << c1.getGiacenza();

    if (c1.prelievo(50))
    {
        cout << "\n Effettuato un prelievo di 50 Euro ";
    }

    if (c1.pagaImpostaDiBollo())
    {
        cout << "\n Effettuato pagamento imposta di bollo di 34.20 Euro";
    }

    cout << "\n Importo attuale: " << c1.getGiacenza() << endl
         << endl;

    cout << c2.getProprietario() << " importo attuale: " << c2.getGiacenza() << endl;

    if (c2.prelievo(50))
    {
        cout << "\n Effettuato un prelievo di 50 Euro " << endl;
    }
    else
    {
        cout << "Sei povero come la fame fai un versamento" << endl;
    }

    c2.versamento(200);

    cout << endl;

    cout << c2.getProprietario() << " importo attuale: " << c2.getGiacenza() << endl;

    if (c2.prelievo(50))
    {
        cout << "\nEffettuato un prelievo di 50 Euro " << endl;
    }
    else
    {
        cout << "Sei povero come la fame fai un versamento" << endl;
    }

    cout << c2.getProprietario() << " importo attuale: " << c2.getGiacenza() << endl;
}

// Per comilare g++ main.cpp banca.cpp -o main.exe
//  .\main.exe