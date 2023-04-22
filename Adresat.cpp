#include "Adresat.h"

void Adresat::ustawId(int noweId) {id = noweId;}
void Adresat::ustawIdZalogowanegoUzytkownika() {idUzytkownika = 8;}
void Adresat::ustawImie(string noweImie) {imie = noweImie;}
void Adresat::ustawNazwisko(string noweNazwisko) {nazwisko = noweNazwisko;}
void Adresat::ustawAdres(string nowyAdres) {adres = nowyAdres;}
void Adresat::ustawEmail(string nowyEmail) {email = nowyEmail;}
void Adresat::ustawTelefon(string nowTelefon) {telefon = nowTelefon;}

int Adresat::pobierzId() {return id;}
int Adresat::pobierzIdUzytkownika() {return idUzytkownika;}
string Adresat::pobierzImie() {return imie;}
string Adresat::pobierzNazwisko() {return nazwisko;}
string Adresat::pobierzAdres() {return adres;}
string Adresat::pobierzEmail() {return email;}
string Adresat::pobierzTelefon() {return telefon;}
