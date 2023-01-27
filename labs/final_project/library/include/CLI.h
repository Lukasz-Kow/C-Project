//
// Created by Mateusz Pryl on 06/01/2023.
//

#ifndef OOPPROJECT_CLI_H
#define OOPPROJECT_CLI_H

#include "LibraryUI.h"
#include "memory"
#include "vector"

/**
 * Class for CLI UI
 */

class CLI: public LibraryUI {
public:

    CLI();

    void displayBooks(std::vector<std::shared_ptr<Book>> book);
    void displayClients(std::vector<std::shared_ptr<Client>> clients);
    void displayRequests(std::vector<std::shared_ptr<Request>> requests);
};


#endif //OOPPROJECT_CLI_H
