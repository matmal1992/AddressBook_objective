#ifndef ADRESAT_H
#define ADRESAT_H

#include <iostream>

using namespace std;

class Adresat
{
    int id;
    int idUzytkownika;
    string imie;
    string nazwisko;
    string adres;
    string email;
    string telefon;

public:
    void ustawIdZalogowanegoUzytkownika(int idZalogowanegoUzytkownika);
    void ustawId(int id);
    void ustawImie(string imie);
    void ustawNazwisko(string nazwisko);
    void ustawAdres(string adres);
    void ustawEmail(string email);
    void ustawTelefon(string telefon);

    int pobierzId();
    int pobierzIdUzytkownika();
    string pobierzImie();
    string pobierzNazwisko();
    string pobierzAdres();
    string pobierzEmail();
    string pobierzTelefon();
};

#endif
