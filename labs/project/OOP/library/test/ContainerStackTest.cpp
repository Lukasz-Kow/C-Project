#include <boost/test/unit_test.hpp>

#include "ContainerStack.h"
#include "Container.h"


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
    BOOST_TEST(ContainerStack.getSize() == 10);
}
// added
BOOST_AUTO_TEST_CASE(ContainerStack_Container_Removal_One_Item_Stack){
    ContainerStack ContainerStack;
    ContainerStack.take(1);
    ContainerStack.give();
    BOOST_REQUIRE_EQUAL(ContainerStack.getSize(), 0);
}

BOOST_AUTO_TEST_CASE(ContainerStack_Container_Removal_Three_Item_Stack) {
    ContainerStack ContainerStack;
    ContainerStack.take(1);
    ContainerStack.take(2);
    ContainerStack.take(3);
    std::cout << 'a' << ContainerStack.at(1).getNumber() << std::endl;
    std::cout << ContainerStack.at(2).getNumber() << std::endl;
    std::cout << ContainerStack.at(3).getNumber() << std::endl;
    std::cout << "Number of elements " << ContainerStack.getSize() << std::endl;
    ContainerStack.give();
    std::cout << ContainerStack.at(1).getNumber() << std::endl;
    std::cout << ContainerStack.at(2).getNumber() << std::endl;
    // Why does it return 3 when this element should be deleted?
    // Size changes but the 3-rd container remains its number, why?
    std::cout << ContainerStack.at(3).getNumber() << std::endl;
    std::cout << "Number of elements " << ContainerStack.getSize() << std::endl;
    BOOST_REQUIRE_EQUAL(ContainerStack.getSize(), 2);
    BOOST_REQUIRE_EQUAL(ContainerStack.at(2).getNumber(), 2);
}

BOOST_AUTO_TEST_CASE(ContainerStack_Check_Order) {
    ContainerStack ContainerStack;
    ContainerStack.take(1);
    ContainerStack.take(2);
    ContainerStack.take(3);
    BOOST_REQUIRE_EQUAL(ContainerStack.at(1).getNumber(), 1);
    BOOST_REQUIRE_EQUAL(ContainerStack.at(2).getNumber(), 2);
    BOOST_REQUIRE_EQUAL(ContainerStack.at(3).getNumber(), 3);
}

// Additional test cases

BOOST_AUTO_TEST_CASE(ContainerStack_Removing_Container_From_Empty_Stack) {
    ContainerStack ContainerStack;
    ContainerStack.give();
    BOOST_TEST(ContainerStack.getSize() == 0);
}

BOOST_AUTO_TEST_CASE(ContainerStack_Accessing_Container_Out_Of_Range) {
    ContainerStack ContainerStack;
    BOOST_TEST(ContainerStack.at(1).getNumber() == 0);
}


BOOST_AUTO_TEST_SUITE_END()

/**
 *  - We can create functions to test some things
 *  - UI should not be connected to logical functions (i.e. don't print anything in functions which do some programm login)
 *  - On the class diagram an arrow should point to the parent class from child classes
 *  - Multi base inheritance - when one class inherits from 3 different classes that both iherit from a forth one
 *  - Protected access specifier - access such attributes is possible from all subclasses but not frmo outside these classes
 *
 */
