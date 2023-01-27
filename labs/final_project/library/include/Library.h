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

/**
 * Class which represents library
 * It holds books, clients and requests
 * It also has a pointer to UI class
 */

class Library {
private:

    int id;

    std::string name;

    std::vector<std::shared_ptr<Book>> books;
    std::vector<std::shared_ptr<Client>> clients;
    std::vector<std::shared_ptr<Request>> requests;

public:

    shared_ptr<LibraryUI> libraryCLI;

    Library(int id, std::string name, std::shared_ptr<LibraryUI> cli);

    void addBook(std::shared_ptr<Book> book);

    void removeBook(int bookId);

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

    std::vector<std::shared_ptr<Book>> getBooks();

    std::vector<std::shared_ptr<Client>> getClients();

    std::vector<std::shared_ptr<Request>> getRequests();

    bool ifClientBelongsToLibrary(boost::uuids::uuid clientUuid);

    int getClientIndexByUUID(boost::uuids::uuid clientUuid);

};


#endif //OOPPROJECT_LIBRARY_H
