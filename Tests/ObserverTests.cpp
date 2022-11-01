#include <gtest/gtest.h>
#include "../Manipulation/public/CountryObserver.h"
#include "../Manipulation/public/Country.h"
#include "../Driver/public/ConcreteSimulator.h"
#include "../Driver/public/enums.h"

TEST(ObserverTests, CountryObserverTEST)
{
    Country* country = new Country(CountryName::France, FactionName::Allies, 3, 0);
    ConcreteSimulator* simulator = ConcreteSimulator::getInstance();

    EXPECT_EQ(simulator->getLastResult(), ActionResult::None);
    country->notify();
    EXPECT_TRUE(simulator->getLastResult() == ActionResult::Draw);
}

TEST(ObserverTests, FactionObserverTEST)
{
    
}