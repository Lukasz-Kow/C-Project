//
// Created by Mateusz Pryl on 06/01/2023.
//

#include "Guest.h"
#include "sstream"


Guest::Guest(int id, std::string name, std::string surname, std::string phoneNumber, std::string city, Gender gender):
    Client(id, name, surname, phoneNumber, city, gender) {}

//Inside the function, it makes a request to the library to reserve a book which will be processed.
void Guest::requestReservation(std::string bookName, Library& library) {
    library.makeRequest(bookName, GUEST, getUuid());
}

std::string Guest::getSpecialTrait() {
    return 0;
}

std::string Guest::display() {
    std::stringstream guestInfo;
    guestInfo   << "Guest's UUID: " << getUuid() << endl
                << "Guest's gender: " << getGender() << endl
                << "Guest's Name: " << getName() << endl
                << "Guest's Surname: " << getSurname() << endl
                << "Guest's phone number: " << getPhoneNumber() << endl
                << "Guest's city of residence: " << getCity() << endl;
    return guestInfo.str();
}
