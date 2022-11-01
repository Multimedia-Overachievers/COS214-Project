#include <iostream>

#include "../public/ConcreteSimulator.h"

int main() 
{
    // === Variables ===
    const int MAX_TURNS = 20;
    FactionName factionTurn = Allies;

    // === Create the simulator ===
    ConcreteSimulator* simulator = ConcreteSimulator::getInstance();

    // === Main Loop ===
    for (int i = 0; i < MAX_TURNS; i++)
    {
        Faction* faction = simulator->getFaction(factionTurn);
        simulator->notify(faction);
        faction->notify();

        std::cout << "Turn " << i << " complete." << std::endl;
        
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

// Misc commits for progress tracking
// Started class diagram implementation