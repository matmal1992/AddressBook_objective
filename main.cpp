#include <iostream>
#include <vector>
#include "AddressBook.h"

using namespace std;

int main()
{
    AddressBook addressBook("Users.txt", "Addressees.txt");
    addressBook.goToMainMenu();

    return 0;
}


