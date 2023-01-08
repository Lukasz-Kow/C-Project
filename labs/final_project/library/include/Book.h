//
// Created by Mateusz Pryl on 06/01/2023.
//

#ifndef OOPPROJECT_BOOK_H
#define OOPPROJECT_BOOK_H

#include "Client.h"
#include <vector>

class Book {
private:

    vector<shared_ptr<Book>> bookCollection;

    int id;

    string title;

    string author;

    int pageNumber;

    string clientUuid;

    bool isAvailable;

public:

    Book(int id, string title, string author, int phoneNumber);

    int getId();

    string getClientUuid();

    string getTitle();

    int getPageNumber();

    bool getStatus();

    void getStatus();

    void setClientUuid();

    virtual string getUniqueTrait() = 0;

    virtual string display() = 0;

};


#endif //OOPPROJECT_BOOK_H
