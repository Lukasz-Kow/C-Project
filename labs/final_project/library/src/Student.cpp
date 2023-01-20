//
// Created by Mateusz Pryl on 06/01/2023.
//

#include "Student.h"
#include "sstream"


Student::Student(int id, std::string uuid, std::string name, std::string surname, std::string phoneNumber, std::string city, Gender gender,
                 std::string course): Client( id, name, surname, phoneNumber, city, gender), course(course){

}

void Student::requestReservation(std::string bookName, Library& library) {
    // Making a request to the library which will be processed
    library.makeRequest(bookName, STUDENT, getUuid());

}

std::string Student::getSpecialTrait() {
    return course;
}

std::string Student::display() {
    std::stringstream StudentInfo;
    StudentInfo << "Student's ID: " << getID() << endl
    << "Student's UUID: " << getUuid() << endl
    << "Student's gender: " << getGender() << endl
    << "Student's Name: " << getName() << endl
    << "Student's Surename: " << getSurname() << endl
    << "Student's course: " << getSpecialTrait() << endl
    << "Student's phone number: " << getPhoneNumber() << endl
    << "Student's city of residence: " << getCity() << endl;

}
