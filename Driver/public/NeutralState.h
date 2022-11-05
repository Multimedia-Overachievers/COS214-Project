/*
 *  NeutralState.h
 *  Created on: 10/31/2022
 *  Author: Dhairiya Chhipa (u21437841)
 */

#pragma once

#include "./FactionState.h"
#include "./AggressiveState.h"
#include "./DefensiveState.h"

/**                         
 * @brief This class handles the neutral attack strategy of a faction
 */
class NeutralState : public FactionState
{                           
public:
    NeutralState(int);
    virtual ~NeutralState();
    void handleState(ActionResult, Faction*, FactionState*) override;
};