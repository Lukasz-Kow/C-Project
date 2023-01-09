//
// Created by Mateusz Pryl on 06/01/2023.
//

#include "StudentBook.h"

StudentBook::StudentBook(int id, string title, string author, int pageNumber, string subject):
        Book(id, title, author, pageNumber), subject(subject) {

}

string StudentBook::getUniqueTrait() {
    return std::string();
}

string StudentBook::display() {
    return std::string();
}
