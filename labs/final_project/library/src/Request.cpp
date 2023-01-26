//
// Created by Mateusz Pryl on 06/01/2023.
//

#include "Request.h"
#include "Status.h"
#include "Date.h"
#include "sstream"

using namespace std;
Request::Request(int id, std::string date, ClientTypes entityWhoMadeTheRequest, boost::uuids::uuid clientUuid, std::string requestedBookName,
                 Status status):
                 id(id), stringDate(date), entityWhoMadeTheRequest(entityWhoMadeTheRequest), clientUuid(clientUuid),
                 requestedBookName(requestedBookName),  status(status){}

int Request::getId() {
    return id;
}

std::string Request::getStringDate() const {
    return stringDate;
}

void Request::setStringDate(const std::string& date) {
    stringDate = date;
}


ClientTypes Request::getEntity() {
    return entityWhoMadeTheRequest;
}

boost::uuids::uuid Request::getClientUuid() {
    return clientUuid;
}

std::string Request::getBookName() {
    return requestedBookName;
}

Status Request::getStatus() {
    return status;
}

void Request::setStatus(Status status) {
    this->status = status;
}

std::string Request::display() {
    std::stringstream requestInfo;
    requestInfo << "Request ID: " << getId() << endl
                << "Request date: " << getStringDate() << endl
                << "Entity who made the request: " << getEntity() << endl
                << "Client's UUID: " << getClientUuid() << endl
                << "Requested book title:" << getBookName() << endl
                << "Request status: " << getStatus() << endl;
    return requestInfo.str();
}

