#include <boost/test/unit_test.hpp>

#include <memory>
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
        A->loadCargo(20);
        A->setStrength(100);

        B->setTare(50);
        B->loadCargo(20);
        B->setStrength(600);

        C->setTare(100);
        A->loadCargo(20);
        C->setStrength(10);

        BOOST_REQUIRE_EQUAL(strategy.canPutDown(*A, loadable), true);
        loadable.take(*A);

        BOOST_REQUIRE_EQUAL(strategy.canPutDown(*B, loadable), false);
        loadable.take(*B);

        BOOST_REQUIRE_EQUAL(strategy.canPutDown(*C, loadable), false);
        loadable.take(*C);
    }

BOOST_AUTO_TEST_CASE(Check_Free_Place_Strategy) {
        CheckFreePlaceStrategy strategy;
        ContainerStack loadable;

        Container containerFirst(1);
        Container containerSecond(2);
        shared_ptr<Container> A = make_shared<Container>(2);
        loadable.take(containerFirst);
        loadable.take(containerSecond);

        BOOST_REQUIRE_EQUAL(strategy.canPutDown(*A, loadable), true);

        Container containerLast(3);
        loadable.take(containerLast);

        BOOST_REQUIRE_EQUAL(strategy.canPutDown(*A, loadable), false);
    }

BOOST_AUTO_TEST_SUITE_END()