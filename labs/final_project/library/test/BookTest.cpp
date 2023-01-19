#include <boost/test/unit_test.hpp>

// Basic object creation and initialization tests

#include "StudentBook.h"
#include "Student.h"
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

    BOOST_AUTO_TEST_CASE(AddBookAndMakeRequest){
        Library l1(1, "Happy");
        Student s1(1, "444444rsr344rfw", "John", "Doe", "+45 87434212312", "Lodz", MALE, "testCourse");
//        BookFactory b;

//        BookFactory doesn't work for some reason
        std::shared_ptr<Book> testBook1 = std::make_shared<StudentBook>(1, "title", "author", 340, "testsubject");
        l1.addBook(testBook1);
        s1.requestReservation("testbook", l1);
        std::shared_ptr<Book> testBook = l1.getBook(0);

        BOOST_CHECK_EQUAL(testBook->getId(), 1);
        BOOST_CHECK_EQUAL(testBook->getTitle(), "title");
        BOOST_CHECK_EQUAL(testBook->getStatus(), true);
        BOOST_CHECK_EQUAL(testBook->getAuthor(), "author");
        BOOST_CHECK_EQUAL(testBook->getClientUuid(), "");
        BOOST_CHECK_EQUAL(testBook->getPageNumber(), 340);
        BOOST_CHECK_EQUAL(testBook->getUniqueTrait(), "testsubject");

    }

BOOST_AUTO_TEST_SUITE_END()
