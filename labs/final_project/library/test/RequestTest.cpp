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


BOOST_AUTO_TEST_SUITE(MakingRequests)

    std::shared_ptr<UnitTestUi> ui = std::make_shared<UnitTestUi>();

    BOOST_AUTO_TEST_CASE(RequestCreation){
        boost::uuids::uuid testUuid = boost::uuids::random_generator()();
        Request r1(1, STUDENT, testUuid ,"Small Prince", PROCESSING);

        BOOST_CHECK_EQUAL(r1.getId(), 1);
        BOOST_CHECK_EQUAL(r1.getEntity(), 1);
        BOOST_CHECK_EQUAL(r1.getClientUuid(), testUuid);
        BOOST_CHECK_EQUAL(r1.getBookName(), "Small Prince");
        BOOST_CHECK_EQUAL(r1.getStatus(), PROCESSING);

    }

    BOOST_AUTO_TEST_CASE(RequestProcess){
        Library l1(1, "Happy", ui);
        std::shared_ptr<Student> s1 = std::make_shared<Student>(1, "Tom", "Doe", "+45 87434212311", "Lodz", MALE, "Physics");

        l1.addClient(s1);

        BookFactory b;

        std::shared_ptr<Book> testBook1 = b.createStudentBook(1, "Small Prince", "Antione de Saint Exupery", 300, "fantasy");
        l1.addBook(testBook1);

        s1->requestReservation("Small Prince", l1);
        std::shared_ptr<Book> testBook = l1.getBook(0);
        std::shared_ptr<Request> r1 = l1.getRequest(0);

        BOOST_CHECK_EQUAL(r1->getId(), 1);
        BOOST_CHECK_EQUAL(r1->getEntity(), 1);
        BOOST_CHECK_EQUAL(r1->getClientUuid(), s1->getUuid());
        BOOST_CHECK_EQUAL(r1->getBookName(), "Small Prince");
        BOOST_CHECK_EQUAL(r1->getStatus(), FULFILLED);
    }


    BOOST_AUTO_TEST_CASE(StudentReqestsTeacherBook) {

        Library l1(1, "Happy", ui);
        std::shared_ptr<Student> s1 = std::make_shared<Student>(1, "John", "Doe", "+45 87434212312", "Lodz", MALE, "testCourse");

        l1.addClient(s1);

        BookFactory b;

        std::shared_ptr<Book> testBook1 = b.createTeacherBook(1, "ForTeachers", "author", 340, "Analysis");
        l1.addBook(testBook1);

        s1->requestReservation("ForTeachers", l1);
        std::shared_ptr<Book> testBook1_ = l1.getBook(0);

        BOOST_CHECK_EQUAL(testBook1->getStatus(), true);
        BOOST_CHECK_EQUAL(l1.getRequest(0)->getStatus(), REJECTED);
        BOOST_CHECK_EQUAL(testBook1->getUniqueTrait(), "Analysis");

    }

    BOOST_AUTO_TEST_CASE(StudentReqestsStudentBook) {

        Library l1(1, "Happy", ui);
        std::shared_ptr<Student> s1 = std::make_shared<Student>(1, "John", "Doe", "+45 87434212312", "Lodz", MALE, "testCourse");

        l1.addClient(s1);

        BookFactory b;

        std::shared_ptr<Book> testBook1 = b.createStudentBook(1, "ForStudents", "author", 340, "BasicsOfAnalysis");
        l1.addBook(testBook1);

        s1->requestReservation("ForStudents", l1);
        std::shared_ptr<Book> testBook = l1.getBook(0);

        BOOST_CHECK_EQUAL(testBook->getStatus(), false);
        BOOST_CHECK_EQUAL(l1.getRequest(0)->getStatus(), FULFILLED);
        BOOST_CHECK_EQUAL(testBook->getUniqueTrait(), "BasicsOfAnalysis");

}

    BOOST_AUTO_TEST_CASE(StudentReqestsEncyclopedia) {

        Library l1(1, "Happy", ui);
        std::shared_ptr<Student> s1 = std::make_shared<Student>(1, "John", "Doe", "+45 87434212312", "Lodz", MALE, "testCourse");

        l1.addClient(s1);

        BookFactory b;

        std::shared_ptr<Book> testBook1 = b.createEncyclopedia( 1, "HumanEncyclopedia", "author", 340, "Human");
        l1.addBook(testBook1);

        s1->requestReservation("HumanEncyclopedia", l1);
        std::shared_ptr<Book> testBook= l1.getBook(0);

        BOOST_CHECK_EQUAL(testBook->getStatus(), false);
        BOOST_CHECK_EQUAL(l1.getRequest(0)->getStatus(), FULFILLED);
        BOOST_CHECK_EQUAL(testBook->getUniqueTrait(), "Human");
    }

    BOOST_AUTO_TEST_CASE(GuestReqestsTeacherBook) {

        Library l1(1, "Happy", ui);
        std::shared_ptr<Guest> g1 = std::make_shared<Guest>(1, "John", "Doe", "+45 87434212312", "Lodz", MALE);

        l1.addClient(g1);

        BookFactory b;

        std::shared_ptr<Book> testBook1 = b.createTeacherBook( 1, "title", "author", 340, "Analysis");
        l1.addBook(testBook1);

        g1->requestReservation("title", l1);
        std::shared_ptr<Book> testBook = l1.getBook(0);

        BOOST_CHECK_EQUAL(testBook1->getStatus(), true);
        BOOST_CHECK_EQUAL(l1.getRequest(0)->getStatus(), REJECTED);
        BOOST_CHECK_EQUAL(testBook1->getUniqueTrait(), "Analysis");

    }

    BOOST_AUTO_TEST_CASE(GuestReqestsStudentBook) {

        Library l1(1, "Happy", ui);
        std::shared_ptr<Guest> g1 = std::make_shared<Guest>(1, "John", "Doe", "+45 87434212312", "Lodz", MALE);

        l1.addClient(g1);

        BookFactory b;

        std::shared_ptr<Book> testBook1 = b.createStudentBook(1, "title", "author", 340, "Analysis");
        l1.addBook(testBook1);

        g1->requestReservation("title", l1);
        std::shared_ptr<Book> testBook = l1.getBook(0);

        BOOST_CHECK_EQUAL(testBook1->getStatus(), false);
        BOOST_CHECK_EQUAL(l1.getRequest(0)->getStatus(), FULFILLED);
        BOOST_CHECK_EQUAL(testBook1->getUniqueTrait(), "Analysis");

    }

    BOOST_AUTO_TEST_CASE(TeacherReqestsStudentBook) {

        Library l1(1, "Happy", ui);
        std::shared_ptr<Teacher> t1 = std::make_shared<Teacher>(1, "John", "Doe", "+45 87434212312", "Lodz", MALE, "Maths");

        l1.addClient(t1);

        BookFactory b;

        std::shared_ptr<Book> testBook1 = b.createStudentBook( 1, "title", "author", 340, "Analysis");
        l1.addBook(testBook1);

        t1->requestReservation("title", l1);
        std::shared_ptr<Book> testBook = l1.getBook(0);

        BOOST_CHECK_EQUAL(testBook1->getStatus(), false);
        BOOST_CHECK_EQUAL(l1.getRequest(0)->getStatus(), FULFILLED);
        BOOST_CHECK_EQUAL(testBook1->getUniqueTrait(), "Analysis");

    }




BOOST_AUTO_TEST_SUITE_END()