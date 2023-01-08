//
// Created by Mateusz Pryl on 06/01/2023.
//

#ifndef OOPPROJECT_GUEST_H
#define OOPPROJECT_GUEST_H

#include "Client.h"

using namespace std;

class Guest : public Client {
public:

    Guest(int id, string uuid, string name, string surname, string phoneNumber, string city, string gender);

    void requestReservation(string bookName) override;

    string getSpecialTrait() override;

};


#endif //OOPPROJECT_GUEST_H
