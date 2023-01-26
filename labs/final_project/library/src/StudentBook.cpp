//
// Created by Mateusz Pryl on 06/01/2023.
//

#include "StudentBook.h"
#include "sstream"
StudentBook::StudentBook(int id, std::string title, std::string author, int pageNumber, std::string subject):
Book(id, title, author, pageNumber, STUDENTBOOK), subject(subject) {

}

std::string StudentBook::getUniqueTrait() {
    return subject;
}

std::string StudentBook::display() {
    std::stringstream studentBookInfo;
    studentBookInfo << "Student book ID: " << getId() << endl
                     << "Title: " << getTitle() << endl
                     << "Author: " << getAuthor() << endl
                     << "Number of pages: " << getPageNumber() << endl
                     << "Subject: " << getUniqueTrait() << endl
                     << "Is available: " << getStatus() << endl;
    return studentBookInfo.str();
}
