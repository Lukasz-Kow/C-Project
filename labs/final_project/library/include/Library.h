//
// Created by Mateusz Pryl on 06/01/2023.
//

#ifndef OOPPROJECT_LIBRARY_H
#define OOPPROJECT_LIBRARY_H
#include "Client.h"
#include "Book.h"
#include "CLI.h"
#include "Request.h"

class Library {
private:

    int id;

    string name;

    CLI libraryCLI;

public:

    Library(int id, string name);

    void addBook(Book& book);

    void removeBook(string uuid);

    Book getBook(unsigned n);

    bool checkIfBookIsReserved(int cookId);

    void processRequest(Request *request);

    void makeRequest(string bookName, string entityWhoMadeTheRequest);

    int findAvailableBookId(string bookName);

    bool bookExists(string bookName);

    void rentBook(Book* book, string clientUuid);

    void finishReservation(int bookId);

    void addClient(Client* client);

    void removeClient(string clientUuid);

    Client::getClient(unsigned n);

    Request::getRequest(unsigned n);

};


#endif //OOPPROJECT_LIBRARY_H
