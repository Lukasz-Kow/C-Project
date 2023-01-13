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

    virtual void displayBooks(std::shared_ptr<Book>) = 0;
    virtual void displayClients(std::shared_ptr<Client>) =0;
    virtual void deisplayRequests(std::shared_ptr<Request>)=0;
};


#endif //OOPPROJECT_LIBRARYUI_H
