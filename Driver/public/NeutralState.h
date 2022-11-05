/*
 *  NeutralState.h
 *  Created on: 10/31/2022
 *  Author: Dhairiya Chhipa (u21437841)
 */

#pragma once

#include "./FactionState.h"

/**                         
 * @brief This class handles the passive attack strategy of a faction
 */
class NeutralState : public FactionState
{                           
public:
    NeutralState();
    void handleState(ActionResult, Faction*, FactionState*) override;
    virtual ~NeutralState();
};