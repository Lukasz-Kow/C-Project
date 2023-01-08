//
// Created by Mateusz Pryl on 06/01/2023.
//

#ifndef OOPPROJECT_REQUEST_H
#define OOPPROJECT_REQUEST_H

#include "Client.h"
#include "Library.h"
#include <vector>

#include <chrono>

//#include "date.h"

class Request {

private:

    vector<shared_ptr<Request>> requests;

    int id;

    Date date;

    string entityWhoMadeTheRequest;

    string clientUuid;

    string requestedBookName;

    string status;

public:

    Request(int id, Date date, string entityWhoMadeTheRequest, string clientUuid, string requestedBookName, string status);

    int getId();

    Date getDate();

    string getEntity();

    string getClientUuid();

    string getBookName();

    string getStatus();

    void setStatus();

};


#endif //OOPPROJECT_REQUEST_H
