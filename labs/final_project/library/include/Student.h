//
// Created by Mateusz Pryl on 06/01/2023.
//

#ifndef OOPPROJECT_STUDENT_H
#define OOPPROJECT_STUDENT_H

#include "Client.h"
#include "Genders.h"
#include "Library.h"

class Student : public Client{
private:
    std::string course;

public:
    Student(int id, std::string uuid, std::string name, std::string surname, std::string phoneNumber, std::string city, Gender gender, std::string course);

    void requestReservation(string bookName, Library& library) override;

    std::string getSpecialTrait() override;

    std::string display() override;
};


#endif //OOPPROJECT_STUDENT_H
