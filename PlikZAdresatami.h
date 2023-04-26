#ifndef PLIKZADRESATAMI_H
#define PLIKZADRESATAMI_H

#include "Adresat.h"
#include "MetodyPomocnicze.h"
#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>

using namespace std;

class PlikZAdresatami
{
    const string NAZWA_PLIKU_Z_ADRESATAMI;
    const string NAZWA_PLIKU_TYMCZASOWEGO;
    const int ID_ZALOGOWANEGO_UZYTKOWNIKA;
    int idOstatniegoAdresata;

    bool czyPlikJestPusty();

public:
    PlikZAdresatami(string nazwaPliku, int idZalogowanegoUzytkownika)
    : NAZWA_PLIKU_Z_ADRESATAMI(nazwaPliku), ID_ZALOGOWANEGO_UZYTKOWNIKA(idZalogowanegoUzytkownika), NAZWA_PLIKU_TYMCZASOWEGO("PlikTymczasowy.txt")
    {
        idOstatniegoAdresata = 0;
    };

    bool dopiszAdresataDoPliku(Adresat adresat);
    string zamienDaneAdresataNaLinieZDanymiOddzielonymiPionowymiKreskami(Adresat adresat);
    Adresat pobierzDaneAdresata(string daneAdresataOddzielonePionowymiKreskami);
    vector <Adresat> wczytajAdresatowZalogowanegoUzytkownikaZPliku();

    void ustawIdZalogowanegoUzytkownika(int id);
    void ustawIdOstatniegoAdresata(int id);
    int pobierzIdOstatniegoAdresata();
    string pobierzNazwePlikuZAdresatami();
    string pobierzNazwePlikuTymczasowego();
};

#endif
