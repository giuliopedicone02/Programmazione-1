/*
    Codificare un programma in linguaggio C++ che chieda
    all’utente di inserire da tastiera il proprio nome e cognome.
    Successivamente il programma dovr`a stampare le seguenti
    informazioni:
    1. il primo e l’ultimo carattere del nome, il secondo ed il
    terzo carattere del cognome.
    2. una stringa formata da tutti i caratteri che sono presenti
    sia nel nome che nel cognome. ES: se nome=”Mario”,
    cognome= ”Rossi” lo output sar`a ”io”.

    3. le segg. ulteriori informazioni:
    a un messaggio che comunica all’utente se la prima
    lettera del nome `e uguale all’ultima lettera del cognome.
    b un messaggio che comunica all’utente se il numero di
    caratteri del nome `e uguale al numero di lettere del
    cognome.
    c il numero di consonanti del nome e del cognome.

*/

#include <iostream>
#include <string>
using namespace std;

int main()
{
    string nome, cognome;

    cout << "Inserisci il nome: ";
    getline(cin, nome);

    cout << "Inserisci il cognome: ";
    getline(cin, cognome);

    cout << "\n\n****************************\n\n";

    cout << "Primo carattere del nome: " << nome[0] << endl;
    cout << "Ultimo carattere del nome: " << nome[nome.size() - 1] << endl;

    cout << "Secondo carattere del nome: " << cognome[1] << endl;
    cout << "Terzo carattere del nome: " << cognome[2];

    cout << "\n\n****************************\n\n";

    string comune;
    bool presente = false;

    for (int c = 0; c < nome.size(); c++)
    {
        for (int i = 0; i < cognome.size(); i++)
        {
            presente = false;

            if (nome[c] == cognome[i])
            {
                for (int t = 0; t < comune.size(); t++)
                {
                    if (comune[t] == nome[c])
                    {
                        presente = true;
                    }
                }
                if (presente == false)
                {
                    comune += nome[c];
                    break;
                }
            }
        }
    }

    cout << "Caratteri presenti sia nel nome che nel cognome: " << comune;

    cout << "\n\n****************************\n\n";

    if (nome[0] == cognome[cognome.size() - 1])
    {
        cout << "Il primo carattere del nome corrisponde all ultimo carattere del cognome" << endl;
    }

    if (nome.size() == cognome.size())
    {
        cout << "Il numero di caratteri del nome e del cognome sono uguali" << endl;
    }

    int consNome = 0, consCognome = 0;

    for (int c = 0; c < nome.size(); c++) //Ricerca delle vocali del nome
    {
        if (nome[c] == 65 || nome[c] == 69 || nome[c] == 73 || nome[c] == 79 || nome[c] == 85 || nome[c] == 97 || nome[c] == 101 || nome[c] == 105 || nome[c] == 111 || nome[c] == 117)
        {
            consNome++;
        }
    }

    for (int c = 0; c < cognome.size(); c++) //Ricerca delle vocali del cognome
    {
        if (cognome[c] == 65 || cognome[c] == 69 || cognome[c] == 73 || cognome[c] == 79 || cognome[c] == 85 || cognome[c] == 97 || cognome[c] == 101 || cognome[c] == 105 || cognome[c] == 111 || cognome[c] == 117)
        {
            consCognome++;
        }
    }

    cout << "Consonanti del nome: " << nome.size() - consNome << endl;
    cout << "Consonanti del cognome: " << cognome.size() - consCognome << endl;
}