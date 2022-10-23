/*
 *  FactionAction.h
 *  Created on: 10/15/2022.
 *  Author: Thomas Isebeck (u20446332)
 */

#pragma once
#include "./ConcreteFaction.h"

class FactionAction {
public:
    explicit FactionAction(ConcreteFaction* c);
    ConcreteFaction* getFaction();
    virtual void execute() = 0;

protected:
    ConcreteFaction* myFaction;
};