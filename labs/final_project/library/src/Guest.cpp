//
// Created by Mateusz Pryl on 06/01/2023.
//

#include "Guest.h"
#include "sstream"
void Guest::requestReservation(std::string bookName, Library& library) {
    library.makeRequest(bookName, GUEST, getUuid());
}

Guest::Guest(int id, std::string uuid, std::string name, std::string surname, std::string phoneNumber, std::string city, Gender gender):
    Client(id, uuid, name, surname, phoneNumber, city, gender) {}

std::string Guest::getSpecialTrait() {
    return 0;
}

std::string Guest::display() {
    std::stringstream GuestInfo;
    GuestInfo << "Guest's ID: " << getID() << endl
                << "Guest's UUID: " << getUuid() << endl
                << "Guest's gender: " << getGender() << endl
                << "Guest's Name: " << getName() << endl
                << "Guest's Surename: " << getSurname() << endl
                << "Guest's phone number: " << getPhoneNumber() << endl
                << "Guest's city of residence: " << getCity() << endl;
}
