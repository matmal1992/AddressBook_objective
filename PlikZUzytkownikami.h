#include <iostream>
#include <vector>
#include "Uzytkownik.h"
#include <fstream>
#include <sstream>

using namespace std;

class PlikZUzytkownikami
{
private:
    string nazwaPlikuZUzytkownikami{};
    fstream plikTekstowy;

    bool czyPlikJestPusty();
    string zamienDaneUzytkownikaNaLinieZDanymiOddzielonaPionowymiKreskami(Uzytkownik uzytkownik);

public:
    void dopiszUzytkownikaDoPliku(Uzytkownik uzytkownik);
    PlikZUzytkownikami();


};
