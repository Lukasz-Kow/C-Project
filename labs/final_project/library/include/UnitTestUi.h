//
// Created by Mateusz Pryl on 06/01/2023.
//

#ifndef OOPPROJECT_UNITTESTUI_H
#define OOPPROJECT_UNITTESTUI_H

#include "LibraryUI.h"

/**
 * Class for UnitTest UI
 * It's used only in UnitTests
 */

class UnitTestUi: public LibraryUI {
public:

    UnitTestUi();

    void displayBooks(std::vector<std::shared_ptr<Book>> books);
    void displayClients(std::vector<std::shared_ptr<Client>> clients);
    void displayRequests(std::vector<std::shared_ptr<Request>> requests);
};


#endif //OOPPROJECT_UNITTESTUI_H
