//
// Created by Mateusz Pryl on 06/01/2023.
//

#ifndef OOPPROJECT_CLIENT_H
#define OOPPROJECT_CLIENT_H

#include <iostream>
#include <string>
#include <vector>
#include "memory"

class Library;

using namespace std;

class Client {
private:

    vector<shared_ptr<Client>> clients;

    int id;
    string uuid;
    string name;
    string surname;
    string phoneNumber;
    string city;
    string gender;
    
public:
        Client(int id, string uuid, string name, string surname, string phoneNumber, string city, string gender);

        virtual void requestReservation(std::string bookName) = 0;

        string getUuid();

        string getName();

        string getSurname();

        string getPhoneNumber();

        string getCity();

        string getGender();

        virtual string getSpecialTrait() = 0;

};


#endif //OOPPROJECT_CLIENT_H
