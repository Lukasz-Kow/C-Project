//
// Created by Mateusz Pryl on 06/01/2023.
//

#ifndef OOPPROJECT_STUDENTBOOK_H
#define OOPPROJECT_STUDENTBOOK_H

#include "Book.h"

class StudentBook : public Book{
private:

    string subject;

public:
    StudentBook(int id, string title, string author, int pageNumber, string subject);

    string getUniqueTrait() override;

    string display() override;

};


#endif //OOPPROJECT_STUDENTBOOK_H
