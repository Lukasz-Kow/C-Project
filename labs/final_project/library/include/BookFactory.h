#ifndef OOPPROJECT_BOOKFACTORY_H
#define OOPPROJECT_BOOKFACTORY_H

#include "Library.h"
#include <memory>
#include <string>
#include <vector>
#include "BookFactory.h"
#include "Client.h"
#include "Book.h"
#include "StudentBook.h"
#include "Encyclopedia.h"
#include "TeacherBook.h"

using namespace std;

class BookFactory {
private:
public:

    BookFactory();

    std::shared_ptr<Book> createEncyclopedia(int id, std::string title, std::string author, int pageNumber, std::string theme);

    std::shared_ptr<Book> createStudentBook(int id, std::string title, std::string author, int pageNumber, std::string subject);

    std::shared_ptr<Book> createTeacherBook(int id, std::string title, std::string author, int pageNumber, std::string studyField);

};

#endif //OOPPROJECT_BOOKFACTORY_H
