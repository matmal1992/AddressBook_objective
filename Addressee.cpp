#include "Addressee.h"

void Addressee::setId(int id) {addresseeId = id;}
void Addressee::setLoggedUserId(int id) {userId = id;}
void Addressee::setName(string name) {this->name = name;}
void Addressee::setSurname(string surname) {this->surname = surname;}
void Addressee::setAddress(string address) {this->address = address;}
void Addressee::setEmail(string email) {this->email = email;}
void Addressee::setPhoneNumber(string phoneNumber) {this->phoneNumber = phoneNumber;}

int Addressee::getId() {return addresseeId;}
int Addressee::getUserId() {return userId;}
string Addressee::getName() {return name;}
string Addressee::getSurname() {return surname;}
string Addressee::getAddress() {return address;}
string Addressee::getEmail() {return email;}
string Addressee::getPhoneNumber() {return phoneNumber;}


