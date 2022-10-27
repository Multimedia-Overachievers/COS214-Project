/*
 *  FactionObserver.h
 *  Created on: 10/27/2022.
 *  Author: Francois Smith (u21649988)
 */

#pragma once
#include "./Observer.h"
// #include "../../Driver/public/ConcreteSimulator.h"

//Forward declaration to avoid circular dependency
class ConcreteFaction;

class FactionObserver: public Observer
{
public:
    FactionObserver(ConcreteFaction* faction);
    void update() override;

private:
    ConcreteFaction* faction;
    FactionStance* stance;
};