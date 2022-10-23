/*
 *  FactionState.h
 *  Created on: 10/15/2022.
 *  Author: Ross Tordiffe (u21533572)
 */

#pragma once

#include "../../Manipulation/public/Country.h"

/**
 * @description Stores the state of a faction at a given time
 */
class FactionState
{
private:
    std::vector<Country*> getCountries();

public:
    FactionState(std::vector<Country*> countries);

private:
    std::vector<Country*> countries;
    friend class Faction;
};