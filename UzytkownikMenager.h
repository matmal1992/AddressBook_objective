

#include <iostream>
#include <vector>
#include "Uzytkownik.h"
#include "PlikZUzytkownikami.h"
#include "MetodyPomocnicze.h"
#include <fstream>
#include <sstream>

#ifndef UZYTKOWNIKMENAGER_H
#define UZYTKOWNIKMENAGER_H

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
    string wczytajLinie();
    void zmianaHaslaZalogowanegoUzytkownika();
    void zapiszWszystkichUzytkownikowDoPliku(vector <Uzytkownik> uzytkownicy);
    void ustawIdZalogowanegoUzytkownika(int aktualneId);
};

#endif
