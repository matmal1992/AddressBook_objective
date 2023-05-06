#include "PlikZAdresatami.h"

bool PlikZAdresatami::dopiszAdresataDoPliku(Adresat adresat)
{
    string liniaZDanymiAdresata{};
    fstream plikTekstowy;
    plikTekstowy.open(pobierzNazwePliku().c_str(), ios::out | ios::app);

    if (plikTekstowy.good())
    {
        liniaZDanymiAdresata = zamienDaneAdresataNaLinieZDanymiOddzielonymiPionowymiKreskami(adresat);

        if (czyPlikJestPusty(plikTekstowy))
            plikTekstowy << liniaZDanymiAdresata;
        else
            plikTekstowy << endl << liniaZDanymiAdresata ;

        plikTekstowy.close();
        return true;
    }
    else
        return false;
}

string PlikZAdresatami::zamienDaneAdresataNaLinieZDanymiOddzielonymiPionowymiKreskami(Adresat adresat)
{
    string liniaZDanymiAdresata{};

    liniaZDanymiAdresata.append(MetodyPomocnicze::konwerjsaIntNaString(adresat.pobierzId()) + '|');
    liniaZDanymiAdresata.append(MetodyPomocnicze::konwerjsaIntNaString(adresat.pobierzIdUzytkownika()) + '|');
    liniaZDanymiAdresata.append(adresat.pobierzImie() + '|');
    liniaZDanymiAdresata.append(adresat.pobierzNazwisko() + '|');
    liniaZDanymiAdresata.append(adresat.pobierzTelefon() + '|');
    liniaZDanymiAdresata.append(adresat.pobierzEmail() + '|');
    liniaZDanymiAdresata.append(adresat.pobierzAdres() + '|');

    return liniaZDanymiAdresata;
}

Adresat PlikZAdresatami::pobierzDaneAdresata(string daneAdresataOddzielonePionowymiKreskami)
{
    Adresat adresat;
    string pojedynczaDanaAdresata{};
    int numerPojedynczejDanejAdresata = 1;

    for (size_t pozycjaZnaku = 0; pozycjaZnaku < daneAdresataOddzielonePionowymiKreskami.length(); ++pozycjaZnaku)
    {
        if (daneAdresataOddzielonePionowymiKreskami[pozycjaZnaku] != '|')
        {
            pojedynczaDanaAdresata += daneAdresataOddzielonePionowymiKreskami[pozycjaZnaku];
        }
        else
        {
            switch(numerPojedynczejDanejAdresata)
            {
            case 1: adresat.ustawId(atoi(pojedynczaDanaAdresata.c_str()));
                break;
            case 2: adresat.ustawIdZalogowanegoUzytkownika(atoi(pojedynczaDanaAdresata.c_str()));
                break;
            case 3: adresat.ustawImie(pojedynczaDanaAdresata);
                break;
            case 4: adresat.ustawNazwisko(pojedynczaDanaAdresata);
                break;
            case 5: adresat.ustawTelefon(pojedynczaDanaAdresata);
                break;
            case 6: adresat.ustawEmail(pojedynczaDanaAdresata);
                break;
            case 7: adresat.ustawAdres(pojedynczaDanaAdresata);
                break;
            }
            pojedynczaDanaAdresata = "";
            numerPojedynczejDanejAdresata++;
        }
    }
    return adresat;
}

string PlikZAdresatami::pobierzNazwePlikuZAdresatami()
{
    return PlikTekstowy::pobierzNazwePliku();
}

vector <Adresat> PlikZAdresatami::wczytajAdresatowZalogowanegoUzytkownikaZPliku(int idUzytkownika)
{
    Adresat adresat;
    vector <Adresat> adresaci;
    int idOstatniegoAdresata;
    string daneJednegoAdresataOddzielonePionowymiKreskami{};
    string daneOstaniegoAdresataWPliku{};
    fstream plikTekstowy;
    plikTekstowy.open(PlikTekstowy::pobierzNazwePliku().c_str(), ios::in);

    if (plikTekstowy.good())
    {
        while (getline(plikTekstowy, daneJednegoAdresataOddzielonePionowymiKreskami))
        {
            if(idUzytkownika == MetodyPomocnicze::pobierzIdUzytkownikaZDanychOddzielonychPionowymiKreskami(daneJednegoAdresataOddzielonePionowymiKreskami))
            {
                adresat = pobierzDaneAdresata(daneJednegoAdresataOddzielonePionowymiKreskami);
                adresaci.push_back(adresat);
            }
        }
        daneOstaniegoAdresataWPliku = daneJednegoAdresataOddzielonePionowymiKreskami;
    }
    else
        cout << "Nie udalo sie otworzyc pliku i wczytac danych." << endl;

    plikTekstowy.close();

    if (daneOstaniegoAdresataWPliku != "")
    {
        idOstatniegoAdresata = MetodyPomocnicze::pobierzIdAdresataZDanychOddzielonychPionowymiKreskami(daneOstaniegoAdresataWPliku);
        ustawIdOstatniegoAdresata(idOstatniegoAdresata);
    }

    return adresaci;
}

void PlikZAdresatami::ustawIdOstatniegoAdresata(int id)
{
    idOstatniegoAdresata = id;
}

int PlikZAdresatami::pobierzIdOstatniegoAdresata()
{
    return idOstatniegoAdresata;
}

string PlikZAdresatami::pobierzNazwePlikuTymczasowego()
{
    return NAZWA_PLIKU_TYMCZASOWEGO;
}

void PlikZAdresatami::usunWybranaLinieWPliku(int idAdresata)
{
    fstream odczytywanyPlikTekstowy, tymczasowyPlikTekstowy;
    string wczytanaLinia{};
    int idZLinii{};

    odczytywanyPlikTekstowy.open(pobierzNazwePlikuZAdresatami().c_str(), ios::in);
    tymczasowyPlikTekstowy.open(pobierzNazwePlikuTymczasowego().c_str(), ios::out | ios::app);

    if (odczytywanyPlikTekstowy.good() && idAdresata != 0)
    {
        while (getline(odczytywanyPlikTekstowy, wczytanaLinia))
        {
            idZLinii = MetodyPomocnicze::pobierzIdAdresataZDanychOddzielonychPionowymiKreskami(wczytanaLinia);

            if (idZLinii == idAdresata) {}
            else
                {
                    if(PlikTekstowy::czyPlikJestPusty(tymczasowyPlikTekstowy))
                        tymczasowyPlikTekstowy << wczytanaLinia;
                    else
                        tymczasowyPlikTekstowy << endl << wczytanaLinia;
                }
        }
        odczytywanyPlikTekstowy.close();
        tymczasowyPlikTekstowy.close();

        usunPlik(pobierzNazwePlikuZAdresatami());
        zmienNazwePliku(pobierzNazwePlikuTymczasowego(), pobierzNazwePlikuZAdresatami());
    }
}

void PlikZAdresatami::usunPlik(string nazwaPlikuZRozszerzeniem)
{
    if (remove(nazwaPlikuZRozszerzeniem.c_str()) == 0) {}
    else
        cout << "Nie udalo sie usunac pliku " << nazwaPlikuZRozszerzeniem << endl;
}

void PlikZAdresatami::zmienNazwePliku(string staraNazwa, string nowaNazwa)
{
    if (rename(staraNazwa.c_str(), nowaNazwa.c_str()) == 0) {}
    else
        cout << "Nazwa pliku nie zostala zmieniona." << staraNazwa << endl;
}

void PlikZAdresatami::edytujWybranaLinieWPliku(string liniaZDanymiAdresataOddzielonePionowymiKreskami)
{
    fstream odczytywanyPlikTekstowy, tymczasowyPlikTekstowy;
    string wczytanaLinia{};
    int idZLinii{};
    int idEdytowanegoAdresata = MetodyPomocnicze::pobierzIdAdresataZDanychOddzielonychPionowymiKreskami(liniaZDanymiAdresataOddzielonePionowymiKreskami);

    odczytywanyPlikTekstowy.open(pobierzNazwePlikuZAdresatami().c_str(), ios::in);
    tymczasowyPlikTekstowy.open(pobierzNazwePlikuTymczasowego().c_str(), ios::out | ios::app);

    if (odczytywanyPlikTekstowy.good())
    {
        while (getline(odczytywanyPlikTekstowy, wczytanaLinia))
        {
            idZLinii = MetodyPomocnicze::pobierzIdAdresataZDanychOddzielonychPionowymiKreskami(wczytanaLinia);

            if (idZLinii == idEdytowanegoAdresata)
                tymczasowyPlikTekstowy <<  endl <<liniaZDanymiAdresataOddzielonePionowymiKreskami;
            else
            {
                if(PlikTekstowy::czyPlikJestPusty(tymczasowyPlikTekstowy))
                    tymczasowyPlikTekstowy << wczytanaLinia;
                else
                    tymczasowyPlikTekstowy << endl << wczytanaLinia;
            }
        }
        odczytywanyPlikTekstowy.close();
        tymczasowyPlikTekstowy.close();

        usunPlik(pobierzNazwePlikuZAdresatami());
        zmienNazwePliku(pobierzNazwePlikuTymczasowego(), pobierzNazwePlikuZAdresatami());
    }
}
