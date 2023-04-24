#ifndef ADRESAT_H
#define ADRESAT_H

#include <iostream>

using namespace std;

class Adresat
{
    int id{};
    int idUzytkownika{};
    string imie{};
    string nazwisko{};
    string adres{};
    string email{};
    string telefon{};

public:
    void ustawIdZalogowanegoUzytkownika(int idZalogowanegoUzytkownika);
    void ustawId(int noweId);
    void ustawImie(string noweImie);
    void ustawNazwisko(string noweNazwisko);
    void ustawAdres(string nowyAdres);
    void ustawEmail(string nowyEmail);
    void ustawTelefon(string nowTelefon);

    int pobierzId();
    int pobierzIdUzytkownika();
    string pobierzImie();
    string pobierzNazwisko();
    string pobierzAdres();
    string pobierzEmail();
    string pobierzTelefon();
};

#endif
