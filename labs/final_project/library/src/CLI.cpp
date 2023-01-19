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
    for(int i =0; i<books.size();i++)
    {
        books[i]->display();
    }
}

void CLI::displayClients(std::vector<std::shared_ptr<Client>> clients) {
    for(int i=0;i<clients.size();i++)
    {
        clients[i]->display();
    };

}

void CLI::displayRequests(std::vector<std::shared_ptr<Request>> requests) {
    for(int i=0;i<requests.size();i++)
    {
        requests[i]->display();
    };

}




