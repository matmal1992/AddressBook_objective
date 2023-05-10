#ifndef FILEWITHUSERS_H
#define FILEWITHUSERS_H

#include "AuxiliaryMethods.h"
#include "User.h"
#include "TextFile.h"
#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>

using namespace std;

class FileWithUsers : public TextFile
{
    string turnUserDataIntoDataSeparatedByDashes(User user);
    User loadUserData(string dataOfSingleUserSeparatedByDashes);

public:
    FileWithUsers(string fileName) : TextFile(fileName){};

    vector <User> loadUsersFromFile();
    void addUserToFile(User user);
    void saveAllUsersToFile(vector <User> users);
};

#endif
