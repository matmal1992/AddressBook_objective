#ifndef USERMANAGER_H
#define USERMANAGER_H

#include "FileWithUsers.h"
#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>

using namespace std;

class UserManager
{
    int loggedUserId;
    vector <User> users;
    FileWithUsers fileWithUsers;

    User insertDataForNewUser();
    int getNewUserId();
    bool checkIfLoginExists(string login);
    void setLoggedUserId(int id);

public:
    UserManager(string fileNameWithUsers) : fileWithUsers(fileNameWithUsers)
    {
        loggedUserId = 0;
        users = fileWithUsers.loadUsersFromFile();
    };

    void registerUser();
    void logInUser();
    void changePasswordOfLoggedUser();
    void saveAllUsersToFile(vector <User> users);
    void logOutUser();
    int getLoggedUserId();
    bool checkIfUserIsLogged();
};

#endif
