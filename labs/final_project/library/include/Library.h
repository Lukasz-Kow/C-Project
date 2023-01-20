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
#include "ClientTypes.h"

class Library {
private:

    int id;

    std::string name;

//    shared_ptr<CLI> libraryCLI;

    std::vector<std::shared_ptr<Book>> books;
    std::vector<std::shared_ptr<Client>> clients;
    std::vector<std::shared_ptr<Request>> requests;

public:

    Library(int id, std::string name);

    void addBook(std::shared_ptr<Book> book);

    void removeBook(boost::uuids::uuid uuid);

    std::shared_ptr<Book> getBook(unsigned n);

    void processRequest(std::shared_ptr<Request> request);

    void makeRequest(std::string bookName, ClientTypes entityWhoMadeTheRequest, boost::uuids::uuid uuid);

    int findAvailableBookIndex(std::string bookName);

    bool bookExists(std::string bookName);

    void rentBook(int bookIndex, boost::uuids::uuid clientUuid);

    void finishReservation(int bookId);

    void addClient(std::shared_ptr<Client> client);

    void addRequest(std::shared_ptr<Request> request);

    void removeClient(boost::uuids::uuid clientUuid);

    int getRequestNumber();

    std::shared_ptr<Client> getClient(unsigned n);

    std::shared_ptr<Request> getRequest(unsigned n);

};


#endif //OOPPROJECT_LIBRARY_H
