#include <boost/test/unit_test.hpp>

// Basic object creation and initialization tests

#include "StudentBook.h"
#include "Student.h"
#include "Request.h"
#include "Library.h"
#include <vector>

BOOST_AUTO_TEST_SUITE(ObjectsInitTestSuite)

    BOOST_AUTO_TEST_CASE(BookCreation) {
        StudentBook s1(1, "Small Prince", "Antione de Saint Exupery", 300, "fantasy");

        BOOST_CHECK_EQUAL(s1.getUniqueTrait(), "fantasy");
        BOOST_CHECK_EQUAL(s1.getId(), 1);
        BOOST_CHECK_EQUAL(s1.getAuthor(), "Antione de Saint Exupery");
        BOOST_CHECK_EQUAL(s1.getPageNumber(), 300);
        BOOST_CHECK_EQUAL(s1.getTitle(), "Small Prince");
        BOOST_CHECK_EQUAL(s1.getStatus(), false);
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
        Request r1(1, "2023-12-01","Student", "fnui4q3vbuwjk4wf", "Small Prince", PROCESSING);

        BOOST_CHECK_EQUAL(r1.getId(), 1);
        BOOST_CHECK_EQUAL(r1.getStringDate(), "2023-12-01");
        BOOST_CHECK_EQUAL(r1.getEntity(), "Student");
        BOOST_CHECK_EQUAL(r1.getClientUuid(), "fnui4q3vbuwjk4wf");
        BOOST_CHECK_EQUAL(r1.getBookName(), "Small Prince");
        BOOST_CHECK_EQUAL(r1.getStatus(), PROCESSING);

    }

//    BOOST_AUTO_TEST_CASE(AddBook){
//        Library l1(1, "Happy");
//        std::shared_ptr<Book> book = std::make_shared<StudentBook>("Factfullness");
//        l1.addBook(book);

//        BOOST_CHECK_EQUAL(r1.getId(), 1);
//        BOOST_CHECK_EQUAL(r1.getStringDate(), "2023-12-01");
//        BOOST_CHECK_EQUAL(r1.getEntity(), "Student");
//        BOOST_CHECK_EQUAL(r1.getClientUuid(), "fnui4q3vbuwjk4wf");
//        BOOST_CHECK_EQUAL(r1.getBookName(), "Small Prince");
//        BOOST_CHECK_EQUAL();

//    }

BOOST_AUTO_TEST_SUITE_END()
