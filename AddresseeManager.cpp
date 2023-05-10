#include "AddresseeManager.h"

void AddresseeManager::addAddressee()
{
    Addressee addressee;
    int lastAddresseeId = fileWithAddressees.getLastAddresseeId();

    system("cls");
    cout << " >>> ADDING NEW ADDRESSEE <<<" << endl << endl;
    addressee = insertDataForNewAddressee();

    addressees.push_back(addressee);

    if(fileWithAddressees.addAddresseeToFile(addressee))
    {
        fileWithAddressees.setLastAddresseeId(lastAddresseeId + 1);
    }
    else
    {
        cout << "I cant open the file" << endl;
        system("pause");
    }
}

Addressee AddresseeManager::insertDataForNewAddressee()
{
    Addressee addressee;

    addressee.setId(fileWithAddressees.getLastAddresseeId() + 1);
    addressee.setLoggedUserId(LOGGED_USER_ID);

    cout << "Insert name: ";
    addressee.setName(AuxiliaryMethods::readLine());
    addressee.setName(AuxiliaryMethods::makeFirstLetterCapital(addressee.getName()));

    cout << "Insert surname: ";
    addressee.setSurname(AuxiliaryMethods::readLine());
    addressee.setSurname(AuxiliaryMethods::makeFirstLetterCapital(addressee.getSurname()));

    cout << "Insert phone number: ";
    addressee.setPhoneNumber(AuxiliaryMethods::readLine());

    cout << "Insert email: ";
    addressee.setEmail(AuxiliaryMethods::readLine());

    cout << "Insert address: ";
    addressee.setAddress(AuxiliaryMethods::readLine());

    return addressee;
}

void AddresseeManager::displayAllAddressees()
{
    system("cls");
    if (!addressees.empty())
    {
        cout << "             >>> ADDRESSEES <<<" << endl;
        cout << "-----------------------------------------------" << endl;
        for (vector <Addressee> :: iterator itr = addressees.begin(); itr != addressees.end(); ++itr)
        {
            displayAddresseeData(*itr);
        }
        cout << endl;
    }
    else
    {
        cout << endl << "Address book is empty." << endl << endl;
    }
    system("pause");
}

void AddresseeManager::displayAddresseeData(Addressee addressee)
{
    cout << endl << "Id:                    " << addressee.getId() << endl;
    cout << "Name:                  " << addressee.getName() << endl;
    cout << "Surname:               " << addressee.getSurname() << endl;
    cout << "Phone number:          " << addressee.getPhoneNumber() << endl;
    cout << "Email:                 " << addressee.getEmail() << endl;
    cout << "Address:               " << addressee.getAddress() << endl;
}

Addressee AddresseeManager::loadAddresseeData(string addresseeDataSeparatedByDashes)
{
    Addressee addressee;
    string singleAddresseeData{};
    int numberOfSingleAddresseeData = 1;

    for (size_t charPosition = 0; charPosition < addresseeDataSeparatedByDashes.length(); charPosition++)
    {
        if (addresseeDataSeparatedByDashes[charPosition] != '|')
        {
            singleAddresseeData += addresseeDataSeparatedByDashes[charPosition];
        }
        else
        {
            switch(numberOfSingleAddresseeData)
            {
            case 1: addressee.setId(atoi(singleAddresseeData.c_str()));
                break;
            case 2: addressee.setLoggedUserId(atoi(singleAddresseeData.c_str()));
                break;
            case 3: addressee.setName(singleAddresseeData);
                break;
            case 4: addressee.setSurname(singleAddresseeData);
                break;
            case 5: addressee.setPhoneNumber(singleAddresseeData);
                break;
            case 6: addressee.setEmail(singleAddresseeData);
                break;
            case 7: addressee.setAddress(singleAddresseeData);
                break;
            }
            singleAddresseeData = "";
            numberOfSingleAddresseeData++;
        }
    }
    return addressee;
}

void AddresseeManager::removeAddressee()
{
    int deletedAddresseeId = 0;

    system("cls");
    cout << ">>> REMOVING OF SELECTED ADDRESSEE <<<" << endl << endl;
    deletedAddresseeId = AuxiliaryMethods::insertIdOfSelectedAddressee();

    char character;
    bool ifAddresseeExists = false;

    for (vector <Addressee>::iterator itr = addressees.begin(); itr != addressees.end(); ++itr)
    {
        if (itr -> getId() == deletedAddresseeId)
        {
            ifAddresseeExists = true;
            cout << endl << "Confirm by inserting 'y': ";
            character = AuxiliaryMethods::readChar();
            if (character == 't')
            {
                fileWithAddressees.removeSelectedLineInFile(deletedAddresseeId);
                addressees.erase(itr);
                cout << endl << endl << "Selected addressee has been removed." << endl << endl;
                system("pause");
            }
            else
            {
                cout << endl << endl << "Selected addressee has not been removed" << endl << endl;
                system("pause");
                return;
            }
        }
    }
    if (!ifAddresseeExists)
    {
        cout << endl << "There is no such addressee in your address book." << endl << endl;
        system("pause");
    }
}

void AddresseeManager::editAddressee()
{
    system("cls");
    Addressee addressee;
    int editedAddresseeId = 0;
    string lineWithAddresseeData{};

    cout << ">>> EDITION OF SELECTED ADDRESSEE <<<" << endl << endl;
    editedAddresseeId = AuxiliaryMethods::insertIdOfSelectedAddressee();

    char choice;
    bool ifAddresseeExists = false;

    for (vector <Addressee>::iterator itr = addressees.begin(); itr != addressees.end(); ++itr)
    {
        if (itr -> getId() == editedAddresseeId)
        {
            ifAddresseeExists = true;
            choice = chooseOptionFromEditionMenu();

            switch (choice)
            {
            case '1':
                cout << "Insert new name: ";
                itr -> setName(AuxiliaryMethods::readLine());
                itr -> setName(AuxiliaryMethods::makeFirstLetterCapital(itr -> getName()));
                updateDataOfSelectedAddressee(*itr);
                break;
            case '2':
                cout << "Insert new surname: ";
                itr -> setSurname(AuxiliaryMethods::readLine());
                itr -> setSurname(AuxiliaryMethods::makeFirstLetterCapital(itr -> getSurname()));
                updateDataOfSelectedAddressee(*itr);
                break;
            case '3':
                cout << "Insert new phone number: ";
                itr -> setPhoneNumber(AuxiliaryMethods::readLine());
                updateDataOfSelectedAddressee(*itr);
                break;
            case '4':
                cout << "Insert new email: ";
                itr -> setEmail(AuxiliaryMethods::readLine());
                updateDataOfSelectedAddressee(*itr);
                break;
            case '5':
                cout << "Insert new address: ";
                itr -> setAddress(AuxiliaryMethods::readLine());
                updateDataOfSelectedAddressee(*itr);
                break;
            case '6':
                cout << endl << "Go to user menu" << endl << endl;
                break;
            default:
                cout << endl << "There is no such option in menu! You are directed towards user menu." << endl << endl;
                break;
            }
        }
    }

    if (!ifAddresseeExists)
        cout << endl << "There is no such addressee." << endl << endl;

    system("pause");
}

char AddresseeManager::chooseOptionFromEditionMenu()
{
    char choice;

    cout << endl << "   >>> EDITION MENU <<<" << endl;
    cout << "---------------------------" << endl;
    cout << "Choose data to change: " << endl;
    cout << "1 - Name" << endl;
    cout << "2 - Surname" << endl;
    cout << "3 - Phone number" << endl;
    cout << "4 - Email" << endl;
    cout << "5 - Address" << endl;
    cout << "6 - Back to previous menu " << endl;
    cout << endl << "Your choice: ";
    choice = AuxiliaryMethods::readChar();

    return choice;
}

void AddresseeManager::updateDataOfSelectedAddressee(Addressee adresat)
{
    string lineWithAddresseeData{};

    lineWithAddresseeData = fileWithAddressees.turnAddresseeDataIntoDataSeparatedByDashes(adresat);
    fileWithAddressees.editSelectedLineInFile(lineWithAddresseeData);

    cout << endl << "Data has been updated." << endl << endl;
}

void AddresseeManager::findAddresseesByName()
{
    string nameOfSearchedAddressee{};
    int amountOfAddressees = 0;

    system("cls");
    if (!addressees.empty())
    {
        cout << ">>> SEARCHING ADDRESSEES BY NAME <<<" << endl << endl;

        cout << "Insert name of searched addressees: ";
        nameOfSearchedAddressee = AuxiliaryMethods::readLine();
        nameOfSearchedAddressee = AuxiliaryMethods::makeFirstLetterCapital(nameOfSearchedAddressee);

        for (vector <Addressee>::iterator  itr = addressees.begin(); itr != addressees.end(); ++itr)
        {
            if (itr -> getName() == nameOfSearchedAddressee)
            {
                displayAddresseeData(*itr);
                amountOfAddressees++;
            }
        }
        AuxiliaryMethods::displayAmountOfFoundAddressees(amountOfAddressees);
    }
    else
    {
        cout << endl << "The address book is empty." << endl << endl;
    }
    cout << endl;
    system("pause");
}

void AddresseeManager::findAddresseesBySurname()
{
    string surnameOfSearchedAddressee{};
    int amountOfAddressees = 0;

    system("cls");
    if (!addressees.empty())
    {
        cout << ">>> SEARCHING ADDRESSEES BY SURNAME <<<" << endl << endl;

        cout << "Insert surname of searched addressees: ";
        surnameOfSearchedAddressee = AuxiliaryMethods::readLine();
        surnameOfSearchedAddressee = AuxiliaryMethods::makeFirstLetterCapital(surnameOfSearchedAddressee);

        for (vector <Addressee>::iterator itr = addressees.begin(); itr != addressees.end(); ++itr)
        {
            if (itr -> getSurname() == surnameOfSearchedAddressee)
            {
                displayAddresseeData(*itr);
                amountOfAddressees++;
            }
        }
         AuxiliaryMethods::displayAmountOfFoundAddressees(amountOfAddressees);
    }
    else
    {
        cout << endl << "The address book is empty." << endl << endl;
    }
    cout << endl;
    system("pause");
}
