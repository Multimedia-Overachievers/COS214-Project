/*
 *  SquadIterator.h
 *  Created on: 10/15/2022.
 *  Author: Tayla Orsmond (u21467456)
 */

#pragma once
#include "./TroopIterator.h"

/**
 * @brief The SquadIterator class
 * @details This class is used to iterate through the squads
 * This is the ConcreteIterator in the Iterator Design Pattern
 * This class inherits from the TroopIterator class
 * 
 * @author Tayla Orsmond
 * @date 11/05/2022
 * 
 */
class SquadIterator : public TroopIterator{
    friend class Troops;
    friend class Soldiers;
    friend class Squad;
public:
    ~SquadIterator();
    Troops * first();
    Troops * next();
    bool isDone();
    Troops * current();    
private:
    SquadIterator();
    SquadIterator(Troops * soldiers);
};