//
// Created by Mateusz Pryl on 06/01/2023.
//

#include "../include/Book.h"
#include "Request.h"
Book::Book(int id, std::string title, std::string author, int pageNumber):
    id(id), title(title), author(author), pageNumber(pageNumber), isAvailable(true), clientUuid("") {}

int Book::getId() {
    return id;
}

std::string Book::getClientUuid() {
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
    return false;
}

void Book::setStatus() {
}

void Book::setUuid(std::string uuid) {
    this->clientUuid = uuid;
}




