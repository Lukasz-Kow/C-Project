#include <iostream>

using namespace std;

#include "Library.h"
#include "Student.h"
#include "TeacherBook.h"
#include <memory>


// int id, std::string uuid, std::string name, std::string surname, std::string phoneNumber, std::string city, Gender gender, std::string course

int main() {

    Library l(1, "Ninja");
    std::shared_ptr<TeacherBook> t1 = std::make_shared<TeacherBook>(1, "title", "author", 123, "subject");
    std::shared_ptr<TeacherBook> t2 = std::make_shared<TeacherBook>(2, "title2", "author2", 423, "subject2");

    l.addBook(t1);
    l.addBook(t2);

    Student s1(1, "uuid", "name", "surname", "phone", "city", MALE, "course");
//    int test = l.findAvailableBookId("title2");
    s1.requestReservation("title", l);

    return 0;
}
