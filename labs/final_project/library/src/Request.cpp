
#include "Request.h"
#include "Status.h"
#include "sstream"

using namespace std;
Request::Request(int id, ClientTypes entityWhoMadeTheRequest, boost::uuids::uuid clientUuid, std::string requestedBookName,
                 Status status):
                 id(id), entityWhoMadeTheRequest(entityWhoMadeTheRequest), clientUuid(clientUuid),
                 requestedBookName(requestedBookName),  status(status), date(boost::posix_time::second_clock::local_time()) {}

int Request::getId() {
    return id;
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

    std::string entity = "";
    if (getEntity() == STUDENT)
        entity = "Student";
    else if (getEntity() == TEACHER)
        entity = "Teacher";
    else if (getEntity() == GUEST)
        entity = "Guest";

    std::string statusName = "";
    if(getStatus() == PROCESSING)
        statusName = "PROCESSING";
    else if(getStatus() == FULFILLED)
        statusName = "FULFILLED";
    else if(getStatus() == REJECTED)
        statusName = "REJECTED";


    requestInfo << "Request ID: " << getId() << endl
                << "Entity who made the request: " << entity << endl
                << "Client's UUID: " << getClientUuid() << endl
                << "Requested book title: " << getBookName() << endl
                << "Request status: " << statusName << endl
                << "Request date: " << getDateTime() << endl;
    return requestInfo.str();
}

boost::posix_time::ptime Request::getDateTime() {
    return date;
}

