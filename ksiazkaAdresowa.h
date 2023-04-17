#include <iostream>
#include "UzytkownikMenager.h"

#ifndef KSIAZKAADRESOWA_H
#define KSIAZKAADRESOWA_H

using namespace std;

class KsiazkaAdresowa
{
    private:
        UzytkownikMenager uzytkownikMenager;


    public:
        KsiazkaAdresowa(string nazwaPlikuZUzytkownikami) : uzytkownikMenager(nazwaPlikuZUzytkownikami)
        {
            uzytkownikMenager.wczytajUzytkownikowZPliku();
        }

        void rejestracjaUzytkownika();
        void wypiszWszystkichUzytkownikow();
        int logowanieUzytkownika();

};

#endif
