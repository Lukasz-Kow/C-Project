//
// Created by Mateusz Pryl on 06/01/2023.
//

#include "Student.h"



Student::Student(int id, string uuid, string name, string surname, string phoneNumber, string city, Gender gender,
                 string course): Client( id, uuid, name, surname, phoneNumber, city, gender), course(course){

}

void Student::requestReservation(string bookName) {
    Client::requestReservation(bookName);
}

string Student::getSpecialTrait() {
    return course;
}
