#include <iostream>
#include <vector>
#include "ksiazkaAdresowa.h"


using namespace std;

int main()
{
    KsiazkaAdresowa ksiazkaAdresowa("Uzytkownicy.txt");
    //ksiazkaAdresowa.rejestracjaUzytkownika();
    //ksiazkaAdresowa.wczytajUzytkownikowZPliku();
    ksiazkaAdresowa.wypiszWszystkichUzytkownikow();


    return 0;
}


