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
    int idOstatniegoAdresata{};
    int idZalogowanegoUzytkownika{};
    vector <Adresat> adresaci{};
    PlikZAdresatami plikZAdresatami;

public:
    AdresatMenager(string nazwaPlikuZAdresatami) : plikZAdresatami(nazwaPlikuZAdresatami) {};
    void dodajAdresata();
    void wyswietlWszystkichAdresatow();
    void ustawIdOstatniegoAdresata();
    Adresat podajDaneNowegoAdresata(int idOstatniegoAdresata);
    void wyswietlDaneAdresata(Adresat adresat);

};

#endif
