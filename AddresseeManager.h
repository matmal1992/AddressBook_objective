#ifndef ADDRESSEEMANAGER_H
#define ADDRESSEEMANAGER_H

#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include "FileWithAddressees.h"

using namespace std;

class AddresseeManager
{
    vector <Addressee> addressees;
    FileWithAddressees fileWithAddressees;
    const int LOGGED_USER_ID;

    char chooseOptionFromEditionMenu();
    void displayAddresseeData(Addressee addressee);
    void updateDataOfSelectedAddressee(Addressee addressee);
    Addressee insertDataForNewAddressee();
    Addressee loadAddresseeData(string addresseeDataSeparatedByDashes);

public:
    AddresseeManager(string fileNameWithAddressees, int loggedUserId)
    : fileWithAddressees(fileNameWithAddressees), LOGGED_USER_ID(loggedUserId)
    {
        addressees = fileWithAddressees.loadAddresseesOfLoggedUserFromFile(LOGGED_USER_ID);
    };

    void addAddressee();
    void findAddresseesByName();
    void findAddresseesBySurname();
    void displayAllAddressees();
    void editAddressee();
    void removeAddressee();
};

#endif
