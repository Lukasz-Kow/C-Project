//
// Created by Mateusz Pryl on 06/01/2023.
//

#ifndef OOPPROJECT_STUDENTBOOK_H
#define OOPPROJECT_STUDENTBOOK_H

#include "Book.h"

/**
 * Child class of Book which can be rented by students and teachers
 */

class StudentBook : public Book{
private:

    std::string subject;

public:
    StudentBook(int id, std::string title, std::string author, int pageNumber, std::string subject);

    std::string getUniqueTrait() override;

    std::string display() override;

};


#endif //OOPPROJECT_STUDENTBOOK_H
