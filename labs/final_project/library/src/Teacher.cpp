//
// Created by Mateusz Pryl on 06/01/2023.
//

#include "Teacher.h"

Teacher::Teacher(int id, string uuid, string name, string surname, string phoneNumber, string city, string gender,
                 string specialty) : Client(id, uuid, name, surname, phoneNumber,city, gender), specialty(specialty){

}

void Teacher::requestReservation(string bookName) {

}

string Teacher::getSpecialTrait() {
    return std::string();
}
