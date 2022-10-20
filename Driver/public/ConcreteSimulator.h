/*
 *  ConcreteSimulator.h
 *  Created on: 10/13/2022.
 *  Author: Keelan Matthews (u21549967)
 */

#pragma once
#include "./Simulator.h"
#include "./Faction.h"
#include "./FactionAction.h"
#include <vector>

class ConcreteSimulator : public Simulator
{
public:
    int TestFunction(int a, int b);
    ConcreteSimulator();
    void action(FactionAction* factionAction);
    void notify(std::string command) override;
    FactionAction* decideAction(Faction* faction); 

private:
    std::vector<Faction*> factions;
};
