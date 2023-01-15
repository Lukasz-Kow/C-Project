//
// Created by Mateusz Pryl on 06/01/2023.
//

#ifndef OOPPROJECT_CLI_H
#define OOPPROJECT_CLI_H

#include "LibraryUI.h"

class CLI: public LibraryUI {
public:

    CLI();

    void displayBooks(std::shared_ptr<Book> books);
    void displayClients(std::shared_ptr<Client> clients);
    void displayRequests(std::shared_ptr<Request> requests);
};


#endif //OOPPROJECT_CLI_H
