#include <iostream>
#include <vector>
#include "ksiazkaAdresowa.h"

using namespace std;

int main()
{
    KsiazkaAdresowa ksiazkaAdresowa("Uzytkownicy.txt", "Adresaci.txt");
    ksiazkaAdresowa.wyswietlMenuGlowne();

    return 0;
}


