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
    const string nazwaPlikuZAdresatami;
    bool czyPlikJestPusty();
    int idOstatniegoAdresata;
    int idZalogowanegoUzytkownika;

public:
    PlikZAdresatami(string nazwaPliku) : nazwaPlikuZAdresatami(nazwaPliku){};
    void dopiszAdresataDoPliku(Adresat adresat);
    string zamienDaneAdresataNaLinieZDanymiOddzielonymiPionowymiKreskami(Adresat adresat);
    Adresat pobierzDaneAdresata(string daneAdresataOddzielonePionowymiKreskami);
    vector <Adresat> wczytajAdresatowZalogowanegoUzytkownikaZPliku();

    void ustawIdZalogowanegoUzytkownika(int id);
    void ustawIdOstatniegoAdresata(int id);
    int pobierzIdOstatniegoAdresata();
    string pobierzNazwePlikuZAdresatami();
};

#endif
