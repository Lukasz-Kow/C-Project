#include "BookFactory.h"



std::shared_ptr<Book> BookFactory::createEncyclopedia(int id, string title,
                                                      string author, int pageNumber, string theme) {

    std::shared_ptr<Encyclopedia> e = std::make_shared<Encyclopedia>(id, title, author, pageNumber, theme);
    return e;
}

std::shared_ptr<Book> createStudentBook(int id, string title,
                                        string author, int pageNumber, string subject){

    std::shared_ptr<StudentBook> s = std::make_shared<StudentBook>(id, title, author, pageNumber, subject);
    return s;

}

std::shared_ptr<Book> BookFactory::createTeacherBook(int id, string title,
                                                     string author, int pageNumber, string studyField){
    std::shared_ptr<TeacherBook> t = std::make_shared<TeacherBook>(id, title, author, pageNumber, studyField);
    return t;
}

BookFactory::BookFactory() {

}
