#ifndef PLIKZADRESATAMI_H
#define PLIKZADRESATAMI_H

#include "Adresat.h"
#include "MetodyPomocnicze.h"
#include "PlikTekstowy.h"
#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>

using namespace std;

class PlikZAdresatami : public PlikTekstowy
{
    const string NAZWA_PLIKU_TYMCZASOWEGO = "PlikTymczasowy.txt";
    int idOstatniegoAdresata;

    string zamienDaneAdresataNaLinieZDanymiOddzielonymiPionowymiKreskami(Adresat adresat);
    Adresat pobierzDaneAdresata(string daneAdresataOddzielonePionowymiKreskami);
    void ustawIdZalogowanegoUzytkownika(int id);
    string pobierzNazwePlikuZAdresatami();
    string pobierzNazwePlikuTymczasowego();

    void usunPlik(string nazwaPlikuZRozszerzeniem);
    void zmienNazwePliku(string staraNazwa, string nowaNazwa);

public:
    PlikZAdresatami(string nazwaPliku): PlikTekstowy(nazwaPliku)
    {
        idOstatniegoAdresata = 0;
    };

    vector <Adresat> wczytajAdresatowZalogowanegoUzytkownikaZPliku(int idUzytkownika);
    int pobierzIdOstatniegoAdresata();
    bool dopiszAdresataDoPliku(Adresat adresat);
    void ustawIdOstatniegoAdresata(int id);
    void usunWybranaLinieWPliku(int numerUsuwanejLinii);
    void edytujWybranaLinieWPliku(string liniaZDanymiAdresataOddzielonePionowymiKreskami);
};

#endif
