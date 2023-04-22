#ifndef UZYTKOWNIKMENAGER_H
#define UZYTKOWNIKMENAGER_H

#include "Uzytkownik.h"
#include "PlikZUzytkownikami.h"
#include "MetodyPomocnicze.h"
#include "AdresatMenager.h"

#include <iostream>
#include <vector>
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

    UzytkownikMenager(string nazwaPlikuZUzytkownikami) : plikZUzytkownikami(nazwaPlikuZUzytkownikami) {};
    void rejestracjaUzytkownika();
    void logowanieUzytkownika();
    void wypiszWszystkichUzytkownikow();
    void wczytajUzytkownikowZPliku();
    void zmianaHaslaZalogowanegoUzytkownika();
    void zapiszWszystkichUzytkownikowDoPliku(vector <Uzytkownik> uzytkownicy);
    void ustawIdZalogowanegoUzytkownika(int aktualneId);
    void wylogujUzytkownika();
    int pobierzIdZalogowanegoUzytkownika();
};

#endif
