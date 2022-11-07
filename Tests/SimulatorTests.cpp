#include <gtest/gtest.h>
#include "../Driver/public/ConcreteSimulator.h"
#include "./TestFormatting.h"

class SimulatorTests : public ::testing::Test {
protected:
    static void SetUpTestSuite() {
        if (simulator == nullptr) {
            simulator = ConcreteSimulator::getInstance();
        }
    }

    static void TearDownTestSuite() {
        simulator = nullptr;
    }

    static ConcreteSimulator* simulator;
};

ConcreteSimulator* SimulatorTests::simulator = nullptr;

TEST_F(SimulatorTests, SimulatorSingletonTest)
{
    std::cout << COUT_GTEST_MES << "Testing: Getting instance of simulator with singleton" << ANSI_TXT_DFT << std::endl;
    ASSERT_EQ(simulator, ConcreteSimulator::getInstance());
    std::cout << COUT_GTEST_SUC << "==== TEST PASSED ====" << ANSI_TXT_DFT << std::endl;
}

TEST_F(SimulatorTests, SimulatorFactionsTest)
{
    std::cout << COUT_GTEST_MES << "Testing: Getting factions from simulator" << ANSI_TXT_DFT << std::endl;
    Faction* allies = simulator->getFaction(Allies);
    Faction* axis = simulator->getFaction(Axis);
    ASSERT_EQ(simulator->getFaction(Allies), allies);
    ASSERT_EQ(simulator->getFaction(Axis), axis);
    ASSERT_EQ(simulator->getOpposite(allies), axis);
    ASSERT_EQ(simulator->getOpposite(axis), allies);
    std::cout << COUT_GTEST_SUC << "==== TEST PASSED ====" << ANSI_TXT_DFT << std::endl;
}

TEST_F(SimulatorTests, SimulatorCaptureTest)
{
    std::cout << COUT_GTEST_MES << "Testing: Capturing countries from factions" << ANSI_TXT_DFT << std::endl;
    Faction* allies = simulator->getFaction(Allies);
    Faction* axis = simulator->getFaction(Axis);
    Country* country1 = simulator->countries[0];
    Country* country2 = simulator->countries[6];
    ASSERT_EQ(country1->getOwner(), FactionName::Allies);
    country1->conquer(country2);
    ASSERT_EQ(country1->getOwner(), FactionName::Axis);
    std::cout << COUT_GTEST_SUC << "==== TEST PASSED ====" << ANSI_TXT_DFT << std::endl;
}

TEST_F(SimulatorTests, SimulatorImageTest)
{
    std::cout << COUT_GTEST_MES << "Testing: Getting image from simulator" << ANSI_TXT_DFT << std::endl;
    ASSERT_EQ(simulator->getImagePath(CountryName::France), "../Media/FranceAxis.png");
    std::cout << COUT_GTEST_SUC << "==== TEST PASSED ====" << ANSI_TXT_DFT << std::endl;
}