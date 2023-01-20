#include <boost/test/unit_test.hpp>

// Basic object creation and initialization tests

#include "StudentBook.h"
#include "Student.h"
#include "Teacher.h"
#include "TeacherBook.h"
#include "Guest.h"
#include "Encyclopedia.h"
#include "Request.h"
#include "Library.h"
#include <vector>
#include "BookFactory.h"

BOOST_AUTO_TEST_SUITE(ObjectsInitTestSuite)

    BOOST_AUTO_TEST_CASE(BookCreation) {
        StudentBook s1(1, "Small Prince", "Antione de Saint Exupery", 300, "fantasy");

        BOOST_CHECK_EQUAL(s1.getUniqueTrait(), "fantasy");
        BOOST_CHECK_EQUAL(s1.getId(), 1);
        BOOST_CHECK_EQUAL(s1.getAuthor(), "Antione de Saint Exupery");
        BOOST_CHECK_EQUAL(s1.getPageNumber(), 300);
        BOOST_CHECK_EQUAL(s1.getTitle(), "Small Prince");
        BOOST_CHECK_EQUAL(s1.getStatus(), true);
    }

    BOOST_AUTO_TEST_CASE(ClientCreation) {
        Student s1(1, "fnui4q3vbuwjk4wf", "Andrzej", "Nazwisko", "+48 092919332", "Lodz", MALE, "IT");

        BOOST_CHECK_EQUAL(s1.getUuid(), "fnui4q3vbuwjk4wf");
        BOOST_CHECK_EQUAL(s1.getSpecialTrait(), "IT");
        BOOST_CHECK_EQUAL(s1.getName(), "Andrzej");
        BOOST_CHECK_EQUAL(s1.getCity(), "Lodz");
        BOOST_CHECK_EQUAL(s1.getGender(), MALE);
        BOOST_CHECK_EQUAL(s1.getPhoneNumber(), "+48 092919332");
        BOOST_CHECK_EQUAL(s1.getSurname(), "Nazwisko");

    }

    BOOST_AUTO_TEST_CASE(RequestCreation){
        Request r1(1, "2023-12-01", STUDENT, "fnui4q3vbuwjk4wf", "Small Prince", PROCESSING);

        BOOST_CHECK_EQUAL(r1.getId(), 1);
        BOOST_CHECK_EQUAL(r1.getStringDate(), "2023-12-01");
        BOOST_CHECK_EQUAL(r1.getEntity(), 1);
        BOOST_CHECK_EQUAL(r1.getClientUuid(), "fnui4q3vbuwjk4wf");
        BOOST_CHECK_EQUAL(r1.getBookName(), "Small Prince");
        BOOST_CHECK_EQUAL(r1.getStatus(), PROCESSING);

    }

    BOOST_AUTO_TEST_CASE(AddBookAndMakeRequestStudent){
        Library l1(1, "Happy");
        Student s1(1, "444444rsr344rfw", "John", "Doe", "+45 87434212312", "Lodz", MALE, "testCourse");
        BookFactory b;

        std::shared_ptr<Book> testBook1 = b.createStudentBook( 1, "title", "author", 340, "testsubject");
        l1.addBook(testBook1);
        s1.requestReservation("testbook", l1);
        std::shared_ptr<Book> testBook = l1.getBook(0);

        BOOST_CHECK_EQUAL(testBook->getId(), 1);
        BOOST_CHECK_EQUAL(testBook->getTitle(), "title");
        BOOST_CHECK_EQUAL(testBook->getStatus(), true);
        BOOST_CHECK_EQUAL(testBook->getAuthor(), "author");
//        BOOST_CHECK_EQUAL(testBook->getClientUuid(), "444444rsr344rfw");
//        BOOST_CHECK_EQUAL(testBook->getPageNumber(), 340);
        BOOST_CHECK_EQUAL(testBook->getUniqueTrait(), "testsubject");

    }

    BOOST_AUTO_TEST_CASE(AddBookAndMakeRequestTeacher){
        Library l1(1, "Happy");
        Teacher t1(1, "444444rsr344rfw", "Alice", "Doe", "+45 87434212311", "Lodz", MALE, "specialty");
        BookFactory b;

        std::shared_ptr<Book> testBook1 = b.createTeacherBook( 1, "title", "author", 340, "specialty");
        l1.addBook(testBook1);
        t1.requestReservation("testbook", l1);
        std::shared_ptr<Book> testBook = l1.getBook(0);

        BOOST_CHECK_EQUAL(testBook->getId(), 1);
        BOOST_CHECK_EQUAL(testBook->getTitle(), "title");
        BOOST_CHECK_EQUAL(testBook->getStatus(), true);
        BOOST_CHECK_EQUAL(testBook->getAuthor(), "author");
//        BOOST_CHECK_EQUAL(testBook->getClientUuid(), "444444rsr344rfw");
        BOOST_CHECK_EQUAL(testBook->getPageNumber(), 340);
        BOOST_CHECK_EQUAL(testBook->getUniqueTrait(), "specialty");

    }

    BOOST_AUTO_TEST_CASE(AddBookAndMakeRequestGuest){
        Library l1(1, "Happy");
        Guest g1(1, "444444rsr344rfw", "Tom", "Doe", "+45 87434212311", "Lodz", MALE);
        BookFactory b;

        std::shared_ptr<Book> testBook1 = b.createEncyclopedia( 1, "title", "author", 340, "animals");
        l1.addBook(testBook1);
        g1.requestReservation("testbook", l1);
        std::shared_ptr<Book> testBook = l1.getBook(0);

        BOOST_CHECK_EQUAL(testBook->getId(), 1);
        BOOST_CHECK_EQUAL(testBook->getTitle(), "title");
        BOOST_CHECK_EQUAL(testBook->getStatus(), true);
        BOOST_CHECK_EQUAL(testBook->getAuthor(), "author");
//        BOOST_CHECK_EQUAL(testBook->getClientUuid(), "444444rsr344rfw");
        BOOST_CHECK_EQUAL(testBook->getPageNumber(), 340);
        BOOST_CHECK_EQUAL(testBook->getUniqueTrait(), "animals");

    }

    BOOST_AUTO_TEST_CASE(AddTwoBooksAndMakeTwoRequestsGuest){
        Library l1(1, "Happy");
        Student s1(1, "444444rsr344rfw", "Tom", "Doe", "+45 87434212311", "Lodz", MALE, "Literature");
        Student s2(2, "uuid", "Mia ", "Wallace", "+45 983273838", "Los Angeles", FEMALE, "Movies");
        Student s3(3, "uuid", "Elvira ", "Hancock", "+45 983273838", "Los Angeles", FEMALE, "Movies");


        BookFactory b;

        std::shared_ptr<Book> testBook1 = b.createStudentBook( 1, "MoviesOverview", "Vincent Vega", 100, "Movies");
        std::shared_ptr<Book> testBook2 = b.createStudentBook( 2, "MoviesOverview", "Vincent Vega", 100, "Movies");
        l1.addBook(testBook1);
        l1.addBook(testBook2);
        s1.requestReservation("MoviesOverview", l1);
        s2.requestReservation("MoviesOverview", l1);
        s3.requestReservation("MoviesOverview", l1);

        std::shared_ptr<Book> testBook1_ = l1.getBook(0);
        std::shared_ptr<Book> testBook2_ = l1.getBook(1);


        BOOST_CHECK_EQUAL(testBook1->getId(), 1);
        BOOST_CHECK_EQUAL(testBook2->getId(), 2);

        BOOST_CHECK_EQUAL(testBook1->getTitle(), "MoviesOverview");
        BOOST_CHECK_EQUAL(testBook2->getTitle(), "MoviesOverview");

        BOOST_CHECK_EQUAL(testBook1->getStatus(), false);
        BOOST_CHECK_EQUAL(testBook2->getStatus(), false);


        BOOST_CHECK_EQUAL(testBook1->getAuthor(), "Vincent Vega");
        BOOST_CHECK_EQUAL(testBook2->getAuthor(), "Vincent Vega");

//        BOOST_CHECK_EQUAL(testBook->getClientUuid(), "444444rsr344rfw");
        BOOST_CHECK_EQUAL(testBook1->getPageNumber(), 100);
        BOOST_CHECK_EQUAL(testBook2->getPageNumber(), 100);

        BOOST_CHECK_EQUAL(testBook1->getUniqueTrait(), "Movies");
        BOOST_CHECK_EQUAL(testBook2->getUniqueTrait(), "Movies");

    }

    BOOST_AUTO_TEST_CASE(StudentRequestsTeacherBook){
        Library l1(1, "Happy");
        Student s1(1, "444444rsr344rfw", "Tom", "Doe", "+45 87434212311", "Lodz", MALE, "Physics");
        BookFactory b;

        std::shared_ptr<Book> testBook1 = b.createTeacherBook( 1, "title", "author", 340, "Analysis");
        l1.addBook(testBook1);
        s1.requestReservation("Analysis", l1);
        std::shared_ptr<Book> testBook = l1.getBook(0);

        BOOST_CHECK_EQUAL(testBook1->getStatus(), true);

    }

    BOOST_AUTO_TEST_CASE(BookExists) {
        Library l1(1, "Happy");
        StudentBook s1(1, "Small Prince", "Antione de Saint Exupery", 300, "fantasy");
        BookFactory b;

        std::shared_ptr<Book> testBook1 = b.createStudentBook( 1, "Baking", "Zoe", 100, "Baking");
        l1.addBook(testBook1);

// to fix
//        BOOST_CHECK_EQUAL(l1.bookExists("Small Prince"), 1);
    }

BOOST_AUTO_TEST_SUITE_END()
