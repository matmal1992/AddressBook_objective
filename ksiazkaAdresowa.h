#include <iostream>
#include <vector>
#include "Uzytkownik.h"
#include <fstream>
#include <sstream>

using namespace std;

class KsiazkaAdresowa
{
    private:
        int idZalogowanegoUzytkownika{};
        int idOstatniegoAdresata{};
        int idUsunietegoAdresata{};
        vector <Uzytkownik> uzytkownicy{};
        string nazwaPlikuZUzytkownikami{};

        Uzytkownik podajDaneNowegoUzytkownika();
        int pobierzIdNowegoUzytkownika();
        bool czyIstniejeLogin(string login);
        void dopiszUzytkownikaDoPliku(Uzytkownik uzytkownik);
        string zamienDaneUzytkownikaNaLinieZDanymiOddzielonaPionowymiKreskami(Uzytkownik uzytkownik);
        string konwerjsaIntNaString(int liczba);
        bool czyPlikJestPusty(fstream &plikTekstowy);


    public:
        KsiazkaAdresowa();
        void rejestracjaUzytkownika();
        int logowanieUzytkownika();
        void wypiszWszystkichUzytkownikow();
};
