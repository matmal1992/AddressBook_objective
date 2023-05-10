#include "FileWithAddressees.h"

bool FileWithAddressees::addAddresseeToFile(Addressee addressee)
{
    string lineWithAddresseeData{};
    fstream textFile;
    textFile.open(getFileName().c_str(), ios::out | ios::app);

    if (textFile.good())
    {
        lineWithAddresseeData = turnAddresseeDataIntoDataSeparatedByDashes(addressee);

        if (checkIfFileIsEmpty(textFile))
            textFile << lineWithAddresseeData;
        else
            textFile << endl << lineWithAddresseeData ;

        textFile.close();
        return true;
    }
    else
        return false;
}

string FileWithAddressees::turnAddresseeDataIntoDataSeparatedByDashes(Addressee addressee)
{
    string lineWithAddresseeData{};

    lineWithAddresseeData.append(AuxiliaryMethods::intToStringConversion(addressee.getId()) + '|');
    lineWithAddresseeData.append(AuxiliaryMethods::intToStringConversion(addressee.getUserId()) + '|');
    lineWithAddresseeData.append(addressee.getName() + '|');
    lineWithAddresseeData.append(addressee.getSurname() + '|');
    lineWithAddresseeData.append(addressee.getPhoneNumber() + '|');
    lineWithAddresseeData.append(addressee.getEmail() + '|');
    lineWithAddresseeData.append(addressee.getAddress() + '|');

    return lineWithAddresseeData;
}

Addressee FileWithAddressees::loadAddresseeData(string addresseeDataSeparatedByDashes)
{
    Addressee addressee;
    string singleAddresseeData{};
    int numberOfSingleAddresseeData = 1;

    for (size_t charPosition = 0; charPosition < addresseeDataSeparatedByDashes.length(); ++charPosition)
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

string FileWithAddressees::getFileNameWithAddressees()
{
    return TextFile::getFileName();
}

vector <Addressee> FileWithAddressees::loadAddresseesOfLoggedUserFromFile(int userId)
{
    Addressee addressee;
    vector <Addressee> addressees;
    int lastAddresseeId;
    string singleAddresseeDataSeparatedByDashes{};
    string dataOfLastAddresseeInFile{};
    fstream textFile;
    textFile.open(TextFile::getFileName().c_str(), ios::in);

    if (textFile.good())
    {
        while (getline(textFile, singleAddresseeDataSeparatedByDashes))
        {
            if(userId == AuxiliaryMethods::getUserIdFromDataSeparatedByDashes(singleAddresseeDataSeparatedByDashes))
            {
                addressee = loadAddresseeData(singleAddresseeDataSeparatedByDashes);
                addressees.push_back(addressee);
            }
        }
        dataOfLastAddresseeInFile = singleAddresseeDataSeparatedByDashes;
    }
    else
        cout << "Opening the file failed." << endl;

    textFile.close();

    if (dataOfLastAddresseeInFile != "")
    {
        lastAddresseeId = AuxiliaryMethods::getAddresseeIdFromDataSeparatedByDashes(dataOfLastAddresseeInFile);
        setLastAddresseeId(lastAddresseeId);
    }

    return addressees;
}

void FileWithAddressees::setLastAddresseeId(int id)
{
    lastAddresseeId = id;
}

int FileWithAddressees::getLastAddresseeId()
{
    return lastAddresseeId;
}

string FileWithAddressees::getTemporaryFileName()
{
    return TEMPORARY_FILE_NAME;
}

void FileWithAddressees::removeSelectedLineInFile(int addresseeId)
{
    fstream loadedTextFile, temporaryTextFile;
    string loadedLine{};
    int idFromLine{};

    loadedTextFile.open(getFileNameWithAddressees().c_str(), ios::in);
    temporaryTextFile.open(getTemporaryFileName().c_str(), ios::out | ios::app);

    if (loadedTextFile.good() && addresseeId != 0)
    {
        while (getline(loadedTextFile, loadedLine))
        {
            idFromLine = AuxiliaryMethods::getAddresseeIdFromDataSeparatedByDashes(loadedLine);

            if (idFromLine == addresseeId) {}
            else
                {
                    if(TextFile::checkIfFileIsEmpty(temporaryTextFile))
                        temporaryTextFile << loadedLine;
                    else
                        temporaryTextFile << endl << loadedLine;
                }
        }
        loadedTextFile.close();
        temporaryTextFile.close();

        removeFile(getFileNameWithAddressees());
        changeFileName(getTemporaryFileName(), getFileNameWithAddressees());
    }
}

void FileWithAddressees::removeFile(string fileNameWithExtension)
{
    if (remove(fileNameWithExtension.c_str()) == 0) {}
    else
        cout << "Removing of the file failed. " << fileNameWithExtension << endl;
}

void FileWithAddressees::changeFileName(string previousName, string newName)
{
    if (rename(previousName.c_str(), newName.c_str()) == 0) {}
    else
        cout << "File name has not been changed." << previousName << endl;
}

void FileWithAddressees::editSelectedLineInFile(string lineWithAddresseeDataSeparatedByDashes)
{
    fstream loadedTextFile, temporaryTextFile;
    string loadedLine{};
    int idFromLine{};
    int editedAddresseeId = AuxiliaryMethods::getAddresseeIdFromDataSeparatedByDashes(lineWithAddresseeDataSeparatedByDashes);

    loadedTextFile.open(getFileNameWithAddressees().c_str(), ios::in);
    temporaryTextFile.open(getTemporaryFileName().c_str(), ios::out | ios::app);

    if (loadedTextFile.good())
    {
        while (getline(loadedTextFile, loadedLine))
        {
            idFromLine = AuxiliaryMethods::getAddresseeIdFromDataSeparatedByDashes(loadedLine);

            if (idFromLine == editedAddresseeId)
                temporaryTextFile <<  endl << lineWithAddresseeDataSeparatedByDashes;
            else
            {
                if(TextFile::checkIfFileIsEmpty(temporaryTextFile))
                    temporaryTextFile << loadedLine;
                else
                    temporaryTextFile << endl << loadedLine;
            }
        }
        loadedTextFile.close();
        temporaryTextFile.close();

        removeFile(getFileNameWithAddressees());
        changeFileName(getTemporaryFileName(), getFileNameWithAddressees());
    }
}
