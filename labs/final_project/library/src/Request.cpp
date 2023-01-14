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
    return entityWhoMadeTheRequest;
}

string Request::getClientUuid() {
    return clientUuid;
}

string Request::getBookName() {
    return requestedBookName;
}

string Request::getStatus() {
    return status;
}

void Request::setStatus() {

}
