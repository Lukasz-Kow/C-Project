//
// Created by Mateusz Pryl on 06/01/2023.
//

#include "Encyclopedia.h"
#include "sstream"

Encyclopedia::Encyclopedia(int id, std::string title, std::string author, int pageNumber, std::string theme):
    Book(id, title, author, pageNumber, ENCYCLOPEDIA), theme(theme){}

std::string Encyclopedia::getUniqueTrait() {
    return theme;
}

std::string Encyclopedia::display() {
    std::stringstream encyclopediaInfo;
    encyclopediaInfo << "Encyclopedia ID: " << getId() << endl
                    << "Title: " << getTitle() << endl
                    << "Author: " << getAuthor() << endl
                    << "Number of pages: " << getPageNumber() << endl
                    << "Theme: " << getUniqueTrait() << endl;
    return encyclopediaInfo.str();
}
