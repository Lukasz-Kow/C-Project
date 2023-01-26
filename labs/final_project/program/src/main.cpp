#include <iostream>


#include "Library.h"
#include "Student.h"
#include "TeacherBook.h"
#include "StudentBook.h"
#include "Teacher.h"
#include "Guest.h"
#include "Encyclopedia.h"
#include <memory>
#include "CLI.h"



int main() {

    std::shared_ptr<LibraryUI> cli = std::make_shared<CLI>();

    Library l(1, "Ninja", cli);

    /**
     * Creating books and clients
     */

    std::shared_ptr<TeacherBook> t1 = std::make_shared<TeacherBook>(1, "IT For Teachers", "Smart Teacher", 123, "IT");
    std::shared_ptr<TeacherBook> t2 = std::make_shared<TeacherBook>(2, "Math Answers", "Teacher", 423, "Math");

    std::shared_ptr<StudentBook> s1 = std::make_shared<StudentBook>(3, "Clean Code", "Robert C. Martin", 123,
                                                                    "Programming");
    std::shared_ptr<StudentBook> s2 = std::make_shared<StudentBook>(4, "Math III", "Math Professor", 423, "Math");

    std::shared_ptr<Encyclopedia> e1 = std::make_shared<Encyclopedia>(5, "worldEncyclopedia", "author5", 123, "World");
    std::shared_ptr<Encyclopedia> e2 = std::make_shared<Encyclopedia>(6, "animalEncyclopedia", "author6", 423,
                                                                      "Animals");

    std::shared_ptr<Teacher> teacher = std::make_shared<Teacher>(1, "Marek", "Kowalski", "+48 909121912", "Lodz", MALE,
                                                                 "IT");
    std::shared_ptr<Student> student = std::make_shared<Student>(2, "Bartek", "Paper", "+48 928732612", "Lodz", MALE,
                                                                 "IT");
    std::shared_ptr<Guest> guest = std::make_shared<Guest>(3, "Marta", "Paper", "+48 928111612", "Lodz", FEMALE);

    /**
     * Adding books and clients to library
     */

    l.addClient(teacher);
    l.addClient(student);
    l.addClient(guest);

    l.addBook(t1);
    l.addBook(t2);

    l.addBook(s1);
    l.addBook(s2);

    l.addBook(e1);
    l.addBook(e2);

    /**
     * Displaying books and clients
     */

    l.libraryCLI->displayBooks(l.getBooks());
    l.libraryCLI->displayClients(l.getClients());

    /**
     * Borrowing books
     */

    student->requestReservation("Clean Code", l);
    teacher->requestReservation("Math Answers", l);
    guest->requestReservation("animalEncyclopedia", l);

    /**
     * Displaying requests and books after renting
     */

    std::cout << "#############################################" << std::endl;
    std::cout << "############### AFTER REQUESTS ##############" << std::endl;
    std::cout << "#############################################" << std::endl;

    l.libraryCLI->displayRequests(l.getRequests());
    l.libraryCLI->displayBooks(l.getBooks());



    return 0;
}
