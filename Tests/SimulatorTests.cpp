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