

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
#include "UnitTestUi.h"
#include <memory>

BOOST_AUTO_TEST_SUITE(LibraryTestSuite)

    std::shared_ptr<UnitTestUi> ui = std::make_shared<UnitTestUi>();

    BOOST_AUTO_TEST_CASE(AddBookAndMakeRequestStudent){
        Library l1(1, "Happy", ui);
        std::shared_ptr<Student> s1 = std::make_shared<Student>(1, "John", "Doe", "+45 87434212312", "Lodz", MALE, "testCourse");

        l1.addClient(s1);

        BookFactory b;

        std::shared_ptr<Book> testBook1 = b.createStudentBook( 1, "title", "author", 340, "testsubject");
        l1.addBook(testBook1);
        s1->requestReservation("title", l1);
        std::shared_ptr<Book> testBook = l1.getBook(0);

        BOOST_CHECK_EQUAL(testBook->getId(), 1);
        BOOST_CHECK_EQUAL(testBook->getTitle(), "title");
        BOOST_CHECK_EQUAL(testBook->getStatus(), false);
        BOOST_CHECK_EQUAL(testBook->getAuthor(), "author");
        BOOST_CHECK_EQUAL(testBook->getPageNumber(), 340);
        BOOST_CHECK_EQUAL(testBook->getUniqueTrait(), "testsubject");

    }

    BOOST_AUTO_TEST_CASE(AddBookAndMakeRequestTeacher){
        Library l1(1, "Happy", ui);
        std::shared_ptr<Teacher> t1 = std::make_shared<Teacher>(1, "Alice", "Doe", "+45 87434212311", "Lodz", MALE, "specialty");

        l1.addClient(t1);

        BookFactory b;

        std::shared_ptr<Book> testBook1 = b.createTeacherBook( 1, "title", "author", 340, "specialty");
        l1.addBook(testBook1);
        t1->requestReservation("title", l1);
        std::shared_ptr<Book> testBook = l1.getBook(0);

        BOOST_CHECK_EQUAL(testBook->getId(), 1);
        BOOST_CHECK_EQUAL(testBook->getTitle(), "title");
        BOOST_CHECK_EQUAL(testBook->getStatus(), false);
        BOOST_CHECK_EQUAL(testBook->getAuthor(), "author");
        BOOST_CHECK_EQUAL(testBook->getPageNumber(), 340);
        BOOST_CHECK_EQUAL(testBook->getUniqueTrait(), "specialty");

    }

    BOOST_AUTO_TEST_CASE(AddBookAndMakeRequestGuest){
        Library l1(1, "Happy", ui);
        std::shared_ptr<Guest> g1 = std::make_shared<Guest>(1, "Tom", "Doe", "+45 87434212311", "Lodz", MALE);

        l1.addClient(g1);

        BookFactory b;

        std::shared_ptr<Book> testBook1 = b.createEncyclopedia( 1, "title", "author", 340, "animals");
        l1.addBook(testBook1);
        g1->requestReservation("title", l1);
        std::shared_ptr<Book> testBook = l1.getBook(0);

        BOOST_CHECK_EQUAL(testBook->getId(), 1);
        BOOST_CHECK_EQUAL(testBook->getTitle(), "title");
        BOOST_CHECK_EQUAL(testBook->getStatus(), false);
        BOOST_CHECK_EQUAL(testBook->getAuthor(), "author");
        BOOST_CHECK_EQUAL(testBook->getPageNumber(), 340);
        BOOST_CHECK_EQUAL(testBook->getUniqueTrait(), "animals");

    }

    BOOST_AUTO_TEST_CASE(AddTwoBooksAndMakeTwoRequestsGuest){
        Library l1(1, "Happy", ui);

        std::shared_ptr<Student> s1 = std::make_shared<Student>(1, "Tom", "Doe", "+45 87434212311", "Lodz", MALE, "testsubject");
        std::shared_ptr<Student> s2 = std::make_shared<Student>(2, "Mia ", "Wallace", "+45 983273838", "Los Angeles", FEMALE, "testsubject");
        std::shared_ptr<Student> s3 = std::make_shared<Student>(3, "Elvira ", "Hancock", "+45 983273838", "Los Angeles", FEMALE, "testsubject");

        l1.addClient(s1);
        l1.addClient(s2);
        l1.addClient(s3);

        BookFactory b;

        std::shared_ptr<Book> testBook1 = b.createStudentBook(1, "Small Prince", "Vincent Vega", 100, "testsubject");
        std::shared_ptr<Book> testBook2 = b.createStudentBook(2, "Small Prince", "Vincent Vega", 100, "testsubject");
        l1.addBook(testBook1);
        l1.addBook(testBook2);
        s1->requestReservation("Small Prince", l1);
        s2->requestReservation("Small Prince", l1);
        s3->requestReservation("Small Prince", l1);

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

        BOOST_CHECK_EQUAL(testBook1->getClientUuid(), s1->getUuid());
        BOOST_CHECK_EQUAL(testBook1->getPageNumber(), 100);
        BOOST_CHECK_EQUAL(testBook2->getPageNumber(), 100);

        BOOST_CHECK_EQUAL(testBook1->getUniqueTrait(), "testsubject");
        BOOST_CHECK_EQUAL(testBook2->getUniqueTrait(), "testsubject");

    }


    BOOST_AUTO_TEST_CASE(CheckIfBookIsAvailableAfterReservation) {
        Library l1(1, "Happy", ui);

        std::shared_ptr<Guest> g1 = std::make_shared<Guest>(1, "Tom", "Doe", "+45 87434212311", "Lodz", MALE);

        l1.addClient(g1);

        BookFactory b;

        std::shared_ptr<Book> testBook1 = b.createEncyclopedia(1, "title", "author", 340, "animals");
        l1.addBook(testBook1);
        std::shared_ptr<Book> testBook2 = b.createEncyclopedia(2, "title", "author", 340, "animals");
        l1.addBook(testBook2);

        g1->requestReservation("title", l1);
        std::shared_ptr<Book> testBook1_ = l1.getBook(0);
        std::shared_ptr<Book> testBook2_ = l1.getBook(1);

        BOOST_CHECK_EQUAL(testBook1_->getStatus(), false);
        BOOST_CHECK_EQUAL(testBook2_->getStatus(), true);
    }

    BOOST_AUTO_TEST_CASE(CheckAvailableBookIndex) {

        Library l1(1, "Happy", ui);
        std::shared_ptr<Student> s1 = std::make_shared<Student>(1, "John", "Doe", "+45 87434212312", "Lodz", MALE, "Maths");

        l1.addClient(s1);

        BookFactory b;

        std::shared_ptr<Book> testBook1 = b.createStudentBook( 1, "title", "author", 340, "Analysis");
        l1.addBook(testBook1);
        std::shared_ptr<Book> testBook2 = b.createStudentBook( 2, "title", "author", 340, "Analysis");
        l1.addBook(testBook2);

        std::shared_ptr<Book> testBook1_ = l1.getBook(0);
        s1->requestReservation("title", l1);

        std::shared_ptr<Book> testBook2_ = l1.getBook(1);

        BOOST_CHECK_EQUAL(testBook1_->getStatus(), false);
        BOOST_CHECK_EQUAL(testBook2_->getStatus(), true);
        BOOST_CHECK_EQUAL(l1.findAvailableBookIndex("title"), 1);
        BOOST_CHECK_EQUAL(testBook1->getUniqueTrait(), "Analysis");

    }

    BOOST_AUTO_TEST_CASE(BookReservationIsFinished) {

        Library l1(1, "Happy", ui);
        std::shared_ptr<Teacher> t1 = std::make_shared<Teacher>(1, "John", "Doe", "+45 87434212312", "Lodz", MALE, "Maths");

        l1.addClient(t1);

        BookFactory b;

        std::shared_ptr<Book> testBook1 = b.createStudentBook(1, "title", "author", 340, "Analysis");
        l1.addBook(testBook1);

        t1->requestReservation("title", l1);
        std::shared_ptr<Book> testBook = l1.getBook(0);

        BOOST_CHECK_EQUAL(testBook1->getStatus(), false);
        BOOST_CHECK_EQUAL(l1.getRequest(0)->getStatus(), FULFILLED);

        l1.finishReservation(testBook1->getId());

        BOOST_CHECK_EQUAL(testBook1->getStatus(), true);
        // getting boost null uuid
        BOOST_CHECK_EQUAL(testBook1->getClientUuid(), boost::uuids::nil_uuid());

    }

    BOOST_AUTO_TEST_CASE(LibraryUITest) {


        Library l1(1, "Happy", ui);

        l1.libraryCLI->displayBooks(l1.getBooks());
        l1.libraryCLI->displayRequests(l1.getRequests());
        l1.libraryCLI->displayClients(l1.getClients());


    }


BOOST_AUTO_TEST_SUITE_END()
