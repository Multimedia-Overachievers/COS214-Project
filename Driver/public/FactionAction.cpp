#include "FactionAction.h"

FactionAction::FactionAction(ConcreteFaction* c) {
    myFaction = c;
}
ConcreteFaction* FactionAction::getFaction() {
    return myFaction;
}

