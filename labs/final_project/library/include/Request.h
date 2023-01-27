//
// Created by Mateusz Pryl on 06/01/2023.
//

#ifndef OOPPROJECT_REQUEST_H
#define OOPPROJECT_REQUEST_H

#include <boost/uuid/uuid.hpp>            // uuid class
#include <boost/uuid/uuid_generators.hpp> // generators
#include <boost/uuid/uuid_io.hpp>         // streaming operators etc.
#include <vector>
#include <string>
#include "Status.h"
#include "ClientTypes.h"
#include "boost/date_time/posix_time/posix_time.hpp"

/**
 * Class representing a request in the library
 */

class Request {

private:

    int id;

    boost::posix_time::ptime date;

    ClientTypes entityWhoMadeTheRequest;

    boost::uuids::uuid clientUuid;

    std::string requestedBookName;

    Status status;

public:

    Request(int id, ClientTypes entityWhoMadeTheRequest, boost::uuids::uuid clientUuid, std::string requestedBookName,
            Status status);

    int getId();

    std::string getStringDate() const;

    ClientTypes getEntity();

    boost::uuids::uuid getClientUuid();

    std::string getBookName();

    Status getStatus();

    void setStatus(Status status);

    std::string display();

    boost::posix_time::ptime getDateTime();

};


#endif //OOPPROJECT_REQUEST_H
