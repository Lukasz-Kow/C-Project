//
// Created by Mateusz Pryl on 06/01/2023.
//

#ifndef OOPPROJECT_BOOK_H
#define OOPPROJECT_BOOK_H

#include "Client.h"
#include <vector>
#include "string"

class Book {
private:

    int id;

    std::string title;

    std::string author;

    int pageNumber;

    bool isAvailable;

    std::string clientUuid;

public:

    Book(int id, string title, string author, int pageNumber);

    int getId();

    std::string getClientUuid();

    std::string getTitle();

    std::string getAuthor();

    int getPageNumber();

    bool getStatus();

    void setStatus();

    void setUuid(std::string uuid);

    virtual std::string getUniqueTrait() = 0;

    virtual std::string display() = 0;

};


#endif //OOPPROJECT_BOOK_H
