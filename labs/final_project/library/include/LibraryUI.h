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
    virtual void displayBooks() = 0;
    virtual void displayClients() = 0;
    virtual void displayRequests() = 0;
};


#endif //OOPPROJECT_LIBRARYUI_H
