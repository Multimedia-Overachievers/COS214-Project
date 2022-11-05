/*
 *  FactionState.h
 *  Created on: 10/31/2022
 *  Author: Dhairiya Chhipa (u21437841)
 */

#pragma once

#include "./Faction.h"

/**                         
 * @brief This class handles the attack strategy of a faction
 */
class FactionState
{                           
public:
    FactionState();
    virtual void handleState(ActionResult, Faction*, FactionState*) = 0;
    virtual ~FactionState();

private:
    int calculateMorale(Faction*);
};