#include <boost/test/unit_test.hpp>

#include "Container.h"

BOOST_AUTO_TEST_SUITE(ContainerSuiteCorrect)

BOOST_AUTO_TEST_CASE(ContainerInitalizeWithNumber) {
    Container container(1);
    BOOST_REQUIRE_EQUAL(container.getNumber(), 1);
    BOOST_REQUIRE_EQUAL(container.getTare(), 0.0);
    BOOST_REQUIRE_EQUAL(container.getMaxWeight(), 0.0);
    BOOST_REQUIRE_EQUAL(container.getNetWeight(), 0.0);
    BOOST_REQUIRE_CLOSE_FRACTION(container.getGrossWeight(), 0.0, 0.00001);
}

BOOST_AUTO_TEST_CASE(ContainerWithoutNumber) {
    Container container;
    BOOST_REQUIRE_EQUAL(container.getNumber(), 0);
    BOOST_REQUIRE_EQUAL(container.getTare(), 0.0);
    BOOST_REQUIRE_EQUAL(container.getMaxWeight(), 0.0);
    BOOST_REQUIRE_EQUAL(container.getNetWeight(), 0.0);
    BOOST_REQUIRE_CLOSE_FRACTION(container.getGrossWeight(), 0.0, 0.00001);
}

BOOST_AUTO_TEST_CASE(ContainerInitialTareWeightAndMaxWeight) {
    Container container;
    container.setTare(100);
    container.setMaxWeight(400);
    BOOST_REQUIRE_EQUAL(container.getTare(), 100);
    BOOST_REQUIRE_EQUAL(container.getMaxWeight(), 400);
}
BOOST_AUTO_TEST_CASE(ContainerCheckLoadBelowMax) {
        Container container;
        container.setMaxWeight(100);
        container.loadCargo(50);
        BOOST_REQUIRE_EQUAL(container.getCargo(), 50);
}

BOOST_AUTO_TEST_CASE(ContainerCheckLoadAboveMax) {
        Container container;
        container.setMaxWeight(50);
        container.loadCargo(100);
        BOOST_REQUIRE_EQUAL(container.getCargo(), 50);
}

BOOST_AUTO_TEST_CASE(ContainerCheckUnloadMoreThanItContains) {
    Container container;
    container.setCargo(100);
    container.unloadCargo(150);
    BOOST_REQUIRE_EQUAL(container.getCargo(), 0);
}

BOOST_AUTO_TEST_SUITE_END()

// BOOST_TEST(condition);
// BOOST_TEST_WARN(condition) - only warning not an error

//BOOST_AUTO_TEST_SUITE(StudentSuiteFailure)
//
//BOOST_AUTO_TEST_CASE(StudentFirstNameRequire) {
//    Student student("Adam", "Smith");
//    // BOOST_REQUIRE_EQUAL(student.getFirstName(), "Error"); //REQUIRE_EQUAL = fatal error - end test case
//    BOOST_REQUIRE_EQUAL(student.getFirstName(), "Adam"); //not invoked due to previous fatal error
// }

//BOOST_AUTO_TEST_CASE(StudentFirstNameCheck) {
//    Student student("Adam", "Smith");
//    // BOOST_CHECK_EQUAL(student.getFirstName(), "Error"); //CHECK_EQUAL = error - but continue testing
//    BOOST_CHECK_EQUAL(student.getFirstName(), "Adam");
//}
//
//BOOST_AUTO_TEST_SUITE_END()
