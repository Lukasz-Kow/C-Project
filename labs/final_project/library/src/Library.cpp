//
// Created by Mateusz Pryl on 06/01/2023.
//

#include "Library.h"

Library::Library(int id, std::string name): id(id), name(name) {}

void Library::addBook(std::shared_ptr<Book> book) {
    books.push_back(book);
}

void Library::removeBook(boost::uuids::uuid uuid) {
    for(int i=0; i<books.size();i++)
    {
        if(books[i]->getClientUuid() == uuid)
        {
            books.erase(books.begin()+i);
        }
    }
}

std::shared_ptr<Book> Library::getBook(unsigned int n) {
    return books[n];
}

void Library::processRequest(std::shared_ptr<Request> request) {

    if(bookExists(request->getBookName())) {
        int bookIndex = findAvailableBookIndex(request->getBookName());
        if (bookIndex >= 0) {
            if (request->getEntity() == TEACHER && books[bookIndex]->getBookTypes() == TEACHERBOOK ||
                    books[bookIndex]->getBookTypes() == STUDENTBOOK ||
                    books[bookIndex]->getBookTypes() == ENCYCLOPEDIA)
            {
                rentBook(bookIndex, request->getClientUuid());
                request->setStatus(FULFILLED);
            }
            else if (request->getEntity() == STUDENT && books[bookIndex]->getBookTypes() == STUDENTBOOK ||
                     books[bookIndex]->getBookTypes() == ENCYCLOPEDIA) {
                rentBook(bookIndex, request->getClientUuid());
                request->setStatus(FULFILLED);
            }
            else if (request->getEntity() == GUEST && books[bookIndex]->getBookTypes() == STUDENTBOOK ||
                     books[bookIndex]->getBookTypes() == ENCYCLOPEDIA) {
                rentBook(bookIndex, request->getClientUuid());
                request->setStatus(FULFILLED);

        } else {
            request->setStatus(REJECTED);
            std::cerr << "Failed to rent this book" << std::endl;
        }
    } else {
        request->setStatus(REJECTED);
        std::cerr << "Failed to rent this book" << std::endl;
    }

    addRequest(request);
    }
}

void Library::makeRequest(string bookName, ClientTypes entityWhoMadeTheRequest, boost::uuids::uuid uuid) {
    std::shared_ptr<Request> clientRequest = std::make_shared<Request>(getRequestNumber() + 1, "2023-12-01",
                                                                       entityWhoMadeTheRequest, uuid, bookName, PROCESSING);
    processRequest(clientRequest);
}

int Library::getRequestNumber() {
    return requests.size();
}

void Library::addRequest(std::shared_ptr<Request> request) {
    requests.push_back(request);
}

int Library::findAvailableBookIndex(string bookName) {
    for(int i = 0; i < books.size(); i++) {
        if(books[i]->getTitle() == bookName) {
            if(books[i]->getStatus()){
                // Book is available
                return i;
            }
            else {
                continue;
            }
        }
    }
    return -1;
}

bool Library::bookExists(string bookName) {
    int index = -1;
    for(int i = 0; i < books.size(); i ++)
    {
        if(books[i]->getTitle() == bookName)
        {
            index = i;
        }
    }
    if (index >= 0) {
        return true;
    }
    return false;
}

void Library::rentBook(int bookIndex, boost::uuids::uuid clientUuid) {
    books[bookIndex]->setStatus(false);
    books[bookIndex]->setUuid(clientUuid);
}

void Library::finishReservation(int bookId) {

}

void Library::addClient(std::shared_ptr<Client> client) {
    clients.push_back(client);
}

std::shared_ptr<Client> Library::getClient(unsigned int n) {
    return clients[n];
}

std::shared_ptr<Request> Library::getRequest(unsigned int n) {
    return requests[n];
}



