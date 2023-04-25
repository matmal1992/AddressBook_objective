#ifndef PLIKZUZYTKOWNIKAMI_H
#define PLIKZUZYTKOWNIKAMI_H

#include "MetodyPomocnicze.h"
#include "Uzytkownik.h"
#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>

using namespace std;

class PlikZUzytkownikami
{
    const string NAZWA_PLIKU_Z_UZYTKOWNIKAMI{};
    bool czyPlikJestPusty();
    string zamienDaneUzytkownikaNaLinieZDanymiOddzielonaPionowymiKreskami(Uzytkownik uzytkownik);

public:
    PlikZUzytkownikami(string nazwaPliku) : NAZWA_PLIKU_Z_UZYTKOWNIKAMI(nazwaPliku){};
    void dopiszUzytkownikaDoPliku(Uzytkownik uzytkownik);
    vector <Uzytkownik> wczytajUzytkownikowZPliku();
    Uzytkownik pobierzDaneUzytkownika(string daneJednegoUzytkownikaOddzielonePionowymiKreskami);
    void zapiszWszystkichUzytkownikowDoPliku(vector <Uzytkownik> uzytkownicy);
};

#endif
