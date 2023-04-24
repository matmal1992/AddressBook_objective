#include "ksiazkaAdresowa.h"
#include "UzytkownikMenager.h"

void KsiazkaAdresowa::rejestracjaUzytkownika()
{
    uzytkownikMenager.rejestracjaUzytkownika();
}

void KsiazkaAdresowa::logowanieUzytkownika()
{
    uzytkownikMenager.logowanieUzytkownika();
    adresatMenager.wczytajAdresatowZalogowanegoUzytkownikaZPliku(uzytkownikMenager.pobierzIdZalogowanegoUzytkownika());

    while(uzytkownikMenager.pobierzIdZalogowanegoUzytkownika() != 0)
    {
        switch (wybierzOpcjeZMenuUzytkownika())
        {
        case '1':
            dodajAdresata();
            break;
        case '2':
            //wyszukajAdresatowPoImieniu(adresaci);
            break;
        case '3':
            //wyszukajAdresatowPoNazwisku(adresaci);
            break;
        case '4':
            adresatMenager.wyswietlWszystkichAdresatow();
            break;
        case '5':
            //idUsunietegoAdresata = usunAdresata(adresaci);
            //idOstatniegoAdresata = podajIdOstatniegoAdresataPoUsunieciuWybranegoAdresata(idUsunietegoAdresata, idOstatniegoAdresata);
            break;
        case '6':
            //edytujAdresata(adresaci);
            break;
        case '7':
            zmianaHaslaZalogowanegoUzytkownika();
            break;
        case '8':
            uzytkownikMenager.wylogujUzytkownika();
            adresatMenager.wylogujUzytkownika();
            break;
        default:
            cout << "Wprowadzono bledne dane!" << endl;
        }
    }
}

void KsiazkaAdresowa::zmianaHaslaZalogowanegoUzytkownika()
{
    uzytkownikMenager.zmianaHaslaZalogowanegoUzytkownika();
}

void KsiazkaAdresowa::dodajAdresata()
{
    adresatMenager.dodajAdresata(uzytkownikMenager.pobierzIdZalogowanegoUzytkownika());
}

char KsiazkaAdresowa::wybierzOpcjeZMenuUzytkownika()
{
    char wybor;

    system("cls");
    cout << " >>> MENU UZYTKOWNIKA <<<" << endl;
    cout << "---------------------------" << endl;
    cout << "1. Dodaj adresata" << endl;
    cout << "2. Wyszukaj po imieniu" << endl;
    cout << "3. Wyszukaj po nazwisku" << endl;
    cout << "4. Wyswietl adresatow" << endl;
    cout << "5. Usun adresata" << endl;
    cout << "6. Edytuj adresata" << endl;
    cout << "---------------------------" << endl;
    cout << "7. Zmien haslo" << endl;
    cout << "8. Wyloguj sie" << endl;
    cout << "---------------------------" << endl;
    cout << "Twoj wybor: ";
    wybor = MetodyPomocnicze::wczytajZnak();

    return wybor;
}

char KsiazkaAdresowa::wybierzOpcjeZMenuGlownego()
{
    char wybor;

    system("cls");
    cout << "    >>> MENU  GLOWNE <<<" << endl;
    cout << "---------------------------" << endl;
    cout << "1. Rejestracja" << endl;
    cout << "2. Logowanie" << endl;
    cout << "9. Koniec programu" << endl;
    cout << "---------------------------" << endl;
    cout << "Twoj wybor: ";
    wybor = MetodyPomocnicze::wczytajZnak();

    return wybor;
}

void KsiazkaAdresowa::wyswietlMenuGlowne()
{
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
