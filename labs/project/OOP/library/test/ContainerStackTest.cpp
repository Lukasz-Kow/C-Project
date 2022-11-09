#include <boost/test/unit_test.hpp>

#include "ContainerStack.h"

BOOST_AUTO_TEST_SUITE(ContainerStackSuiteCorrect)

BOOST_AUTO_TEST_CASE(ContainerStack_Check_If_Empty){
    ContainerStack ContainerStack;
    ContainerStack.take(1);
    ContainerStack.take(2);
    BOOST_REQUIRE_EQUAL(ContainerStack.getSize(), 2);
}

BOOST_AUTO_TEST_CASE(ContainerStack_Check_The_Size_Of_The_Stack){
    ContainerStack ContainerStack;
    ContainerStack.take(1);
    ContainerStack.take(2);
    ContainerStack.take(3);
    ContainerStack.take(4);
    ContainerStack.take(5);
    ContainerStack.take(6);
    ContainerStack.take(7);
    ContainerStack.take(8);
    BOOST_REQUIRE_EQUAL(ContainerStack.getCapacity(), 2);
}
BOOST_AUTO_TEST_CASE(ContainerStack_Overload){
    ContainerStack ContainerStack;
    ContainerStack.take(1);
    ContainerStack.take(2);
    ContainerStack.take(3);
    ContainerStack.take(4);
    ContainerStack.take(5);
    ContainerStack.take(6);
    ContainerStack.take(7);
    ContainerStack.take(8);
    ContainerStack.take(9);
    ContainerStack.take(10);
    ContainerStack.take(11);
    BOOST_REQUIRE_EQUAL(ContainerStack.getCapacity(), 0);
}

BOOST_AUTO_TEST_SUITE_END()
