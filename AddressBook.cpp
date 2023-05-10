#include "AddressBook.h"
#include "UserManager.h"

char AddressBook::chooseOptionFromMainMenu()
{
    char choice;

    system("cls");
    cout << "    >>> MAIN MENU <<<" << endl;
    cout << "---------------------------" << endl;
    cout << "1. Register user" << endl;
    cout << "2. Log in" << endl;
    cout << "9. Exit" << endl;
    cout << "---------------------------" << endl;
    cout << "Your choice: ";
    choice = AuxiliaryMethods::readChar();

    return choice;
}

void AddressBook::goToMainMenu()
{
    while (true)
    {
        if (userManager.getLoggedUserId() == 0)
        {
            switch (chooseOptionFromMainMenu())
            {
            case '1': userManager.registerUser();
                break;
            case '2':
                userManager.logInUser();

                if(userManager.checkIfUserIsLogged())
                {
                    addresseeManager = new AddresseeManager(FILE_NAME_WITH_ADDRESSEES, userManager.getLoggedUserId());
                    goToUserMenu();
                }
                break;
            case '9':
                exit(0); break;
            default:
                cout << endl << "There is no such option im menu." << endl << endl;
                system("pause");
                break;
            }
        }
    }
}

char AddressBook::chooseOptionFromUserMenu()
{
    char choice;

    system("cls");
    cout << " >>> USER MENU <<<" << endl;
    cout << "---------------------------" << endl;
    cout << "1. Add addressee" << endl;
    cout << "2. Find by name" << endl;
    cout << "3. Find by surname" << endl;
    cout << "4. Display all addressees" << endl;
    cout << "5. Delete addressee" << endl;
    cout << "6. Edit addressee" << endl;
    cout << "---------------------------" << endl;
    cout << "7. Change password" << endl;
    cout << "8. Log out" << endl;
    cout << "---------------------------" << endl;
    cout << "Your choice: ";
    choice = AuxiliaryMethods::readChar();

    return choice;
}

void AddressBook::goToUserMenu()
{
    while(userManager.getLoggedUserId() != 0)
    {
        switch (chooseOptionFromUserMenu())
        {
        case '1': addresseeManager -> addAddressee();
            break;
        case '2': addresseeManager -> findAddresseesByName();
            break;
        case '3': addresseeManager -> findAddresseesBySurname();
            break;
        case '4': addresseeManager -> displayAllAddressees();
            break;
        case '5': addresseeManager -> removeAddressee();
            break;
        case '6': addresseeManager -> editAddressee();
            break;
        case '7': userManager.changePasswordOfLoggedUser();
            break;
        case '8':
            userManager.logOutUser();
            delete addresseeManager;
            addresseeManager = NULL;
            break;
        default:
            cout << "You inserted invalid data!" << endl;
        }
    }
}
