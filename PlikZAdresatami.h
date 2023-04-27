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
    //const string NAZWA_PLIKU_Z_ADRESATAMI;
    const string NAZWA_PLIKU_TYMCZASOWEGO;
    const int ID_ZALOGOWANEGO_UZYTKOWNIKA;
    int idOstatniegoAdresata;

    string zamienDaneAdresataNaLinieZDanymiOddzielonymiPionowymiKreskami(Adresat adresat);
    Adresat pobierzDaneAdresata(string daneAdresataOddzielonePionowymiKreskami);
    void ustawIdZalogowanegoUzytkownika(int id);
    string pobierzNazwePlikuZAdresatami();
    string pobierzNazwePlikuTymczasowego();

    void usunPlik(string nazwaPlikuZRozszerzeniem);
    void zmienNazwePliku(string staraNazwa, string nowaNazwa);

public:
    PlikZAdresatami(string nazwaPliku, int idZalogowanegoUzytkownika)
    : PlikTekstowy(nazwaPliku), ID_ZALOGOWANEGO_UZYTKOWNIKA(idZalogowanegoUzytkownika), NAZWA_PLIKU_TYMCZASOWEGO("PlikTymczasowy.txt")
    {
        idOstatniegoAdresata = 0;
    };

    vector <Adresat> wczytajAdresatowZalogowanegoUzytkownikaZPliku();
    int pobierzIdOstatniegoAdresata();
    bool dopiszAdresataDoPliku(Adresat adresat);
    void ustawIdOstatniegoAdresata(int id);
    void usunWybranaLinieWPliku(int numerUsuwanejLinii);
    void edytujWybranaLinieWPliku(int idEdytowanegoAdresata, string liniaZDanymiAdresataOddzielonePionowymiKreskami);
};

#endif
