//
// Created by Mateusz Pryl on 06/01/2023.
//

#include "TeacherBook.h"

TeacherBook::TeacherBook(int id, string title, string author, int pageNumber, string studyField):
        Book(id, title, author, pageNumber), studyField(studyField){

}

string TeacherBook::getUniqueTrait() {
    return std::string();
}

string TeacherBook::display() {
    return std::string();
}
