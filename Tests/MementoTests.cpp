#include <gtest/gtest.h>
#include "../../Driver/public/Faction.h"
#include "../../Creation/public/Simulation.h"
#include "../../Creation/public/MapState.h"
#include "../../Driver/public/structs.h"
#include "../../Creation/public/Logs.h"
#include "../../Driver/public/ConcreteSimulator.h"
#include "../Driver/public/enums.h"

TEST(MementoTests, SimulationTEST)
{
    Faction* allies = new ConcreteFaction(Allies);
    Faction* axis = new ConcreteFaction(Axis);

    FactionName alliesName = allies->getName();
    FactionName axisName = axis->getName();


    Simulation* simulation = new Simulation(allies, axis);
    MapState* state = simulation->saveLog();
    simulation->loadLog(state);

    EXPECT_TRUE(allies->getName() == alliesName);
    EXPECT_TRUE(axis->getName() == axisName);

    delete simulation;

    // EXPECT_TRUE(allies == nullptr);
    // EXPECT_TRUE(axis == nullptr);

}

// TEST(MementoTests, FactionObserverTEST)
// {
    
// }