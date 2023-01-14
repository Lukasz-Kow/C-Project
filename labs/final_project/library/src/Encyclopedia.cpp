//
// Created by Mateusz Pryl on 06/01/2023.
//

#include "Encyclopedia.h"
#include "sstream"
Encyclopedia::Encyclopedia(int id, string title, string author, int pageNumber, string theme):
    Book(id, title, author, pageNumber), theme(theme) {}

string Encyclopedia::getUniqueTrait() {
    return theme;
}

string Encyclopedia::display() {
    std::stringstream EncyclopediaInfo;
    EncyclopediaInfo << "Encyclopedia ID: " << getId() << endl
    << "Title: " << getTitle() << endl
    << "Author: " << getAuthor() << endl
    << "Number of pages: " << getPageNumber() << endl
    << "Theme: " << getUniqueTrait() << endl;

}
