/*
 *  ConcreteSimulator.h
 *  Created on: 10/13/2022.
 *  Author: Keelan Matthews (u21549967)
 */

#pragma once
#include "./Simulator.h"
#include "./ConcreteFaction.h"
#include "./FactionAction.h"
#include <vector>

class ConcreteSimulator : public Simulator
{
public:
    int TestFunction(int a, int b);
    ConcreteSimulator();
    static void action(FactionAction* factionAction);
    void notify(ConcreteFaction* enemyFaction) override;
    static FactionAction* decideAction(ConcreteFaction* faction);
    ConcreteFaction* getFaction(FactionName name); // 0 = Allies, 1 = Axis
    
private:
    std::vector<ConcreteFaction*> factions;
};
