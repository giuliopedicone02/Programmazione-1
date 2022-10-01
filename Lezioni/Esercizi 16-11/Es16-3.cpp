/*
    Codificare in C++ un programma battaglia navale in cui l’utente
    gioca contro il calcolatore.
    Il programma chiede all’utente le seguenti informazioni:
    • il nome del giocatore
    • la dimensione del campo di gara
    • la dimensione della tabella di gara.
    • la dimensione minima e massima delle navi, intesa come
    numero di celle occupate da ogni nave.
    
    Il programma dispone in modo casuale un certo numero di navi
    nella tabella del giocatore e nella tabella dell’avversario (il
    calcolatore).
    Il programma visualizza sempre e solo le due tabelle del giocatore,
    i) quella che contiene le navi del giocatore e ii) quella che contiene
    le mosse contro l’avversario. In questa ultima tabella saranno
    visibili solo i tiri a vuoto e i tiri a segno, mentre nella prima tabella
    saranno visibili le navi e i tiri a segno.
    Dopo l’inizio della battaglia, il programma chiede all’utente le
    coordinate dell’obiettivo (cella) da colpire, di conseguenza aggiorna
    le tabelle del giocatore.
    
    La mossa del calcolatore avverr`a dopo ogni mossa del giocatore.
    Anche in questo caso il giocatore vedr`a le sue tabelle aggiornate.
    Il giocatore pu`o chiedere al programma di interrompere il gioco in
    qualsiasi momento, in questo caso il programma offre al giocatore
    la possibilit`a di salvare lo stato del gioco su un file, e di scegliere
    un nome.
    Inoltre, ad ogni avvio del programma, l’utente pu`o scegliere se
    iniziare una nuova sessione di gioco oppure caricare una sessione di
    gioco salvata precedentemente in un file.
  
*/

#include <iostream>
#include <stdlib.h> /* srand, rand */
#include <time.h>
#include <string.h>
using namespace std;

int main()
{
    /* initialize random seed: */
    srand(time(NULL));

    string nome;
    int campo = 0, tabella = 0;
    int min = 0, max = 0;

    cout << "Inserisci nome: ";
    getline(cin, nome);

    cout << "Inserisci dimensione campo: "; //Cosa sarebbe il campo?!
    cin >> campo;

    do
    {
        cout << "Inserisci dimensione tabella: ";
        cin >> tabella;
        if (tabella < 1)
        {
            cerr << "\nAttenzione! Inserire un numero maggiore o uguale a 1!" << endl;
        }
    } while (tabella < 1);

    {
        cout << "Inserisci dimensione minima nave: ";
        cin >> min;
        if (min < 1 || min > tabella)
        {
            cerr << "\nAttenzione! Inserire un numero minore di " << tabella << " e maggiore di " << 1 << "!" << endl;
        }
    }
    while (min < 1 || min > tabella)
        ;

    do
    {
        cout << "Inserisci dimensione massima nave: ";
        cin >> max;

        if (max < min || max > tabella)
        {
            cerr << "\nAttenzione! Inserire un numero minore di " << tabella << " e maggiore di " << min << "!" << endl;
        }

    } while (max < min || max > tabella);

    cout << "Riepilogo: " << endl
         << endl;

    cout << "Ti chiami: " << nome << endl;
    cout << "Tabella di gioco: " << tabella << "x" << tabella << endl;
    cout << "Dimensione minima nave: " << min << endl;
    cout << "Dimensione massima nave: " << max << endl;
}