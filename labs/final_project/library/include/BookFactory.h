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

    std::shared_ptr<Book> createEncyclopedia(int id, string title, string author, int pageNumber, string theme);

    std::shared_ptr<Book> createStudentBook(int id, string title, string author, int pageNumber, string subject);

    std::shared_ptr<Book> createTeacherBook(int id, string title, string author, int pageNumber, string studyField);

};

#endif //OOPPROJECT_BOOKFACTORY_H
