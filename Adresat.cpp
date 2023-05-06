#include "Adresat.h"

void Adresat::ustawId(int id) {idAdresata = id;}
void Adresat::ustawIdZalogowanegoUzytkownika(int id) {idUzytkownika = id;}
void Adresat::ustawImie(string imie) {this->imie = imie;}
void Adresat::ustawNazwisko(string nazwisko) {this->nazwisko = nazwisko;}
void Adresat::ustawAdres(string adres) {this->adres = adres;}
void Adresat::ustawEmail(string email) {this->email = email;}
void Adresat::ustawTelefon(string telefon) {this->telefon = telefon;}

int Adresat::pobierzId() {return idAdresata;}
int Adresat::pobierzIdUzytkownika() {return idUzytkownika;}
string Adresat::pobierzImie() {return imie;}
string Adresat::pobierzNazwisko() {return nazwisko;}
string Adresat::pobierzAdres() {return adres;}
string Adresat::pobierzEmail() {return email;}
string Adresat::pobierzTelefon() {return telefon;}


