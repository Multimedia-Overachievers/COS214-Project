#include <iostream>

#include "../public/ConcreteSimulator.h"

int main() 
{
    // === Variables ===
    const int MAX_TURNS = 20;
    FactionName factionTurn = Allies;

    // === Main Loop ===
    for (int i = 0; i < MAX_TURNS; i++)
    {
        Faction* faction = ConcreteSimulator::getInstance()->getFaction(factionTurn);
        ConcreteSimulator::getInstance()->notify(faction);
        faction->notify();
        
        // Switch turn
        if (factionTurn == Allies)
        {
            factionTurn = Axis;
        }
        else
        {
            factionTurn = Allies;
        }
    }

    return 0;
}

