#ifndef KSIAZKAADRESOWA_H
#define KSIAZKAADRESOWA_H

#include <iostream>

#include "UzytkownikMenager.h"
#include "AdresatMenager.h"

using namespace std;

class KsiazkaAdresowa
{
    private:
        UzytkownikMenager uzytkownikMenager;
        AdresatMenager adresatMenager;

    public:
        KsiazkaAdresowa(string nazwaPlikuZUzytkownikami, string nazwaPlikuZAdresatami) : uzytkownikMenager(nazwaPlikuZUzytkownikami), adresatMenager(nazwaPlikuZAdresatami)
        {
            uzytkownikMenager.wczytajUzytkownikowZPliku();
            //wczytaj adresatow z pliku
        }

        void rejestracjaUzytkownika();
        void wypiszWszystkichUzytkownikow();
        int logowanieUzytkownika();
        void zmianaHaslaZalogowanegoUzytkownika();
        void dodajAdresata();
};

#endif
