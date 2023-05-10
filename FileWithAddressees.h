#ifndef FILEWITHADDRESSEES_H
#define AUXILIARYMETHODS_H_H

#include "Addressee.h"
#include "AuxiliaryMethods.h"
#include "TextFile.h"
#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>

using namespace std;

class FileWithAddressees : public TextFile
{
    const string TEMPORARY_FILE_NAME = "TemporaryFile.txt";
    int lastAddresseeId;

    Addressee loadAddresseeData(string addresseeDataSeparatedByDashes);
    string getFileNameWithAddressees();
    string getTemporaryFileName();
    void removeFile(string fileNameWithExtension);
    void changeFileName(string previousName, string newName);

public:
    FileWithAddressees(string fileName): TextFile(fileName)
    {
        lastAddresseeId = 0;
    };

    string turnAddresseeDataIntoDataSeparatedByDashes(Addressee addressee);
    vector <Addressee> loadAddresseesOfLoggedUserFromFile(int userId);
    int getLastAddresseeId();
    bool addAddresseeToFile(Addressee addressee);
    void setLastAddresseeId(int id);
    void removeSelectedLineInFile(int numberOfRemovedLine);
    void editSelectedLineInFile(string lineWithAddresseeDataSeparatedByDashes);
};

#endif
