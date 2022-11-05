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

/*
 * if defensive, morale == 25, if neutral, morale == 50, if aggressive, morale == 75
 * if opposite is null, morale *= 1.2
 * if the result is a win, morale *= 1.4, if the result is a loss, morale *= 0.6, if the result is a draw, morale *= 0.9
*/
class FactionState
{                           
public:
    FactionState();
    virtual ~FactionState();
    virtual void handleState(ActionResult, Faction*, FactionState*) = 0;
    void printState(FactionName, string, bool);

protected:
    string getFactionName(FactionName);
    void deletePreviousState(FactionState*);
    int calculateMorale(ActionResult, Faction*);
};