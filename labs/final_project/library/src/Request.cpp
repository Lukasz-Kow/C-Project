//
// Created by Mateusz Pryl on 06/01/2023.
//

#include "Request.h"
#include "ctime"

Request::Request(int id, Date date, string entityWhoMadeTheRequest, string clientUuid, string requestedBookName,
                 string status) {

}

int Request::getId() {
    return id;
}

Date Request::getDate() {
    return Date;
}

string Request::getEntity() {
    return std::string();
}

string Request::getClientUuid() {
    return std::string();
}

string Request::getBookName() {
    return requestedBookName;
}

string Request::getStatus() {
    return std::string();
}

void Request::setStatus() {

}
