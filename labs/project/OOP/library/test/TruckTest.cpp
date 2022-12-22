//
// Created by Mateusz Pryl on 03/12/2022.
//
#include <boost/test/unit_test.hpp>

#include "Truck.h"
#include "Container.h"

BOOST_AUTO_TEST_SUITE(TruckSuiteCorrect)

BOOST_AUTO_TEST_CASE(Truck_Capacity_Test) {
    Truck myTruck;
    BOOST_REQUIRE_EQUAL(myTruck.getCapacity(), 2);
}

BOOST_AUTO_TEST_CASE(Truck_Size_Test) {
    Truck myTruck;
    Container myContainer(1);
    Container myContainer2(2);
    myTruck.take(myContainer);
//    myTruck.take(myContainer2);

    BOOST_REQUIRE_EQUAL(myTruck.getSize(), 1);
}

BOOST_AUTO_TEST_CASE(Truck_OverLoad_Test) {
    Truck myTruck;
    Container myContainer(1);
    Container myContainer2(2);
    Container myContainer3(3);
    myTruck.take(myContainer);
    myTruck.take(myContainer2);
    myTruck.take(myContainer3);

    BOOST_REQUIRE_EQUAL(myTruck.getSize(), 2);
}

BOOST_AUTO_TEST_CASE(Truck_at_Test) {
    Truck myTruck;
    Container myContainer(1);
    Container myContainer2(2);

    myTruck.take(myContainer);
    myTruck.take(myContainer2);

    Container returnedContainerFrom1Pos = myTruck.at(1);
    Container returnedContainerFrom2Pos = myTruck.at(2);

    BOOST_REQUIRE_EQUAL(returnedContainerFrom1Pos.getNumber(), 1);
    BOOST_REQUIRE_EQUAL(returnedContainerFrom2Pos.getNumber(), 2);
    BOOST_REQUIRE_EQUAL(myTruck.getSize(), 2);

}

BOOST_AUTO_TEST_CASE(Truck_Give_Test) {
    Truck myTruck;
    Container myContainer(1);
    Container myContainer2(2);

    myTruck.give();

    myTruck.take(myContainer);
    myTruck.take(myContainer2);

    BOOST_REQUIRE_EQUAL(myTruck.at(1).getNumber(), 1);
    BOOST_REQUIRE_EQUAL(myTruck.at(2).getNumber(), 2);

    Container returnedContainerFrom2Pos = myTruck.give();
    Container returnedContainerFrom1Pos = myTruck.give();

    std::cout << myTruck.at(2).getNumber() << std::endl;


    BOOST_REQUIRE_EQUAL(returnedContainerFrom1Pos.getNumber(), 1);
    BOOST_REQUIRE_EQUAL(returnedContainerFrom2Pos.getNumber(), 2);
    BOOST_REQUIRE_EQUAL(myTruck.getSize(), 0);

}



BOOST_AUTO_TEST_SUITE_END()

