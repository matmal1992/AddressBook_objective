#ifndef UZYTKOWNIKMENAGER_H
#define UZYTKOWNIKMENAGER_H

#include "PlikZUzytkownikami.h"
#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>

using namespace std;

class UzytkownikMenager
{
    int idZalogowanegoUzytkownika{};
    vector <Uzytkownik> uzytkownicy{};
    PlikZUzytkownikami plikZUzytkownikami;

    Uzytkownik podajDaneNowegoUzytkownika();
    int pobierzIdNowegoUzytkownika();
    bool czyIstniejeLogin(string login);

public:
    UzytkownikMenager(string nazwaPlikuZUzytkownikami) : plikZUzytkownikami(nazwaPlikuZUzytkownikami)
    {
        idZalogowanegoUzytkownika = 0;
        uzytkownicy = plikZUzytkownikami.wczytajUzytkownikowZPliku();
    };

    void rejestracjaUzytkownika();
    void logowanieUzytkownika();
    void zmianaHaslaZalogowanegoUzytkownika();
    void zapiszWszystkichUzytkownikowDoPliku(vector <Uzytkownik> uzytkownicy);
    void ustawIdZalogowanegoUzytkownika(int aktualneId);
    void wylogujUzytkownika();
    int pobierzIdZalogowanegoUzytkownika();
    bool czyUzytkownikJestZalogowany();
};

#endif
