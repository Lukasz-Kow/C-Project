//
// Created by Mateusz Pryl on 06/01/2023.
//

#include "Guest.h"

void Guest::requestReservation(string bookName) {

}

Guest::Guest(int id, string uuid, string name, string surname, string phoneNumber, string city, string gender):
    Client(id, uuid, name, surname, phoneNumber, city, gender) {}

string Guest::getSpecialTrait() {
    return std::string();
}
