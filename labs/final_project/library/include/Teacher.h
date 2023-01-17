//
// Created by Mateusz Pryl on 06/01/2023.
//

#ifndef OOPPROJECT_TEACHER_H
#define OOPPROJECT_TEACHER_H
#include "Client.h"
#include "Genders.h"

class Teacher : public Client{
private:

    string specialty;

public:

    Teacher(int id, string uuid, string name, string surname, string phoneNumber, string city, Gender gender, string specialty);

    void requestReservation(string bookName) override;

    string getSpecialTrait() override;
};


#endif //OOPPROJECT_TEACHER_H
