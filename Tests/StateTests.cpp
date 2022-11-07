#include <gtest/gtest.h>
#include "../Driver/public/enums.h"
#include "../Driver/public/ConcreteSimulator.h"
#include "../Driver/public/AggressiveState.h"
#include "../Driver/public/DefensiveState.h"
#include "./TestFormatting.h"

class StateTests : public ::testing::Test {
protected:
    static void SetUpTestSuite() {
        if (simulator == nullptr) {
            simulator = ConcreteSimulator::getInstance();
        }
    }

    static ConcreteSimulator* simulator;
};

ConcreteSimulator* StateTests::simulator = nullptr;

TEST_F(StateTests, StateSwapTest)
{
    std::cout << COUT_GTEST_MES << "Testing: Attack from country command" << ANSI_TXT_DFT << std::endl;
    Faction* allies = simulator->getFaction(Allies);

    ASSERT_EQ(allies->getStance(), StanceType::NeutralStance);
    allies->setStance(new AggressiveState(1));
    ASSERT_EQ(allies->getStance(), StanceType::AggressiveStance);
    std::cout << COUT_GTEST_SUC << "==== TEST PASSED ====" << ANSI_TXT_DFT << std::endl;
}