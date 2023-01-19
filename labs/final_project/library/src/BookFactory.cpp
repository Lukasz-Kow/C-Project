#include "BookFactory.h"
#include "Library.h"
#include "Client.h"
#include "Book.h"
#include "StudentBook.h"


BookFactory::BookFactory(int id, const string &name) : Library(id, name) {}

std::shared_ptr<Book> BookFactory::createEncyklopedia(int id, string title, string author, int pageNumber, string theme) {}

std::shared_ptr<Book> createStudentBook(int id, string title, string author, int pageNumber, string subject){

//    to add
//    return std::make_shared<Book>(id, title, author, pageNumber, subject);

}

std::shared_ptr<Book> BookFactory::createTeacherBook(int id, string title, string author, int pageNumber, string studyField){}