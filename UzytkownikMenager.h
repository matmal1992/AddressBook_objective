#ifndef UZYTKOWNIKMENAGER_H
#define UZYTKOWNIKMENAGER_H

#include <iostream>
#include <vector>
#include "Uzytkownik.h"
#include "PlikZUzytkownikami.h"
#include <fstream>
#include <sstream>

using namespace std;

class UzytkownikMenager
{
private:
    int idZalogowanegoUzytkownika{};
    vector <Uzytkownik> uzytkownicy{};
    PlikZUzytkownikami plikZUzytkownikami;

    Uzytkownik podajDaneNowegoUzytkownika();
    int pobierzIdNowegoUzytkownika();
    bool czyIstniejeLogin(string login);


public:
    void rejestracjaUzytkownika();
    int logowanieUzytkownika();
    void wypiszWszystkichUzytkownikow();
};

#endif
