//
// Created by Mateusz Pryl on 06/01/2023.
//

#ifndef OOPPROJECT_GUEST_H
#define OOPPROJECT_GUEST_H

#include "Client.h"
#include "Genders.h"
#include "Library.h"

using namespace std;

class Guest : public Client {
public:

    Guest(int id, std::string name, std::string surname, std::string phoneNumber, std::string city, Gender gender);

    void requestReservation(std::string bookName, Library& library) override;

    std::string getSpecialTrait() override;

    std::string display() override;
};


#endif //OOPPROJECT_GUEST_H
