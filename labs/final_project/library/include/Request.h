//
// Created by Mateusz Pryl on 06/01/2023.
//

#ifndef OOPPROJECT_REQUEST_H
#define OOPPROJECT_REQUEST_H


#include <vector>
#include "Status.h"
#include <chrono>
#include "boost/date_time/posix_time/posix_time.hpp"

class Request {

private:

    int id;

    boost::posix_time::ptime date;

    std::string entityWhoMadeTheRequest;

    std::string clientUuid;

    std::string requestedBookName;

    Status status;

public:

    Request(int id, std::string date, std::string entityWhoMadeTheRequest, std::string clientUuid, std::string requestedBookName,
            Status status);

    int getId();

    boost::posix_time::ptime getDate();

    std::string getEntity();

    std::string getClientUuid();

    std::string getBookName();

    Status getStatus();

    void setStatus();

};


#endif //OOPPROJECT_REQUEST_H
