#ifndef PLIKZADRESATAMI_H
#define PLIKZADRESATAMI_H

#include "Adresat.h"

#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>

using namespace std;

class PlikZAdresatami
{
private:
    const string nazwaPlikuZAdresatami;
    bool czyPlikJestPusty();

public:
    PlikZAdresatami(string nazwaPliku) : nazwaPlikuZAdresatami(nazwaPliku){};
    void dopiszAdresataDoPliku(Adresat adresat);
    string zamienDaneAdresataNaLinieZDanymiOddzielonymiPionowymiKreskami(Adresat adresat);
    int wczytajAdresatowZalogowanegoUzytkownikaZPliku(vector <Adresat> &adresaci, int idZalogowanegoUzytkownika);
    Adresat pobierzDaneAdresata(string daneAdresataOddzielonePionowymiKreskami);
    string pobierzNazwePlikuZAdresatami();
};

#endif
