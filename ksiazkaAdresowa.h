#include <iostream>
#include <vector>
#include "Uzytkownik.h"

using namespace std;

class KsiazkaAdresowa
{
    private:
        int idZalogowanegoUzytkownika{};
        int idOstatniegoAdresata{};
        int idUsunietegoAdresata{};
        vector <Uzytkownik> uzytkownicy{};

        Uzytkownik podajDaneNowegoUzytkownika();
        int pobierzIdNowegoUzytkownika();
        bool czyIstniejeLogin(string login);

    public:
        void rejestracjaUzytkownika();
        int logowanieUzytkownika();
        void wypiszWszystkichUzytkownikow();
};
