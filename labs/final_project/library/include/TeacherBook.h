//
// Created by Mateusz Pryl on 06/01/2023.
//

#ifndef OOPPROJECT_TEACHERBOOK_H
#define OOPPROJECT_TEACHERBOOK_H

#include "Book.h"

class TeacherBook : public Book {
private:

    string studyField;

public:
    TeacherBook(int id, string title, string author, int pageNumber, string studyField);

    string getUniqueTrait() override;

    string display() override;

};


#endif //OOPPROJECT_TEACHERBOOK_H
