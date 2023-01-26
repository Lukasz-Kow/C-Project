

#include <boost/test/unit_test.hpp>

// Basic object creation and initialization tests

#include "StudentBook.h"
#include "Student.h"
#include "Teacher.h"
#include "Guest.h"
#include "Request.h"
#include "Library.h"
#include <vector>
#include "BookFactory.h"
#include "UnitTestUi.h"
#include <memory>



BOOST_AUTO_TEST_SUITE(ClientTestSuite)

    std::shared_ptr<UnitTestUi> ui = std::make_shared<UnitTestUi>();

    BOOST_AUTO_TEST_CASE(StudentCreation) {
        std::shared_ptr<Student> s1 = std::make_shared<Student>(1, "Andrzej", "Nazwisko", "+48 092919332", "Lodz", MALE, "IT");

        BOOST_CHECK_EQUAL(s1->getSpecialTrait(), "IT");
        BOOST_CHECK_EQUAL(s1->getName(), "Andrzej");
        BOOST_CHECK_EQUAL(s1->getCity(), "Lodz");
        BOOST_CHECK_EQUAL(s1->getGender(), MALE);
        BOOST_CHECK_EQUAL(s1->getPhoneNumber(), "+48 092919332");
        BOOST_CHECK_EQUAL(s1->getSurname(), "Nazwisko");

    }

    BOOST_AUTO_TEST_CASE(TeacherCreation) {
        std::shared_ptr<Teacher> t1 = std::make_shared<Teacher>(1, "Marek", "Nazwisko", "+48 092919332", "Lodz", MALE, "IT");

        BOOST_CHECK_EQUAL(t1->getSpecialTrait(), "IT");
        BOOST_CHECK_EQUAL(t1->getName(), "Marek");
        BOOST_CHECK_EQUAL(t1->getCity(), "Lodz");
        BOOST_CHECK_EQUAL(t1->getGender(), MALE);
        BOOST_CHECK_EQUAL(t1->getPhoneNumber(), "+48 092919332");
        BOOST_CHECK_EQUAL(t1->getSurname(), "Nazwisko");

    }

    BOOST_AUTO_TEST_CASE(GuestCreation) {
        std::shared_ptr<Guest> g1 = std::make_shared<Guest>(1, "Marek", "Nazwisko", "+48 092919332", "Lodz", MALE);

        BOOST_CHECK_EQUAL(g1->getName(), "Marek");
        BOOST_CHECK_EQUAL(g1->getCity(), "Lodz");
        BOOST_CHECK_EQUAL(g1->getGender(), MALE);
        BOOST_CHECK_EQUAL(g1->getPhoneNumber(), "+48 092919332");
        BOOST_CHECK_EQUAL(g1->getSurname(), "Nazwisko");

    }

    BOOST_AUTO_TEST_CASE(AddingClientsToLibrary) {

        Library l1(1, "Happy", ui);
        std::shared_ptr<Student> s1 = std::make_shared<Student>(1, "John", "Doe", "+45 87434212312", "Lodz", MALE, "testCourse");

        l1.addClient(s1);

        BOOST_CHECK_EQUAL(s1->getName(), "John");
        BOOST_CHECK_EQUAL(s1->getSurname(), "Doe");
        BOOST_CHECK_EQUAL(s1->getPhoneNumber(), "+45 87434212312");
        BOOST_CHECK_EQUAL(s1->getCity(), "Lodz");
        BOOST_CHECK_EQUAL(s1->getGender(), MALE);
        BOOST_CHECK_EQUAL(s1->getID(), 1);
        BOOST_CHECK_EQUAL(s1->getSpecialTrait(), "testCourse");

    }

    BOOST_AUTO_TEST_CASE(ClientsBelongingToDifferentLibraries) {

        Library l1(1, "Happy", ui);
        std::shared_ptr<Student> s1 = std::make_shared<Student>(1, "John", "Doe", "+45 87434212312", "Lodz", MALE, "testCourse");
        l1.addClient(s1);
        std::shared_ptr<Student> s2 = std::make_shared<Student>(2, "Tom", "Smith", "+45 99999999999", "Lodz", MALE, "testCourse");
        l1.addClient(s2);

        Library l2(2, "Sunshine", ui);
        std::shared_ptr<Student> s3 = std::make_shared<Student>(3, "Elle", "Brown", "+45 88888888888", "Lodz", FEMALE, "testCourse");
        l2.addClient(s3);

        BookFactory b;

        std::shared_ptr<Book> testBook1 = b.createStudentBook(1, "Small Prince", "Antione de Saint Exupery", 300, "fantasy");
        l1.addBook(testBook1);

        std::shared_ptr<Book> testBook2 = b.createStudentBook(2, "The Catcher in the Rye", "J. D. Salinger", 300, "novel");
        l2.addBook(testBook2);


        s1->requestReservation("Small Prince", l1);
        std::shared_ptr<Book> testBook1_ = l1.getBook(0);
        std::shared_ptr<Request> r1 = l1.getRequest(0);

        s2->requestReservation("The Catcher in the Rye", l2);
        std::shared_ptr<Book> testBook2_ = l2.getBook(0);
        std::shared_ptr<Request> r2 = l2.getRequest(0);

        s3->requestReservation("The Catcher in the Rye", l2);
        std::shared_ptr<Book> testBook3_ = l2.getBook(0);
        std::shared_ptr<Request> r3 = l2.getRequest(1);

        BOOST_CHECK_EQUAL(r1->getStatus(), FULFILLED);
        BOOST_CHECK_EQUAL(r2->getStatus(), REJECTED);
        BOOST_CHECK_EQUAL(r3->getStatus(), FULFILLED);

    }


BOOST_AUTO_TEST_SUITE_END()
