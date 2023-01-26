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

    BOOST_AUTO_TEST_CASE(StudentBookCreation) {
        StudentBook s1(1, "Small Prince", "Antione de Saint Exupery", 300, "fantasy");

        BOOST_CHECK_EQUAL(s1.getUniqueTrait(), "fantasy");
        BOOST_CHECK_EQUAL(s1.getId(), 1);
        BOOST_CHECK_EQUAL(s1.getAuthor(), "Antione de Saint Exupery");
        BOOST_CHECK_EQUAL(s1.getPageNumber(), 300);
        BOOST_CHECK_EQUAL(s1.getTitle(), "Small Prince");
        BOOST_CHECK_EQUAL(s1.getStatus(), true);
    }

    BOOST_AUTO_TEST_CASE(TeacherBookCreation) {
        TeacherBook t1(1, "Math III", "Vincent Vega", 200,"teststudyField");

        BOOST_CHECK_EQUAL(t1.getUniqueTrait(), "teststudyField");
        BOOST_CHECK_EQUAL(t1.getId(), 1);
        BOOST_CHECK_EQUAL(t1.getAuthor(), "Vincent Vega");
        BOOST_CHECK_EQUAL(t1.getPageNumber(), 200);
        BOOST_CHECK_EQUAL(t1.getTitle(), "Math III");
        BOOST_CHECK_EQUAL(t1.getStatus(), true);
    }

    BOOST_AUTO_TEST_CASE(EncyclopediaCreation) {
        Encyclopedia e1(1, "Encyclopedia", "Vincent Vega", 200,"teststudyField");

        BOOST_CHECK_EQUAL(e1.getUniqueTrait(), "teststudyField");
        BOOST_CHECK_EQUAL(e1.getId(), 1);
        BOOST_CHECK_EQUAL(e1.getAuthor(), "Vincent Vega");
        BOOST_CHECK_EQUAL(e1.getPageNumber(), 200);
        BOOST_CHECK_EQUAL(e1.getTitle(), "Encyclopedia");
        BOOST_CHECK_EQUAL(e1.getStatus(), true);
    }

    BOOST_AUTO_TEST_CASE(DeletingBook) {
        Library l1(1, "Happy");

        BookFactory b;

        std::shared_ptr<Book> testBook1 = b.createStudentBook( 1, "Small Prince", "Vincent Vega", 100, "testsubject");
        std::shared_ptr<Book> testBook2 = b.createStudentBook( 2, "Small Prince2", "Vincent Vega", 150, "testsubject");

        std::shared_ptr<Book> testBook3 = b.createTeacherBook( 3, "Math III", "Vincent Vega", 200,"teststudyField");

        l1.addBook(testBook1);
        l1.addBook(testBook2);
        l1.addBook(testBook3);

        l1.removeBook(2);

        std::shared_ptr<Book> testBook1_ = l1.getBook(0);
        std::shared_ptr<Book> testBook2_ = l1.getBook(1);


        BOOST_CHECK_EQUAL(testBook1_->getId(), 1);
        BOOST_CHECK_EQUAL(testBook2_->getId(), 3);

    }

    //not finished
    BOOST_AUTO_TEST_CASE(DisplayingAllBooksCreated) {
        Library l1(1, "Happy");

        BookFactory b;

        std::shared_ptr<Book> testBook1 = b.createStudentBook( 1, "Small Prince", "Vincent Vega", 100, "testsubject");
        std::shared_ptr<Book> testBook2 = b.createStudentBook( 2, "Small Prince", "Vincent Vega", 150, "testsubject");

        std::shared_ptr<Book> testBook3 = b.createTeacherBook( 3, "Math III", "Vincent Vega", 200,"teststudyField");

        std::shared_ptr<Book> testBook4 = b.createEncyclopedia( 4, "Encyclopedia of Life", "testAuthor", 500,"testTheme");

        l1.addBook(testBook1);
        l1.addBook(testBook2);
        l1.addBook(testBook3);
        l1.addBook(testBook4);


    }

BOOST_AUTO_TEST_SUITE_END()
