//
// Created by Mateusz Pryl on 06/01/2023.
//

#include "TeacherBook.h"
#include "sstream"
TeacherBook::TeacherBook(int id, std::string title, std::string author, int pageNumber, std::string studyField):
        Book(id, title, author, pageNumber, TEACHERBOOK), studyField(studyField){

}

std::string TeacherBook::getUniqueTrait() {
    return studyField;
}

std::string TeacherBook::display() {
    std::stringstream teacherBookInfo;
    teacherBookInfo << "Teacher book ID: " << getId() << endl
                     << "Title: " << getTitle() << endl
                     << "Author: " << getAuthor() << endl
                     << "Number of pages: " << getPageNumber() << endl
                     << "Study field: " << getUniqueTrait() << endl;
    return teacherBookInfo.str();
}
