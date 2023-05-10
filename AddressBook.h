#ifndef ADDRESSBOOK_H
#define ADDRESSBOOK_H

#include <iostream>
#include "UserManager.h"
#include "AddresseeManager.h"

using namespace std;

class AddressBook
{
    UserManager userManager;
    AddresseeManager *addresseeManager;
    const string FILE_NAME_WITH_ADDRESSEES;

public:
    AddressBook(string fileNameWithUsers, string fileNameWithAddressees)
    : userManager(fileNameWithUsers), FILE_NAME_WITH_ADDRESSEES(fileNameWithAddressees)
    {
        addresseeManager = NULL;
    }

    ~AddressBook()
    {
        delete addresseeManager;
        addresseeManager = NULL;
    }

    char chooseOptionFromUserMenu();
    char chooseOptionFromMainMenu();
    void goToMainMenu();
    void goToUserMenu();
};

#endif
