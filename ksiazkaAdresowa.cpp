#include "ksiazkaAdresowa.h"
#include "UzytkownikMenager.h"

void KsiazkaAdresowa::rejestracjaUzytkownika()
{
    uzytkownikMenager.rejestracjaUzytkownika();
}

void KsiazkaAdresowa::wypiszWszystkichUzytkownikow()
{
    uzytkownikMenager.wypiszWszystkichUzytkownikow();
}

int KsiazkaAdresowa::logowanieUzytkownika()
{
    uzytkownikMenager.logowanieUzytkownika();
}
