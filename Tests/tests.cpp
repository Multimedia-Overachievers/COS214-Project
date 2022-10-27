#include <gtest/gtest.h>
#include "../Driver/public/ConcreteSimulator.h"

TEST(TestFunction, BasicTest)
{
    EXPECT_EQ(ConcreteSimulator::getInstance()->TestFunction(1, 2), 3);
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}