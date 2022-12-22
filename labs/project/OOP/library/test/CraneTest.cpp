//
// Created by student on 12/2/22.
//
#include <boost/test/unit_test.hpp>

#include "Crane.h"
#include "Truck.h"

BOOST_AUTO_TEST_SUITE(CraneSuiteCorrect)

    BOOST_AUTO_TEST_CASE(Crane_is_Parked) {
        Crane a;
        BOOST_CHECK_EQUAL(a.getPosition(), -1);
    }
    BOOST_AUTO_TEST_CASE(CraneisParked) {
        Crane a;
        BOOST_CHECK_EQUAL(a.isParked(), true);
    }

    BOOST_AUTO_TEST_CASE(checkPark_isParked) {
        Crane c;
        BOOST_CHECK_EQUAL(c.isParked(), true);
        c.forward(1);
        BOOST_CHECK_EQUAL(c.isParked(), false);
        c.park();
        BOOST_CHECK_EQUAL(c.isParked(), true);
    }

    BOOST_AUTO_TEST_CASE(checkLoad_isLoad_Unload_isUnloaded) {
        Container a(1);
        Crane b;
        Truck myTruck;
        myTruck.take(a);
        BOOST_CHECK_EQUAL(b.isLoaded(), false);

        // Loading the container from truck to the crane

        b.backward(1);
        b.loadFrom(myTruck);
        Container test = b.getContainer();
        BOOST_CHECK_EQUAL(b.isLoaded(), true);
        BOOST_CHECK_EQUAL(b.isUnloaded(), false);

    }
}

//BOOST_AUTO_TEST_CASE(isUnloaded1) {
//    Container c;
//    Crane a;
//    BOOST_CHECK_EQUAL((bool)c.getNumber(), 0);
//    BOOST_CHECK_EQUAL(a.getPosition(), -2);
//}
