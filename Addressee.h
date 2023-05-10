#ifndef ADDRESSEE_H
#define ADDRESSEE_H

#include <iostream>

using namespace std;

class Addressee
{
    int addresseeId;
    int userId;
    string name;
    string surname;
    string address;
    string email;
    string phoneNumber;

public:
    void setLoggedUserId(int id);
    void setId(int id);
    void setName(string name);
    void setSurname(string surname);
    void setAddress(string address);
    void setEmail(string email);
    void setPhoneNumber(string phoneNumber);

    int getUserId();
    int getId();
    string getName();
    string getSurname();
    string getAddress();
    string getEmail();
    string getPhoneNumber();
};

#endif
