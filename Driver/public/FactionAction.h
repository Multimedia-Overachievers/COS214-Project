#pragma once
#include "ConcreteFaction.h"

class FactionAction {
protected:
    ConcreteFaction* myFaction;
public:
    FactionAction(ConcreteFaction* c);
    ConcreteFaction* getFaction();
    virtual void execute() = 0;
};