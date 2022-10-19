//
// Created by thoma on 10/19/2022.
//

#include "../public/MoveTroops.h"

MoveTroops::MoveTroops(ConcreteFaction* destinationFaction, Country* destinationCountry, Country* sourceCountry, int numTroops)
                                                                                : FactionAction(destinationFaction) {
    this->destinationCountry = destinationCountry;
    this->numTroops = numTroops;
}

bool MoveTroops::execute() {
    if (!this->sourceCountry->hasTroops())
        return false;

    //TODO: remove building buff before you move the troops
    for (int i = 0; this->sourceCountry->hasTroops() && i < this->numTroops; i++)
        this->destinationCountry->addTroop(this->sourceCountry->removeTroop());

    return true;
}
