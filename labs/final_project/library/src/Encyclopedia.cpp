//
// Created by Mateusz Pryl on 06/01/2023.
//

#include "Encyclopedia.h"

Encyclopedia::Encyclopedia(int id, string title, string author, int pageNumber, string theme):
    Book(id, title, author, pageNumber), theme(theme) {}

string Encyclopedia::getUniqueTrait() {
    return theme;
}

string Encyclopedia::display() {
    return std::string();
}
