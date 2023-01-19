//
// Created by Mateusz Pryl on 06/01/2023.
//

#include "Request.h"
#include "Status.h"
#include "Date.h"

Request::Request(int id, std::string date, ClientTypes entityWhoMadeTheRequest, std::string clientUuid, std::string requestedBookName,
                 Status status):
                 id(id), stringDate(date), entityWhoMadeTheRequest(entityWhoMadeTheRequest), clientUuid(clientUuid),
                 requestedBookName(requestedBookName),  status(status){}

int Request::getId() {
    return id;
}

std::string Request::getStringDate() const {
    return stringDate;
}

void Request::setStringDate(const std::string& date)
{
    stringDate = date;
}

//std::string Request::getDate() const
//{
//    return date;
//}

ClientTypes Request::getEntity() {
    return entityWhoMadeTheRequest;
}

std::string Request::getClientUuid() {
    return clientUuid;
}

std::string Request::getBookName() {
    return requestedBookName;
}

Status Request::getStatus() {
    return status;
}

void Request::setStatus() {

}
