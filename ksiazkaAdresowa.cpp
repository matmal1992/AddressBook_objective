#include "ksiazkaAdresowa.h"
#include "UzytkownikMenager.h"

KsiazkaAdresowa::KsiazkaAdresowa()
{
    uzytkownikMenager.wczytajUzytkownikowZPliku();
}

void KsiazkaAdresowa::rejestracjaUzytkownika()
{
    uzytkownikMenager.rejestracjaUzytkownika();
}

void KsiazkaAdresowa::wypiszWszystkichUzytkownikow()
{
    uzytkownikMenager.wypiszWszystkichUzytkownikow();
}
