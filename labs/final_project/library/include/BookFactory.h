#ifndef OOPPROJECT_BOOKFACTORY_H
#define OOPPROJECT_BOOKFACTORY_H

#include "Library.h"
#include <memory>
#include <string>
#include <vector>

using namespace std;

class BookFactory : public Library {
private:

    BookFactory(int id, const string &name);

public:

    static std::shared_ptr<Book> createEncyklopedia(int id, string title, string author, int pageNumber, string theme);

    static std::shared_ptr<Book> createStudentBook(int id, string title, string author, int pageNumber, string subject);

    static std::shared_ptr<Book> createTeacherBook(int id, string title, string author, int pageNumber, string studyField);

};

#endif //OOPPROJECT_BOOKFACTORY_H
