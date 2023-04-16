#include <iostream>
#include <vector>
#include "ksiazkaAdresowa.h"


using namespace std;

int main()
{
    KsiazkaAdresowa ksiazkaAdresowa;
    ksiazkaAdresowa.rejestracjaUzytkownika();
    //ksiazkaAdresowa.wczytajUzytkownikowZPliku();
    ksiazkaAdresowa.wypiszWszystkichUzytkownikow();


    return 0;
}


