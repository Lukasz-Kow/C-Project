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

#include <boost/uuid/uuid.hpp>            // uuid class
#include <boost/uuid/uuid_generators.hpp> // generators
#include <boost/uuid/uuid_io.hpp>         // streaming operators etc.

class Library;

using namespace std;

class Client {
private:

    int id;
    boost::uuids::uuid clientUuid;

    std::string name;
    std::string surname;
    std::string phoneNumber;
    std::string city;
    Gender gender;
    
public:
        Client(int id, std::string name, std::string surname, std::string phoneNumber, string city, Gender gender);

        virtual void requestReservation(std::string bookName, Library& library) = 0;

        int getID();

        boost::uuids::uuid getUuid();

        std::string getName();

        std::string getSurname();

        std::string getPhoneNumber();

        std::string getCity();

        Gender getGender();

        virtual std::string getSpecialTrait() = 0;

        virtual std::string display() = 0;
};


#endif //OOPPROJECT_CLIENT_H
