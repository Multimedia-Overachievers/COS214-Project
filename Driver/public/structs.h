#pragma once

#include "../../Manipulation/public/Country.h"
#include "../../Driver/public/enums.h"
#include "./FactionState.h"
#include <list>

struct FactionStore
{
private:
    std::list<Country*> countries;
    FactionState* stance;
    FactionName name;
    friend class ConcreteFaction;
    friend class FactionObserver;
};
