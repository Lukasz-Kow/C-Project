//
// Created by Mateusz Pryl on 06/01/2023.
//

#include "Request.h"
#include "Status.h"

Request::Request(int id, std::string date, std::string entityWhoMadeTheRequest, std::string clientUuid, std::string requestedBookName,
                 Status status):
                 id(id), entityWhoMadeTheRequest(entityWhoMadeTheRequest), clientUuid(clientUuid),
                 requestedBookName(requestedBookName),  status(status){

    boost::posix_time::ptime time(boost::posix_time::time_from_string(date));
    this->date = time;
}

int Request::getId() {
    return id;
}

boost::posix_time::ptime Request::getDate() {
    return date;
}

std::string Request::getEntity() {
    return entityWhoMadeTheRequest;
}

std::string Request::getClientUuid() {
    return clientUuid;
}

std::string Request::getBookName() {
    return requestedBookName;
}

std::string Request::getStatus() {
    return status;
}

void Request::setStatus() {

}
