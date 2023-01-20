//
// Created by Mateusz Pryl on 06/01/2023.
//

#include "../include/Book.h"
#include "Request.h"

Book::Book(int id, std::string title, std::string author, int pageNumber, BookTypes bookType):
    id(id), title(title), author(author), pageNumber(pageNumber), bookType(bookType), isAvailable(true), bookUuid(boost::uuids::random_generator()()) {}

int Book::getId() {
    return id;
}

boost::uuids::uuid Book::getClientUuid() {
    return clientUuid;
}

std::string Book::getTitle() {
    return title;
}

std::string Book::getAuthor() {
    return author;
}

int Book::getPageNumber() {
    return pageNumber;
}

bool Book::getStatus() {
    return isAvailable;
}

void Book::setStatus(bool newStatus) {
    isAvailable = newStatus;
}

void Book::setUuid(boost::uuids::uuid uuid) {
    this->clientUuid = uuid;
}

BookTypes Book::getBookTypes() {
    return bookType;
}






