#ifndef KSIAZKAADRESOWA_H
#define KSIAZKAADRESOWA_H

#include <iostream>
#include "UzytkownikMenager.h"
#include "AdresatMenager.h"

using namespace std;

class KsiazkaAdresowa
{
    private:
        UzytkownikMenager uzytkownikMenager;
        AdresatMenager adresatMenager;

    public:
        KsiazkaAdresowa(string nazwaPlikuZUzytkownikami, string nazwaPlikuZAdresatami)
        : uzytkownikMenager(nazwaPlikuZUzytkownikami), adresatMenager(nazwaPlikuZAdresatami)
        {
            uzytkownikMenager.wczytajUzytkownikowZPliku();

            while (true)
            {
                if (uzytkownikMenager.pobierzIdZalogowanegoUzytkownika() == 0)
                {
                    switch (wybierzOpcjeZMenuGlownego())
                    {
                    case '1': rejestracjaUzytkownika(); break;
                    case '2': logowanieUzytkownika(); break;
                    case '9': exit(0); break;
                    default:
                        cout << endl << "Nie ma takiej opcji w menu." << endl << endl;
                        system("pause");
                        break;
                    }
                }
            }
        }

        void rejestracjaUzytkownika();
        void logowanieUzytkownika();
        void zmianaHaslaZalogowanegoUzytkownika();
        void dodajAdresata();
        char wybierzOpcjeZMenuUzytkownika();
        char wybierzOpcjeZMenuGlownego();
};

#endif
