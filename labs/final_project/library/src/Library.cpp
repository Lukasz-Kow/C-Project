//
// Created by Mateusz Pryl on 06/01/2023.
//

#include "Library.h"

Library::Library(int id, string name): id(id), name(name) {}

void Library::addBook(std::shared_ptr<Book> book) {
    books.push_back(book);
}

void Library::removeBook(string uuid) {

}

std::shared_ptr<Book> Library::getBook(unsigned int n) {
    return books[n];
}

bool Library::checkIfBookIsReserved(int bookId) {
    std::shared_ptr<Book> book = getBook(bookId);
    std::cout << book->getId();
}

void Library::processRequest(std::shared_ptr<Request> request) {


}

void Library::makeRequest(string bookName, ClientTypes entityWhoMadeTheRequest) {
    std::cout<<"bookname: " << bookName << " entitynum: " << entityWhoMadeTheRequest;
}

int Library::findAvailableBookId(string bookName) {

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
    if (index > 0) {
        return true;
    }
}

void Library::rentBook(std::shared_ptr<Book> book, string clientUuid) {

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



