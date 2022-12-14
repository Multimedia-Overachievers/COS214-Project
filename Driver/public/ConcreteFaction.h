/*
 *  ConcreteFaction.cpp
 *  Created on: 10/15/2022.
 *  Author: Thomas Isebeck (u20446332)
 */

#pragma once
#include "./Faction.h"
#include "./NeutralState.h"

class ConcreteFaction: public Faction 
{
public:
    ConcreteFaction(FactionName name);
    virtual ~ConcreteFaction();
    FactionStore* getData() override;
    void setData(FactionStore* store) override;
    FactionState* getStance() override;
    StanceType getStanceType() override;
    FactionName getName() override;
    Country* getCountry(int index) override;
    int getStrength() override;
    void removeCountry(Country* country) override;
    void addCountry(Country* country) override;
    void notify() override;
    void changeState(ActionResult result) override;
    void createCountries() override;
    int getTotalTroops() override;
    void setStance(FactionState*) override;
    Faction* clone() override;

protected:
    ConcreteFaction(Faction*);
};
