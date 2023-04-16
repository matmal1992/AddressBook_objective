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
    string nazwaPlikuZUzytkownikami{};
    fstream plikTekstowy;

    bool czyPlikJestPusty();
    string zamienDaneUzytkownikaNaLinieZDanymiOddzielonaPionowymiKreskami(Uzytkownik uzytkownik);

public:
    void dopiszUzytkownikaDoPliku(Uzytkownik uzytkownik);
    vector <Uzytkownik> wczytajUzytkownikowZPliku();
    Uzytkownik pobierzDaneUzytkownika(string daneJednegoUzytkownikaOddzielonePionowymiKreskami);
    PlikZUzytkownikami();


};

#endif
