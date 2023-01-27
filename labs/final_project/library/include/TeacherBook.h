//
// Created by Mateusz Pryl on 06/01/2023.
//

#ifndef OOPPROJECT_TEACHERBOOK_H
#define OOPPROJECT_TEACHERBOOK_H

#include "Book.h"

/**
 * Child class of Book which can be rented by teachers
 */

class TeacherBook : public Book {
private:

    std::string studyField;

public:
    TeacherBook(int id, std::string title, std::string author, int pageNumber, std::string studyField);

    std::string getUniqueTrait() override;

    std::string display() override;

};


#endif //OOPPROJECT_TEACHERBOOK_H
