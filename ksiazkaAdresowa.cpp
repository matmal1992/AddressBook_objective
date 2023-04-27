#include "ksiazkaAdresowa.h"
#include "UzytkownikMenager.h"

void KsiazkaAdresowa::rejestracjaUzytkownika()
{
    uzytkownikMenager.rejestracjaUzytkownika();
}

void KsiazkaAdresowa::logowanieUzytkownika()
{
    uzytkownikMenager.logowanieUzytkownika();

    if(uzytkownikMenager.czyUzytkownikJestZalogowany())
    {
        adresatMenager = new AdresatMenager(NAZWA_PLIKU_Z_ADRESATAMI, uzytkownikMenager.pobierzIdZalogowanegoUzytkownika());
        wyswietlMenuUzytkownika();
    }
}

void KsiazkaAdresowa::zmianaHaslaZalogowanegoUzytkownika()
{
    uzytkownikMenager.zmianaHaslaZalogowanegoUzytkownika();
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

void KsiazkaAdresowa::wyswietlMenuUzytkownika()
{
    while(uzytkownikMenager.pobierzIdZalogowanegoUzytkownika() != 0)
    {
        switch (wybierzOpcjeZMenuUzytkownika())
        {
        case '1':
            adresatMenager->dodajAdresata();
            break;
        case '2':
            adresatMenager->wyszukajAdresatowPoImieniu();
            break;
        case '3':
            adresatMenager->wyszukajAdresatowPoNazwisku();
            break;
        case '4':
            adresatMenager->wyswietlWszystkichAdresatow();
            break;
        case '5':
            adresatMenager->usunAdresata();
            break;
        case '6':
            adresatMenager->edytujAdresata();
            break;
        case '7':
            zmianaHaslaZalogowanegoUzytkownika();
            break;
        case '8':
            uzytkownikMenager.wylogujUzytkownika();
            delete adresatMenager;
            adresatMenager = NULL;
            break;
        default:
            cout << "Wprowadzono bledne dane!" << endl;
        }
    }
}
