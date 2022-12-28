#include <boost/test/unit_test.hpp>

#include "Crane.h"
#include "CheckPlaceAndWeightStrategy.h"
#include "CheckFreePlaceStrategy.h"
#include "Loadable.h"

using namespace std;

BOOST_AUTO_TEST_SUITE(Check_Strategies_Test)

BOOST_AUTO_TEST_CASE(Check_Place_And_Weight_Strategy) {
        CheckPlaceAndWeightStrategy strategy;
        ContainerStack loadable;

        shared_ptr<Container> A = make_shared<Container>(1);
        shared_ptr<Container> B = make_shared<Container>(2);
        shared_ptr<Container> C = make_shared<Container>(3);

        A->setTare(10);
        A->setStrength(100);

        B->setTare(50);
        B->setStrength(51);

        C->setTare(20);
        C->setStrength(10);

        BOOST_REQUIRE_EQUAL(strategy.canPutDown(*A, loadable), true);
        loadable.take(*A);
        BOOST_REQUIRE_EQUAL(strategy.canPutDown(*B, loadable), true);
        loadable.take(*B);
        BOOST_REQUIRE_EQUAL(strategy.canPutDown(*C, loadable), false);
        loadable.take(*C);
    }

BOOST_AUTO_TEST_CASE(Check_Free_Place_Strategy) {
        CheckFreePlaceStrategy strategy;
        ContainerStack loadable;

        Container container_first(1);
        Container container_second(2);

        loadable.take(container_first);
        loadable.take(container_second);
        shared_ptr<Container> A = make_shared<Container>(2);

        BOOST_REQUIRE_EQUAL(strategy.canPutDown(*A, loadable), true);


        Container container_last(3);
        loadable.take(container_last);

        BOOST_REQUIRE_EQUAL(strategy.canPutDown(*A, loadable), false);
    }



BOOST_AUTO_TEST_SUITE_END()