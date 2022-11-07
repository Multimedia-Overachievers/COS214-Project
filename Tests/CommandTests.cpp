#include <gtest/gtest.h>
#include "../Driver/public/FactionAction.h"
#include "../Driver/public/AttackFromCountry.h"
#include "../Driver/public/Restock.h"
#include "../Driver/public/MoveTroops.h"
#include "../Driver/public/ConcreteSimulator.h"
#include "./TestFormatting.h"

class CommandTests : public ::testing::Test {
protected:
    static void SetUpTestSuite() {
        if (simulator == nullptr) {
            simulator = ConcreteSimulator::getInstance();
        }
    }

    static ConcreteSimulator* simulator;
};

ConcreteSimulator* CommandTests::simulator = nullptr;

TEST_F(CommandTests, CommandAttackTest)
{
    std::cout << COUT_GTEST_MES << "Testing: Attack from country command" << ANSI_TXT_DFT << std::endl;
    Faction* allies = simulator->getFaction(Allies);
    Faction* axis = simulator->getFaction(Axis);

    Country* invadingCountry = allies->getCountry(3);
    Country* defendingCountry = axis->getCountry(3);
    ASSERT_EQ(defendingCountry->getOwner(), FactionName::Axis);

    invadingCountry->addTroops(10);
    FactionAction* attack = new AttackFromCountry(allies, invadingCountry, defendingCountry);
    simulator->action(attack);
    ASSERT_EQ(invadingCountry->getOwner(), FactionName::Allies);
    std::cout << COUT_GTEST_SUC << "==== TEST PASSED ====" << ANSI_TXT_DFT << std::endl;
}

TEST_F(CommandTests, CommandRestockTest)
{
    std::cout << COUT_GTEST_MES << "Testing: Restock a country" << ANSI_TXT_DFT << std::endl;
    Faction* allies = simulator->getFaction(Allies);
    Faction* axis = simulator->getFaction(Axis);

    // ASSERT_EQ(country->getTroops(), 0);
    // Country* country = allies->getCountry(2);
    // FactionAction* restock = new Restock(allies, country);
    // simulator->action(restock);
    // ASSERT_EQ(country->getTroops(), 20);
    std::cout << COUT_GTEST_SUC << "==== TEST PASSED ====" << ANSI_TXT_DFT << std::endl;
}