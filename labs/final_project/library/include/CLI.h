//
// Created by Mateusz Pryl on 06/01/2023.
//

#ifndef OOPPROJECT_CLI_H
#define OOPPROJECT_CLI_H
#include "memory"
#include "Book.h"
#include "Client.h"
#include "Request.h"
class CLI {
public:
    void displayBooks(std::shared_ptr<Book> books);

    void displayClients(std::shared_ptr<Client> clients);

    void displayRequests(std::shared_ptr<Request> requests);
};


#endif //OOPPROJECT_CLI_H
