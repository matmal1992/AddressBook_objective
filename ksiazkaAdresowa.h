#ifndef KSIAZKAADRESOWA_H
#define KSIAZKAADRESOWA_H

#include <iostream>
#include "UzytkownikMenager.h"

using namespace std;

class KsiazkaAdresowa
{
    private:
        UzytkownikMenager uzytkownikMenager;


    public:
        void rejestracjaUzytkownika();
        void wypiszWszystkichUzytkownikow();

};

#endif
