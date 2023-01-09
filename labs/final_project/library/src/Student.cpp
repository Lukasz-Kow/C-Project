//
// Created by Mateusz Pryl on 06/01/2023.
//

#include "Student.h"

Student::Student(int id, string uuid, string name, string surname, string phoneNumber, string city, string gender,
                 string course): Client(id, uuid, name, surname, phoneNumber, city, gender) {

}

void Student::requestReservation(string bookName) {

}

string Student::getSpecialTrait() {
    return std::string();
}
