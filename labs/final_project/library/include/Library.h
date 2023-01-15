//
// Created by Mateusz Pryl on 06/01/2023.
//

#ifndef OOPPROJECT_LIBRARY_H
#define OOPPROJECT_LIBRARY_H

#include "Client.h"
#include "Book.h"
#include "CLI.h"
#include "Request.h"
#include <memory>

class Library {
private:

    int id;

    string name;

    shared_ptr<CLI> libraryCLI;

    std::vector<std::shared_ptr<Book>> books;
    std::vector<std::shared_ptr<Client>> clients;
    std::vector<std::shared_ptr<Request>> requests;

public:

    Library(int id, string name);

    void addBook(Book& book);

    void removeBook(string uuid);

    std::shared_ptr<Book> getBook(unsigned n);

    bool checkIfBookIsReserved(int cookId);

    void processRequest(std::shared_ptr<Request> request);

    void makeRequest(string bookName, string entityWhoMadeTheRequest);

    int findAvailableBookId(string bookName);

    bool bookExists(string bookName);

    void rentBook(std::shared_ptr<Book> book, string clientUuid);

    void finishReservation(int bookId);

    void addClient(std::shared_ptr<Client> client);

    void removeClient(string clientUuid);

    std::shared_ptr<Client> getClient(unsigned n);

    std::shared_ptr<Request> getRequest(unsigned n);

};


#endif //OOPPROJECT_LIBRARY_H
