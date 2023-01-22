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

#include <boost/uuid/uuid.hpp>            // uuid class
#include <boost/uuid/uuid_generators.hpp> // generators
#include <boost/uuid/uuid_io.hpp>         // streaming operators etc.

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

//    BOOST_AUTO_TEST_CASE(DeletingBook) {
//        StudentBook s1(1, "Small Prince", "Antione de Saint Exupery", 300, "fantasy");
//        Encyclopedia e1(1,"AAAA", "BBBB", 400, "CCC" );
//
//        Library l1;
//
//        BOOST_CHECK_EQUAL();
//    }

    BOOST_AUTO_TEST_CASE(ClientCreation) {
        Student s1(1, "Andrzej", "Nazwisko", "+48 092919332", "Lodz", MALE, "IT");

        BOOST_CHECK_EQUAL(s1.getSpecialTrait(), "IT");
        BOOST_CHECK_EQUAL(s1.getName(), "Andrzej");
        BOOST_CHECK_EQUAL(s1.getCity(), "Lodz");
        BOOST_CHECK_EQUAL(s1.getGender(), MALE);
        BOOST_CHECK_EQUAL(s1.getPhoneNumber(), "+48 092919332");
        BOOST_CHECK_EQUAL(s1.getSurname(), "Nazwisko");

    }

    BOOST_AUTO_TEST_CASE(RequestCreation){
        boost::uuids::uuid testUuid = boost::uuids::random_generator()();
        Request r1(1, "2023-12-01", STUDENT, testUuid ,"Small Prince", PROCESSING);

        BOOST_CHECK_EQUAL(r1.getId(), 1);
        BOOST_CHECK_EQUAL(r1.getStringDate(), "2023-12-01");
        BOOST_CHECK_EQUAL(r1.getEntity(), 1);
        BOOST_CHECK_EQUAL(r1.getClientUuid(), testUuid);
        BOOST_CHECK_EQUAL(r1.getBookName(), "Small Prince");
        BOOST_CHECK_EQUAL(r1.getStatus(), PROCESSING);

    }

    BOOST_AUTO_TEST_CASE(AddBookAndMakeRequestStudent){
        Library l1(1, "Happy");
        Student s1(1, "John", "Doe", "+45 87434212312", "Lodz", MALE, "testCourse");
        BookFactory b;

        std::shared_ptr<Book> testBook1 = b.createStudentBook( 1, "title", "author", 340, "testsubject");
        l1.addBook(testBook1);
        s1.requestReservation("title", l1);
        std::shared_ptr<Book> testBook = l1.getBook(0);

        BOOST_CHECK_EQUAL(testBook->getId(), 1);
        BOOST_CHECK_EQUAL(testBook->getTitle(), "title");
        BOOST_CHECK_EQUAL(testBook->getStatus(), false);
        BOOST_CHECK_EQUAL(testBook->getAuthor(), "author");
        BOOST_CHECK_EQUAL(testBook->getPageNumber(), 340);
        BOOST_CHECK_EQUAL(testBook->getUniqueTrait(), "testsubject");

    }

    BOOST_AUTO_TEST_CASE(AddBookAndMakeRequestTeacher){
        Library l1(1, "Happy");
        Teacher t1(1, "Alice", "Doe", "+45 87434212311", "Lodz", MALE, "specialty");
        BookFactory b;

        std::shared_ptr<Book> testBook1 = b.createTeacherBook( 1, "title", "author", 340, "specialty");
        l1.addBook(testBook1);
        t1.requestReservation("title", l1);
        std::shared_ptr<Book> testBook = l1.getBook(0);

        BOOST_CHECK_EQUAL(testBook->getId(), 1);
        BOOST_CHECK_EQUAL(testBook->getTitle(), "title");
        BOOST_CHECK_EQUAL(testBook->getStatus(), false);
        BOOST_CHECK_EQUAL(testBook->getAuthor(), "author");
        BOOST_CHECK_EQUAL(testBook->getPageNumber(), 340);
        BOOST_CHECK_EQUAL(testBook->getUniqueTrait(), "specialty");

    }

    BOOST_AUTO_TEST_CASE(AddBookAndMakeRequestGuest){
        Library l1(1, "Happy");
        Guest g1(1, "Tom", "Doe", "+45 87434212311", "Lodz", MALE);
        BookFactory b;

        std::shared_ptr<Book> testBook1 = b.createEncyclopedia( 1, "title", "author", 340, "animals");
        l1.addBook(testBook1);
        g1.requestReservation("title", l1);
        std::shared_ptr<Book> testBook = l1.getBook(0);

        BOOST_CHECK_EQUAL(testBook->getId(), 1);
        BOOST_CHECK_EQUAL(testBook->getTitle(), "title");
        BOOST_CHECK_EQUAL(testBook->getStatus(), false);
        BOOST_CHECK_EQUAL(testBook->getAuthor(), "author");
        BOOST_CHECK_EQUAL(testBook->getPageNumber(), 340);
        BOOST_CHECK_EQUAL(testBook->getUniqueTrait(), "animals");

    }

    BOOST_AUTO_TEST_CASE(AddTwoBooksAndMakeTwoRequestsGuest){
        Library l1(1, "Happy");

        Student s1(1, "Tom", "Doe", "+45 87434212311", "Lodz", MALE, "testsubject");
        Student s2(2, "Mia ", "Wallace", "+45 983273838", "Los Angeles", FEMALE, "testsubject");
        Student s3(3, "Elvira ", "Hancock", "+45 983273838", "Los Angeles", FEMALE, "testsubject");

        BookFactory b;

        std::shared_ptr<Book> testBook1 = b.createStudentBook( 1, "Small Prince", "Vincent Vega", 100, "testsubject");
        std::shared_ptr<Book> testBook2 = b.createStudentBook( 2, "Small Prince", "Vincent Vega", 100, "testsubject");
        l1.addBook(testBook1);
        l1.addBook(testBook2);
        s1.requestReservation("Small Prince", l1);
        s2.requestReservation("Small Prince", l1);
        s3.requestReservation("Small Prince", l1);

        std::shared_ptr<Book> testBook1_ = l1.getBook(0);
        std::shared_ptr<Book> testBook2_ = l1.getBook(1);


        BOOST_CHECK_EQUAL(testBook1->getId(), 1);
        BOOST_CHECK_EQUAL(testBook2->getId(), 2);

        BOOST_CHECK_EQUAL(testBook1->getTitle(), "Small Prince");
        BOOST_CHECK_EQUAL(testBook2->getTitle(), "Small Prince");

        BOOST_CHECK_EQUAL(l1.getRequest(0)->getStatus(), FULFILLED);
        BOOST_CHECK_EQUAL(l1.getRequest(1)->getStatus(), FULFILLED);
        BOOST_CHECK_EQUAL(l1.getRequest(2)->getStatus(), REJECTED);

        BOOST_CHECK_EQUAL(testBook1->getAuthor(), "Vincent Vega");
        BOOST_CHECK_EQUAL(testBook2->getAuthor(), "Vincent Vega");

        BOOST_CHECK_EQUAL(testBook1->getClientUuid(), s1.getUuid());
        BOOST_CHECK_EQUAL(testBook1->getPageNumber(), 100);
        BOOST_CHECK_EQUAL(testBook2->getPageNumber(), 100);

        BOOST_CHECK_EQUAL(testBook1->getUniqueTrait(), "testsubject");
        BOOST_CHECK_EQUAL(testBook2->getUniqueTrait(), "testsubject");

    }

    BOOST_AUTO_TEST_CASE(BookExists) {
        Library l1(1, "Happy");
        StudentBook s1(1, "Small Prince", "Antione de Saint Exupery", 300, "fantasy");
        BookFactory b;

        std::shared_ptr<Book> testBook1 = b.createStudentBook( 1, "Small Prince", "Antione de Saint Exupery", 300, "fantasy");
        l1.addBook(testBook1);

        BOOST_CHECK_EQUAL(l1.bookExists("Small Prince"), 1);
    }

    BOOST_AUTO_TEST_CASE(CheckIfBookIsAvailable) {
        Library l1(1, "Happy");
        Guest g1(1, "Tom", "Doe", "+45 87434212311", "Lodz", MALE);
        BookFactory b;

        std::shared_ptr<Book> testBook1 = b.createEncyclopedia(1, "title", "author", 340, "animals");
        l1.addBook(testBook1);
        std::shared_ptr<Book> testBook2 = b.createEncyclopedia(1, "title", "author", 340, "animals");
        l1.addBook(testBook2);

        g1.requestReservation("title", l1);
        std::shared_ptr<Book> testBook1_ = l1.getBook(0);
        std::shared_ptr<Book> testBook2_ = l1.getBook(1);

        BOOST_CHECK_EQUAL(testBook1_->getStatus(), false);
        BOOST_CHECK_EQUAL(testBook2_->getStatus(), true);
    }

BOOST_AUTO_TEST_SUITE_END()
