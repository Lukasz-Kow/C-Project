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
    string uuid;
    string name;
    string surname;
    string phoneNumber;
    string city;
    Gender gender;
    
public:
        Client(int id, string uuid, string name, string surname, string phoneNumber, string city, Gender gender);

        virtual void requestReservation(std::string bookName, Library& library) = 0;

        string getUuid();

        string getName();

        string getSurname();

        string getPhoneNumber();

        string getCity();

        Gender getGender();

        virtual string getSpecialTrait() = 0;

};


#endif //OOPPROJECT_CLIENT_H
