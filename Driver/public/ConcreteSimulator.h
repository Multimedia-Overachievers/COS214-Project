/*
 *  ConcreteSimulator.h
 *  Created on: 10/13/2022.
 *  Author: Keelan Matthews (u21549967)
 */

#pragma once
#include "Simulator.h"
#include "Faction.h"
#include "FactionAction.h"
#include <vector>

class ConcreteSimulator : public Simulator
{
private:
    std::vector<Faction*> factions;
public:
    int TestFunction(int a, int b);
    ConcreteSimulator();
    void action(FactionAction*);
    void notify(std::string command) override;
};
