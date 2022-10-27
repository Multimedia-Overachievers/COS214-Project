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

/**
 * @brief The concrete simulator which simulates the game.
 */
class ConcreteSimulator : public Simulator
{
public:
    int TestFunction(int a, int b);
    static void action(FactionAction* factionAction);
    void notify(ConcreteFaction* enemyFaction) override;
    FactionAction* decideAction(ConcreteFaction* faction);
    ConcreteFaction* getFaction(FactionName name); // 0 = Allies, 1 = Axis
    ConcreteFaction* getOpposite(ConcreteFaction* faction);
    static ConcreteSimulator* getInstance();
    void captureCountry(Country* country, ConcreteFaction* faction);

protected:
    ConcreteSimulator();

private:
    std::vector<ConcreteFaction*> factions;
    ConcreteSimulator* instance;
};
