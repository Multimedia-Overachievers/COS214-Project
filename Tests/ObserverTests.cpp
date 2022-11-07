#include <gtest/gtest.h>
#include "../Manipulation/public/Country.h"
#include "../Driver/public/ConcreteSimulator.h"
#include "./TestFormatting.h"

class ObserverTests : public ::testing::Test {
protected:
    static void SetUpTestSuite() {
        if(simulator == nullptr) {
            simulator = ConcreteSimulator::getInstance();
        }
        if(country == nullptr) {
            country = new Country(CountryName::France, FactionName::Allies, 3, 0);
        }
    }

    static void TearDownTestSuite() {
        delete country;
        country = nullptr;
    }

    static Country* country;
    static ConcreteSimulator* simulator;
};

Country* ObserverTests::country = nullptr;
ConcreteSimulator* ObserverTests::simulator = nullptr;

TEST_F(ObserverTests, CountryObserverDrawTest)
{
    std::cout << COUT_GTEST_MES << "Testing: Initial action result" << ANSI_TXT_DFT << std::endl;
    EXPECT_EQ(simulator->getLastResult(), ActionResult::Win);
    country->notify();
    EXPECT_TRUE(simulator->getLastResult() == ActionResult::Draw);
    std::cout << COUT_GTEST_SUC << "==== TEST PASSED ====" << ANSI_TXT_DFT << std::endl;
}

TEST_F(ObserverTests, CountryObserverLossTest)
{
    std::cout << COUT_GTEST_MES << "Testing: Failed invade results in Loss result" << ANSI_TXT_DFT << std::endl;
    country->addTroops(10);
    EXPECT_EQ(simulator->getLastResult(), ActionResult::Draw);
    country->notify();
    EXPECT_TRUE(simulator->getLastResult() == ActionResult::Loss);
}

TEST_F(ObserverTests, CountryObserverWinTest)
{
    std::cout << COUT_GTEST_MES << "Testing: Successful invade results in Win result" << ANSI_TXT_DFT << std::endl;
    country->setOwner(FactionName::Axis);
    EXPECT_EQ(simulator->getLastResult(), ActionResult::Loss);
    country->notify();
    EXPECT_TRUE(simulator->getLastResult() == ActionResult::Win);
}