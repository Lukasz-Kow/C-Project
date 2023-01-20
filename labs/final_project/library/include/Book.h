//
// Created by Mateusz Pryl on 06/01/2023.
//

#ifndef OOPPROJECT_BOOK_H
#define OOPPROJECT_BOOK_H

#include "Client.h"
#include <vector>
#include "string"

#include <boost/uuid/uuid.hpp>            // uuid class
#include <boost/uuid/uuid_generators.hpp> // generators
#include <boost/uuid/uuid_io.hpp>         // streaming operators etc.
class Book {
private:

    int id;

    boost::uuids::uuid bookUuid;

    std::string title;

    std::string author;

    int pageNumber;

    bool isAvailable;

    boost::uuids::uuid clientUuid;

public:

    Book(int id, std::string title, std::string author, int pageNumber);

    int getId();

    boost::uuids::uuid getClientUuid();

    std::string getTitle();

    std::string getAuthor();

    int getPageNumber();

    bool getStatus();

    void setStatus(bool newStatus);

    void setUuid(boost::uuids::uuid uuid);

    virtual std::string getUniqueTrait() = 0;

    virtual std::string display() = 0;

};


#endif //OOPPROJECT_BOOK_H
