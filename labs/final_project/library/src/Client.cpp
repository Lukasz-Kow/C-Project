//
// Created by Mateusz Pryl on 06/01/2023.
//

#include "Client.h"
#include "Library.h"
Client::Client(int id, std::string uuid, std::string name, std::string surname, std::string phoneNumber, std::string city, Gender gender):
    id(id), uuid(uuid), name(name), surname(surname), phoneNumber(phoneNumber), city(city), gender(gender) {
    std::cout << "Clkeint created" << std::endl;
}

std::string Client::getUuid() {
    return uuid;
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


