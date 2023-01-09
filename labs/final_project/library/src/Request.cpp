//
// Created by Mateusz Pryl on 06/01/2023.
//

#include "Request.h"
#include "ctime"

Request::Request(int id, Date date, string entityWhoMadeTheRequest, string clientUuid, string requestedBookName,
                 string status) {

}

int Request::getId() {
    return 0;
}

Date Request::getDate() {
    return nullptr;
}

string Request::getEntity() {
    return std::string();
}

string Request::getClientUuid() {
    return std::string();
}

string Request::getBookName() {
    return std::string();
}

string Request::getStatus() {
    return std::string();
}

void Request::setStatus() {

}
