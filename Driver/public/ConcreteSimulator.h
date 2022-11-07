/*
 *  ConcreteSimulator.h
 *  Created on: 10/13/2022.
 *  Author: Keelan Matthews (u21549967)
 */

#pragma once
#include "./Simulator.h"
#include "./ConcreteFaction.h"
#include <vector>
#include <map>

class FactionAction;

/**
 * @brief The concrete simulator which simulates the game.
 */
class ConcreteSimulator : public Simulator
{
public:
    void action(FactionAction* factionAction) override;
    void notify(Faction* faction) override;
    FactionAction* decideAction(Faction* faction) override;
    Faction* getFaction(FactionName name) override; // 0 = Allies, 1 = Axis
    Faction* getOpposite(Faction* faction) override;
    void captureCountry(Country* country, Faction* faction) override;
    static ConcreteSimulator* getInstance();
    void setLastResult(ActionResult result);
    ActionResult getLastResult();
    ActionType getNextAction();
    std::string getImagePath(CountryName country);
    std::string getImagePath(ActionType action);
    bool gameOver(){return this->WIN_CONDITION;}
    void toggleGameOver(){this->WIN_CONDITION = true;}

protected:
    ConcreteSimulator();
    virtual ~ConcreteSimulator() = default;
    ConcreteSimulator(const ConcreteSimulator& other) = default;
    ConcreteSimulator& operator=(const ConcreteSimulator& other) = default;

public:
    std::vector<Country*> countries;
    std::map<std::string, std::string> messageMap;

private:
    std::vector<Faction*> factions;
    static ConcreteSimulator* instance;
    ActionResult lastResult;
    ActionType nextAction;
    bool WIN_CONDITION;


};
