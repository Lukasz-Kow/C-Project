//
// Created by Mateusz Pryl on 06/01/2023.
//

#include "Client.h"
#include "Library.h"


Client::Client(int id, std::string name, std::string surname, std::string phoneNumber, std::string city, Gender gender):
    id(id), name(name), surname(surname), phoneNumber(phoneNumber), city(city), gender(gender), clientUuid(boost::uuids::random_generator()()) {
}

boost::uuids::uuid Client::getUuid() {
    return clientUuid;
}

std::string Client::getName() {
    return name;
}

std::string Client::getSurname() {
    return surname;
}

std::string Client::getPhoneNumber() {
    return phoneNumber;
}

std::string Client::getCity() {
    return city;
}

Gender Client::getGender() {
    return gender;
}

int Client::getID() {
    return id;
}


