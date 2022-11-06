#include <gtest/gtest.h>
#include "../Creation/public/Soldiers.h"
#include "./TestFormatting.h"

class SquadTests : public ::testing::Test {
protected:
    static void SetUpTestSuite() {
        if (squad1 == nullptr) {
            squad1 = new Squad(SquadStd, Ready);
        }
        if (squad2 == nullptr) {
            squad2 = new Squad(SquadStd, Ready);
        }
    }

    static void TearDownTestSuite() {
        delete squad1;
        delete squad2;
        squad1 = nullptr;
        squad2 = nullptr;
    }

    static Troops* squad1;
    static Troops* squad2;
};

Troops* SquadTests::squad1 = nullptr;
Troops* SquadTests::squad2 = nullptr;

TEST_F(SquadTests, SquadInitialStateTest)
{
    std::cout << COUT_GTEST_MES << "Testing: Squad state after initialization" << ANSI_TXT_DFT << std::endl;
    EXPECT_TRUE(squad1->getState() == State::Ready);
    std::cout << COUT_GTEST_SUC << "==== TEST PASSED ====" << ANSI_TXT_DFT << std::endl;
}

TEST_F(SquadTests, SquadTakeDamageTest)
{
    std::cout << COUT_GTEST_MES << "Testing: Squad HP updates after taking damage" << ANSI_TXT_DFT << std::endl;
    SquadTests::squad1->takeDMG(10);
    EXPECT_EQ(squad1->getTotalHP(), 90);
    std::cout << COUT_GTEST_SUC << "==== TEST PASSED ====" << ANSI_TXT_DFT << std::endl;
}

TEST_F(SquadTests, SquadDefeatTest)
{
    std::cout << COUT_GTEST_MES << "Testing: Squad state after being defeated" << ANSI_TXT_DFT << std::endl;
    squad1->takeDMG(90);
    EXPECT_TRUE(squad1->getState() == State::Defeated);
    EXPECT_EQ(squad1->getTotalHP(), 0);
    std::cout << COUT_GTEST_SUC << "==== TEST PASSED ====" << ANSI_TXT_DFT << std::endl;
}

TEST_F(SquadTests, SquadAddTest)
{
    std::cout << COUT_GTEST_MES << "Testing: Adding new leaf to squad" << ANSI_TXT_DFT << std::endl;
    squad1->build(new Squad(SquadStd, Ready));
    EXPECT_EQ(squad1->getTotalTroops(), 1);
    std::cout << COUT_GTEST_SUC << "==== TEST PASSED ====" << ANSI_TXT_DFT << std::endl;
}

TEST_F(SquadTests, SquadDisbandTest)
{
    std::cout << COUT_GTEST_MES << "Testing: Disband method" << ANSI_TXT_DFT << std::endl;
    std::vector<Troops*> disbanded = squad1->disband();
    EXPECT_EQ(disbanded.size(), 1);
    std::cout << COUT_GTEST_SUC << "==== TEST PASSED ====" << ANSI_TXT_DFT << std::endl;
}

class SoldierTests : public ::testing::Test {
protected:
    static void SetUpTestSuite() {
        if (soldiers1 == nullptr) {
            soldiers1 = new Soldiers(Platoon, Ready);
        }
        if (soldiers2 == nullptr) {
            soldiers2 = new Soldiers(Platoon, Ready);
        }
    }

    static void TearDownTestSuite() {
        delete soldiers1;
        delete soldiers2;
        soldiers1 = nullptr;
        soldiers2 = nullptr;
    }

    static Troops* soldiers1;
    static Troops* soldiers2;
};

Troops* SoldierTests::soldiers1 = nullptr;
Troops* SoldierTests::soldiers2 = nullptr;

TEST_F(SoldierTests, SoldierInitialStateTest)
{
    std::cout << COUT_GTEST_MES << "Testing: Soldier status afer initialization" << ANSI_TXT_DFT << std::endl;
    EXPECT_TRUE(soldiers1->getState() == State::Ready);
    std::cout << COUT_GTEST_SUC << "==== TEST PASSED ====" << ANSI_TXT_DFT << std::endl;
}

TEST_F(SoldierTests, SoldierStateChangeTest)
{
    std::cout << COUT_GTEST_MES << "Testing: Soldier setState method" << ANSI_TXT_DFT << std::endl;
    soldiers1->setState(Moving);
    EXPECT_TRUE(soldiers1->getState() == State::Moving);
    std::cout << COUT_GTEST_SUC << "==== TEST PASSED ====" << ANSI_TXT_DFT << std::endl;
}

TEST_F(SoldierTests, SoldierBuildTest)
{
    std::cout << COUT_GTEST_MES << "Testing: Composite scalability with numerous troops added in succession" << ANSI_TXT_DFT << std::endl;
    soldiers1->setState(Ready);
    soldiers1->build(new Squad());
    soldiers1->build(new Squad(SquadStd, Ready));
    soldiers1->build(new Squad(SquadStd, Ready));
    soldiers1->build(new Squad(SquadStd, Ready));
    EXPECT_EQ(soldiers1->getTotalTroops(), 4);
    std::cout << COUT_GTEST_SUC << "==== TEST PASSED ====" << ANSI_TXT_DFT << std::endl;
}

TEST_F(SoldierTests, SoldierTakeDamageTest)
{
    std::cout << COUT_GTEST_MES << "Testing: Soldiers total hp after taking damage" << ANSI_TXT_DFT << std::endl;
    soldiers1->takeDMG(100);
    EXPECT_EQ(soldiers1->getTotalHP(), 500);
    std::cout << COUT_GTEST_SUC << "==== TEST PASSED ====" << ANSI_TXT_DFT << std::endl;
}

TEST_F(SoldierTests, SoldierMergeTest)
{
    std::cout << COUT_GTEST_MES << "Testing: Merging two soldier composites" << ANSI_TXT_DFT << std::endl;
    vector<Troops*> squads = soldiers1->disband();
    soldiers2->build(squads);
    EXPECT_EQ(soldiers2->getTotalTroops(), 3);
    std::cout << COUT_GTEST_SUC << "==== TEST PASSED ====" << ANSI_TXT_DFT << std::endl;
}

TEST_F(SoldierTests, SoldierDeathTest)
{
    std::cout << COUT_GTEST_MES << "Testing: Soldier state after being defeated" << ANSI_TXT_DFT << std::endl;
    soldiers1->takeDMG(1000);
    EXPECT_TRUE(soldiers1->getState() == State::Defeated);
    EXPECT_EQ(soldiers1->getTotalHP(), 0);
    std::cout << COUT_GTEST_SUC << "==== TEST PASSED ====" << ANSI_TXT_DFT << std::endl;
}

class AdvancedSoldierTests : public ::testing::Test {
protected:
    static void SetUpTestSuite() {
        if (soldiers1 == nullptr) {
            soldiers1 = new Soldiers(Platoon, Ready);
        }
        if (soldiers2 == nullptr) {
            soldiers2 = new Soldiers(Platoon, Ready);
        }
    }

    static void TearDownTestSuite() {
        delete soldiers1;
        delete soldiers2;
        soldiers1 = nullptr;
        soldiers2 = nullptr;
    }

    static Troops* soldiers1;
    static Troops* soldiers2;
};

Troops* AdvancedSoldierTests::soldiers1 = nullptr;
Troops* AdvancedSoldierTests::soldiers2 = nullptr;

TEST_F(AdvancedSoldierTests, AdvancedBuildTest)
{
    std::cout << COUT_GTEST_MES << "Testing: Building large amounts of squads" << ANSI_TXT_DFT << std::endl;
    for (int i = 0; i < 10; i++)
    {
        soldiers1->build(new Squad(SquadStd, Ready));
        soldiers2->build(new Squad(SquadStd, Ready));
    }
    EXPECT_EQ(soldiers1->getTotalTroops(), 10);
    EXPECT_EQ(soldiers2->getTotalTroops(), 10);
    std::cout << COUT_GTEST_SUC << "==== TEST PASSED ====" << ANSI_TXT_DFT << std::endl;
}

TEST_F(AdvancedSoldierTests, AdvancedMoveTest)
{
    soldiers2->build(soldiers1->disband(5));
    std::cout << COUT_GTEST_MES << "Testing: Moving squads from one soldier instance to another" << ANSI_TXT_DFT << std::endl;
    EXPECT_EQ(soldiers1->getTotalTroops(), 5);
    EXPECT_EQ(soldiers2->getTotalTroops(), 15);
    std::cout << COUT_GTEST_SUC << "==== TEST PASSED ====" << ANSI_TXT_DFT << std::endl;
}

TEST_F(AdvancedSoldierTests, AdvancedAttackTest)
{
    std::cout << COUT_GTEST_MES << "Testing: Different composites attacking eachother" << ANSI_TXT_DFT << std::endl;
    soldiers1->takeDMG(soldiers2->getTotalDMG());
    EXPECT_EQ(soldiers1->getTotalHP(), 520);
    std::cout << COUT_GTEST_SUC << "==== TEST PASSED ====" << ANSI_TXT_DFT << std::endl;
}
