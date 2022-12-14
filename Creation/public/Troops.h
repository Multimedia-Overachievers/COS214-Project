/*
 *  Troops.h
 *  Created on: 10/15/2022.
 *  Author: Tayla Orsmond (u21467456)
 */

#pragma once
#include <vector>
#include <string>
#include "../../Driver/public/enums.h"

using namespace std;
/**
 * @brief The Troops class
 * @details This class is used to create the troops that will be used in the sim
 * This is the Component class in the Composite Design pattern
 * This is an abstract class
 *
 * @author Tayla Orsmond
 * @date 11/05/2022
 *
 */
class TroopIterator;
class Troops
{
    friend class MoveTroops;
    friend class TroopIterator;
    friend class SquadIterator;

public:
    Troops(Name name = SquadStd, State state = Ready);
    virtual ~Troops();
    virtual int takeDMG(int total) = 0;
    virtual string getReport() = 0;
    virtual vector<Troops *> disband() = 0;
    virtual vector<Troops *> disband(int noToRemove) = 0;
    virtual void build(vector<Troops *> squads) = 0;
    virtual void build(Troops *squad) = 0;
    virtual void build(int noToAdd) = 0;
    virtual int getTotalHP() = 0;
    virtual int getTotalDMG() = 0;
    virtual int getTotalTroops() = 0;
    void setState(State state) { this->state = state; }
    enum State getState() { return this->state; }
    enum Name getName() { return this->name; }
protected:
    void setName(Name name) { this->name = name; }
    void setHP(int hp) { this->hp = hp; }
    void setDMG(int dmg) { this->dmg = dmg; }
    int getHP() { return this->hp; }
    int getDMG() { return this->dmg; }

private:
    virtual TroopIterator *createIterator() = 0;
    virtual vector<Troops *> getTroops() = 0;
    int dmg;
    int hp;
    State state;
    Name name;
};