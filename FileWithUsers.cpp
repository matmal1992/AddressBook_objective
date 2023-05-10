#include "FileWithUsers.h"

void FileWithUsers::addUserToFile(User user)
{
    fstream textFile;
    string lineWithUserData{};
    textFile.open(TextFile::getFileName().c_str(), ios::app);

    if (textFile.good())
    {
        lineWithUserData = turnUserDataIntoDataSeparatedByDashes(user);

        if (TextFile::checkIfFileIsEmpty(textFile))
            textFile << lineWithUserData;
        else
            textFile << endl << lineWithUserData ;
    }
    else
        cout << "Opening The file " << TextFile::getFileName() << " failed." << endl;

    textFile.close();
}

string FileWithUsers::turnUserDataIntoDataSeparatedByDashes(User user)
{
    string lineWithUserData{};

    lineWithUserData.append(AuxiliaryMethods::intToStringConversion(user.getId())+ '|');
    lineWithUserData.append(user.getLogin() + '|');
    lineWithUserData.append(user.getPassword() + '|');

    return lineWithUserData;
}

vector <User> FileWithUsers::loadUsersFromFile()
{
    User user;
    fstream textFile;
    vector <User> users;
    string dataOfSingleUserSeparatedByDashes{};

    textFile.open(TextFile::getFileName().c_str(), ios::in);

    if (textFile.good())
    {
        while (getline(textFile, dataOfSingleUserSeparatedByDashes))
        {
            user = loadUserData(dataOfSingleUserSeparatedByDashes);
            users.push_back(user);
        }
    }
    textFile.close();
    return users;
}

User FileWithUsers::loadUserData(string dataOfSingleUserSeparatedByDashes)
{
    User user;
    string singleUserData{};
    int numberOfSingleUserData = 1;

    for (size_t charPosition = 0; charPosition < dataOfSingleUserSeparatedByDashes.length(); ++charPosition)
    {
        if (dataOfSingleUserSeparatedByDashes[charPosition] != '|')
        {
            singleUserData += dataOfSingleUserSeparatedByDashes[charPosition];
        }
        else
        {
            switch(numberOfSingleUserData)
            {
            case 1:
                user.setId(atoi(singleUserData.c_str()));
                break;
            case 2:
                user.setLogin(singleUserData);
                break;
            case 3:
                user.setPassword(singleUserData);
                break;
            }
            singleUserData = "";
            numberOfSingleUserData++;
        }
    }
    return user;
}

void FileWithUsers::saveAllUsersToFile(vector <User> users)
{
    fstream textFile;
    string lineWithUserData{};
    vector <User>::iterator itrEnd = --users.end();

    textFile.open(TextFile::getFileName().c_str(), ios::out);

    if (textFile.good())
    {
        for (vector <User>::iterator itr = users.begin(); itr != users.end(); ++itr)
        {
            lineWithUserData = turnUserDataIntoDataSeparatedByDashes(*itr);

            if (itr == itrEnd)
                textFile << lineWithUserData;
            else
                textFile << lineWithUserData;

            lineWithUserData = "";
        }
    }
    else
    {
        cout << "I cannot open the file. " << TextFile::getFileName() << endl;
    }
    textFile.close();
}


