#ifndef ADRESATMENAGER_H
#define ADRESATMENAGER_H

#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>

#include "Adresat.h"
#include "PlikZAdresatami.h"
#include "MetodyPomocnicze.h"


using namespace std;

class AdresatMenager
{
private:
    int idOstatniegoAdresata;

    vector <Adresat> adresaci;
    PlikZAdresatami plikZAdresatami;
    int idZalogowanegoUzytkownika;

public:
    AdresatMenager();
    AdresatMenager(string nazwaPlikuZAdresatami) : plikZAdresatami(nazwaPlikuZAdresatami){};

    void dodajAdresata(int idZalogowanegoUzytkownika);
    void wyswietlWszystkichAdresatow();
    void ustawIdOstatniegoAdresata(int aktualneId);
    Adresat podajDaneNowegoAdresata(int idOstatniegoAdresata, int idZalogowanegoUzytkownika);
    void wyswietlDaneAdresata(Adresat adresat);
    void wczytajAdresatowZalogowanegoUzytkownikaZPliku(int idZalogowanegoUzytkownika);
    Adresat pobierzDaneAdresata(string daneAdresataOddzielonePionowymiKreskami);
    int pobierzIdOstatniegoAdresata();
    void wylogujUzytkownika();
};

#endif
