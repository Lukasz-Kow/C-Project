//
// Created by Mateusz Pryl on 06/01/2023.
//

#ifndef OOPPROJECT_UNITTESTUI_H
#define OOPPROJECT_UNITTESTUI_H

#include "LibraryUI.h"

class UnitTestUi: public LibraryUI {
    UnitTestUi();

    void displayBooks(std::shared_ptr<Book> books) override;
    void displayClients(std::shared_ptr<Client> clients) override;
    void displayRequests(std::shared_ptr<Request> requests) override;
};


#endif //OOPPROJECT_UNITTESTUI_H
