#include <iostream>
#include "Uzytkownik.h"

using namespace std;

void Uzytkownik::ustawId(int id)
{
    if(id >= 0)
        this->id = id;
}

void Uzytkownik::ustawLogin(string login) {this->login = login;}
void Uzytkownik::ustawHaslo(string haslo) {this->haslo = haslo;}

int Uzytkownik::pobierzId() {return id;}
string Uzytkownik::pobierzLogin() {return login;}
string Uzytkownik::pobierzHaslo() {return haslo;}
