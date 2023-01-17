//
// Created by Mateusz Pryl on 06/01/2023.
//

#include "../include/Book.h"

Book::Book(int id, string title, string author, int pageNumber):
    id(id), title(title), author(author), pageNumber(pageNumber), isAvailable(true), clientUuid("") {}

int Book::getId() {
    return id;
}

string Book::getClientUuid() {
    return clientUuid;
}

string Book::getTitle() {
    return title;
}

string Book::getAuthor() {
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

void Book::setUuid(string uuid) {
    this->clientUuid = uuid;
}




