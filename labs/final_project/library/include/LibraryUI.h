//
// Created by Mateusz Pryl on 06/01/2023.
//

#ifndef OOPPROJECT_LIBRARYUI_H
#define OOPPROJECT_LIBRARYUI_H

#include "memory"
#include "Client.h"
#include "Request.h"
#include "Book.h"

class LibraryUI {
public:
    virtual void displayBooks(std::vector<std::shared_ptr<Book>> books) = 0;
    virtual void displayClients(std::vector<std::shared_ptr<Client>> clients) = 0;
    virtual void displayRequests(std::vector<std::shared_ptr<Request>> requests) = 0;
};


#endif //OOPPROJECT_LIBRARYUI_H
