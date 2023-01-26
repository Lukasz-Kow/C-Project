//
// Created by Mateusz Pryl on 06/01/2023.
//

#include "CLI.h"
#include "LibraryUI.h"
#include "sstream"
#include "Book.h"

CLI::CLI() {

}

void CLI::displayBooks(std::vector<std::shared_ptr<Book>> books) {
    for(auto & book : books)
    {
        book->display();
    }
}

void CLI::displayClients(std::vector<std::shared_ptr<Client>> clients) {
    for(auto & client : clients)
    {
        client->display();
    };

}

void CLI::displayRequests(std::vector<std::shared_ptr<Request>> requests) {
    for(auto & request : requests)
    {
        request->display();
    };

}




