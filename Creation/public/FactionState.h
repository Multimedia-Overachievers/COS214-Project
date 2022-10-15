/*
 *  FactionState.h
 *  Created on: 10/15/2022.
 *  Author: Ross Tordiffe (u21533572)
 */

#pragma once
#include "vector"

#include "../Driver/public/Country.h"

/**
 * @description Stores the state of a faction at a given time
 */

class FactionState
{
    private:
        FactionState(std::vector<Country*> countries);
        std::vector<Country*> getCountries();

    private:
        std::vector<Country*> countries;
        friend class Faction;
}