#include <iostream>
#include <vector>
#include "Uzytkownik.h"
#include <fstream>
#include <sstream>

#ifndef PLIKZUZYTKOWNIKAMI_H
#define PLIKZUZYTKOWNIKAMI_H

using namespace std;

class PlikZUzytkownikami
{
private:
    const string nazwaPlikuZUzytkownikami{};
    bool czyPlikJestPusty();
    string zamienDaneUzytkownikaNaLinieZDanymiOddzielonaPionowymiKreskami(Uzytkownik uzytkownik);

public:
    void dopiszUzytkownikaDoPliku(Uzytkownik uzytkownik);
    vector <Uzytkownik> wczytajUzytkownikowZPliku();
    Uzytkownik pobierzDaneUzytkownika(string daneJednegoUzytkownikaOddzielonePionowymiKreskami);
    PlikZUzytkownikami(string nazwaPliku) : nazwaPlikuZUzytkownikami(nazwaPliku){};
    void zapiszWszystkichUzytkownikowDoPliku(vector <Uzytkownik> uzytkownicy);



};

#endif
