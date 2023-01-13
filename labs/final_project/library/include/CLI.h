//
// Created by Mateusz Pryl on 06/01/2023.
//

#ifndef OOPPROJECT_CLI_H
#define OOPPROJECT_CLI_H

#include "LibraryUI.h"

class CLI: public LibraryUI{

    void displayClients() override;
    void displayBooks() override;
    void displayRequests() override;

};


#endif //OOPPROJECT_CLI_H
