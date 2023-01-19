//
// Created by Mateusz Pryl on 06/01/2023.
//

#ifndef OOPPROJECT_TEACHER_H
#define OOPPROJECT_TEACHER_H
#include "Client.h"
#include "Genders.h"
#include "Library.h"

class Teacher : public Client{
private:

    std::string specialty;

public:

    Teacher(int id, std::string uuid, std::string name, std::string surname, std::string phoneNumber, std::string city, Gender gender, std::string specialty);

    void requestReservation(std::string bookName, Library& library) override;

    std::string getSpecialTrait() override;

    std::string display() override;
};


#endif //OOPPROJECT_TEACHER_H
