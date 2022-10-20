/*
 *  SquadIterator.h
 *  Created on: 10/15/2022.
 *  Author: Tayla Orsmond (u21467456)
 */

#pragma once
#include "./TroopIterator.h"
#include "./Soldiers.h"
#include "./Squad.h"

/**
 * @brief The SquadIterator class
 * @details This class is used to iterate through the squads
 * This is the ConcreteIterator in the Iterator Design Pattern
 * This class inherits from the TroopIterator class
 * 
 * @author Tayla Orsmond
 * @date 10/19/2022
 * 
 */
class Soldiers;
class SquadIterator : public TroopIterator{
public:
    SquadIterator();
    SquadIterator(Soldiers * soldiers);
    ~SquadIterator();
    Troops * first();
    Troops * next();
    bool isDone();
    Troops * current();
    vector<Troops *>::iterator at();
    
private:
    vector<Troops *>::iterator it;
    Soldiers * mySoldiers;
};