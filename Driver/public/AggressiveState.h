/*
 *  AggressiveState.h
 *  Created on: 10/31/2022
 *  Author: Dhairiya Chhipa (u21437841)
 */

#pragma once

#include "./FactionState.h"
#include "./DefensiveState.h"
#include "./NeutralState.h"

/**                         
 * @brief This class handles the aggressive attack strategy of a faction
 */
class AggressiveState : public FactionState
{                           
public:
    AggressiveState();
    virtual ~AggressiveState();
    void handleState(ActionResult, Faction*, FactionState*) override;
};