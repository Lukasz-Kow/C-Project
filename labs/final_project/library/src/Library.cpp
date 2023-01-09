//
// Created by Mateusz Pryl on 06/01/2023.
//

#include "Library.h"

Library::Library(int id, string name): id(id), name(name) {}

void Library::addBook(Book book) &{

}

void Library::removeBook(string uuid) {

}

Book Library::getBook(unsigned int n) {
    return 0;
}

bool Library::checkIfBookIsReserved(int cookId) {
    return false;
}

void Library::processRequest(std::shared_ptr<Request> request) {

}

void Library::makeRequest(string bookName, string entityWhoMadeTheRequest) {

}

int Library::findAvailableBookId(string bookName) {
    return 0;
}

bool Library::bookExists(string bookName) {
    return false;
}

void Library::rentBook(Book *book, string clientUuid) {

}

void Library::finishReservation(int bookId) {

}
