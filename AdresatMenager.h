#ifndef ADRESATMENAGER_H
#define ADRESATMENAGER_H

#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include "PlikZAdresatami.h"

using namespace std;

class AdresatMenager
{
    int idOstatniegoAdresata;
    vector <Adresat> adresaci;
    PlikZAdresatami plikZAdresatami;
    int idZalogowanegoUzytkownika;

public:
    AdresatMenager();
    AdresatMenager(string nazwaPlikuZAdresatami) : plikZAdresatami(nazwaPlikuZAdresatami){};

    void dodajAdresata();
    void wyswietlWszystkichAdresatow();
    void wylogujUzytkownika();
    Adresat podajDaneNowegoAdresata();
    Adresat pobierzDaneAdresata(string daneAdresataOddzielonePionowymiKreskami);
    void wyswietlDaneAdresata(Adresat adresat);
    void wczytajAdresatowZalogowanegoUzytkownikaZPliku();
    int pobierzIdOstatniegoAdresata();
    void ustawIdOstatniegoAdresata(int aktualneId);
    void ustawIdZalogowanegoUzytkownika(int aktualneId);

};

#endif
