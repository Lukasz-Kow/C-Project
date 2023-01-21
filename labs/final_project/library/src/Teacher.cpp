//
// Created by Mateusz Pryl on 06/01/2023.
//

#include "Teacher.h"
#include "sstream"


Teacher::Teacher(int id, std::string name, std::string surname, std::string phoneNumber, std::string city, Gender gender,
                 std::string specialty) : Client(id, name, surname, phoneNumber,city, gender), specialty(specialty){

}

void Teacher::requestReservation(std::string bookName, Library& library) {
    library.makeRequest(bookName, TEACHER, getUuid());
}

std::string Teacher::getSpecialTrait() {
    return specialty;
}

std::string Teacher::display() {
    std::stringstream TeacherInfo;
    TeacherInfo << "Teacher's ID: " << getID() << endl
                << "Teacher's UUID: " << getUuid() << endl
                << "Teacher's gender: " << getGender() << endl
                << "Teacher's Name: " << getName() << endl
                << "Teacher's Surename: " << getSurname() << endl
                << "Teacher's specialty: " << getSpecialTrait() << endl
                << "Teacher's phone number: " << getPhoneNumber() << endl
                << "Teacher's city of residence: " << getCity() << endl;
}
