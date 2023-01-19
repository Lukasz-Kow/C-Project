#include "BookFactory.h"
#include "Library.h"
#include "Client.h"
#include "Book.h"

BookFactory::BookFactory(int id, const string &name) : Library(id, name) {}

std::shared_ptr<Book> BookFactory::createEncyklopedia(int id, string title, string author, int pageNumber, string theme) {}

std::shared_ptr<Book> BookFactory::createStudentBook(int id, string title, string author, int pageNumber, string subject){}

std::shared_ptr<Book> BookFactory::createTeacherBook(int id, string title, string author, int pageNumber, string studyField){}