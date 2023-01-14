//
// Created by Mateusz Pryl on 06/01/2023.
//

#include "StudentBook.h"
#include "sstream"
StudentBook::StudentBook(int id, string title, string author, int pageNumber, string subject):
Book(id, title, author, pageNumber), subject(subject) {

}

string StudentBook::getUniqueTrait() {
    return subject;
}

string StudentBook::display() {
    std::stringstream StudentBookInfo;
    StudentBookInfo << "Student book ID: " << getId() << endl
                     << "Title: " << getTitle() << endl
                     << "Author: " << getAuthor() << endl
                     << "Number of pages: " << getPageNumber() << endl
                     << "Subject: " << getUniqueTrait() << endl;
}
