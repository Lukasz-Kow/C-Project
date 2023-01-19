//
// Created by Mateusz Pryl on 06/01/2023.
//

#ifndef OOPPROJECT_CLIENT_H
#define OOPPROJECT_CLIENT_H

#include <iostream>
#include <string>
#include <vector>
#include "memory"
#include "Genders.h"
//#include "Library.h"

class Library;

using namespace std;

class Client {
private:

    int id;
    std::string uuid;
    std::string name;
    std::string surname;
    std::string phoneNumber;
    std::string city;
    Gender gender;
    
public:
        Client(int id, std::string uuid, std::string name, std::string surname, std::string phoneNumber, string city, Gender gender);

        virtual void requestReservation(std::string bookName, Library& library) = 0;

        int getID();

        std::string getUuid();

        std::string getName();

        std::string getSurname();

        std::string getPhoneNumber();

        std::string getCity();

        Gender getGender();

        virtual std::string getSpecialTrait() = 0;

        virtual std::string display() = 0;
};


#endif //OOPPROJECT_CLIENT_H
