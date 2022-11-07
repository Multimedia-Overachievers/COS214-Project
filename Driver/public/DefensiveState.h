/*
 *  DefensiveState.h
 *  Created on: 10/31/2022
 *  Author: Dhairiya Chhipa (u21437841)
 */

#pragma once

#include "./FactionState.h"
#include "./AggressiveState.h"
#include "./NeutralState.h"

/**                         
 * @brief This class handles the defensive attack strategy of a faction
 */
class DefensiveState : public FactionState
{                           
public:
    DefensiveState(int);
    virtual ~DefensiveState();
    void handleState(ActionResult, Faction*) override;
    StanceType getStateType() override;
};