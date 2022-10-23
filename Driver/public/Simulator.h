/*
 *  Simulator.h
 *  Created on: 10/13/2022.
 *  Author: Keelan Matthews (u21549967)
 */

#pragma once 
#include <string>
#include <iostream>
#include "./ConcreteFaction.h"

class Simulator
{
public:
    virtual void notify(ConcreteFaction* enemyFaction) = 0;
};
