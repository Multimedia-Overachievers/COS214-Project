/*
 *  ConcreteSimulator.h
 *  Created on: 10/13/2022.
 *  Author: Keelan Matthews (u21549967)
 */

#pragma once
#include "./Simulator.h"
#include "./ConcreteFaction.h"
#include <vector>

class FactionAction;

/**
 * @brief The concrete simulator which simulates the game.
 */
class ConcreteSimulator : public Simulator
{
public:
    int TestFunction(int a, int b);
    void action(FactionAction* factionAction) override;
    void notify(Faction* faction) override;
    FactionAction* decideAction(Faction* faction) override;
    Faction* getFaction(FactionName name) override; // 0 = Allies, 1 = Axis
    Faction* getOpposite(Faction* faction) override;
    void captureCountry(Country* country, Faction* faction) override;
    static ConcreteSimulator* getInstance();
    void setLastResult(ActionResult result);
    ActionResult getLastResult();

protected:
    ConcreteSimulator();
    virtual ~ConcreteSimulator() = default;
    ConcreteSimulator(const ConcreteSimulator& other) = default;
    ConcreteSimulator& operator=(const ConcreteSimulator& other) = default;

private:
    std::vector<Faction*> factions;
    static ConcreteSimulator* instance;
    ActionResult lastResult;
};
