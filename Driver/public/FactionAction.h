#pragma once
#include "ConcreteFaction.h"

class FactionAction {
private:
    ConcreteFaction* myFaction;
public:
    FactionAction(ConcreteFaction* c);
    ConcreteFaction* getFaction();
    virtual bool execute() = 0;
};