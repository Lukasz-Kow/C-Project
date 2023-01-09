//
// Created by Mateusz Pryl on 06/01/2023.
//

#include "Client.h"

Client::Client(int id, string uuid, string name, string surname, string phoneNumber, string city, string gender):
    id(id), uuid(uuid), name(name), surname(surname), phoneNumber(phoneNumber), city(city), gender(gender) {}

string Client::getUuid() {
    return uuid;
}

string Client::getName() {
    return name;
}

string Client::getSurname() {
    return surname;
}

string Client::getPhoneNumber() {
    return phoneNumber;
}

string Client::getCity() {
    return city;
}

string Client::getGender() {
    return gender;
}
