//
// Created by Mateusz Pryl on 06/01/2023.
//

#include "TeacherBook.h"
#include "sstream"
TeacherBook::TeacherBook(int id, string title, string author, int pageNumber, string studyField):
        Book(id, title, author, pageNumber), studyField(studyField){

}

string TeacherBook::getUniqueTrait() {
    return studyField;
}

string TeacherBook::display() {
    std::stringstream TeacherBookInfo;
    TeacherBookInfo << "Teacher book ID: " << getId() << endl
                     << "Title: " << getTitle() << endl
                     << "Author: " << getAuthor() << endl
                     << "Number of pages: " << getPageNumber() << endl
                     << "Study field: " << getUniqueTrait() << endl;
}
