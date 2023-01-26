

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


BOOST_AUTO_TEST_SUITE(ClientTestSuite)



    BOOST_AUTO_TEST_CASE(StudentCreation) {
        Student s1(1, "Andrzej", "Nazwisko", "+48 092919332", "Lodz", MALE, "IT");

        BOOST_CHECK_EQUAL(s1.getSpecialTrait(), "IT");
        BOOST_CHECK_EQUAL(s1.getName(), "Andrzej");
        BOOST_CHECK_EQUAL(s1.getCity(), "Lodz");
        BOOST_CHECK_EQUAL(s1.getGender(), MALE);
        BOOST_CHECK_EQUAL(s1.getPhoneNumber(), "+48 092919332");
        BOOST_CHECK_EQUAL(s1.getSurname(), "Nazwisko");

    }

    BOOST_AUTO_TEST_CASE(TeacherCreation) {
        Teacher t1(1, "Marek", "Nazwisko", "+48 092919332", "Lodz", MALE, "IT");

        BOOST_CHECK_EQUAL(t1.getSpecialTrait(), "IT");
        BOOST_CHECK_EQUAL(t1.getName(), "Marek");
        BOOST_CHECK_EQUAL(t1.getCity(), "Lodz");
        BOOST_CHECK_EQUAL(t1.getGender(), MALE);
        BOOST_CHECK_EQUAL(t1.getPhoneNumber(), "+48 092919332");
        BOOST_CHECK_EQUAL(t1.getSurname(), "Nazwisko");

    }

    BOOST_AUTO_TEST_CASE(GuestCreation) {
        Guest g1(1, "Marek", "Nazwisko", "+48 092919332", "Lodz", MALE);

        BOOST_CHECK_EQUAL(g1.getName(), "Marek");
        BOOST_CHECK_EQUAL(g1.getCity(), "Lodz");
        BOOST_CHECK_EQUAL(g1.getGender(), MALE);
        BOOST_CHECK_EQUAL(g1.getPhoneNumber(), "+48 092919332");
        BOOST_CHECK_EQUAL(g1.getSurname(), "Nazwisko");

    }



    BOOST_AUTO_TEST_CASE(DisplayingAllClients) {
        Library l1(1, "Happy");


    }


BOOST_AUTO_TEST_SUITE_END()
