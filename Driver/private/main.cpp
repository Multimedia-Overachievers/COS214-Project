#include <iostream>

#include "../public/ConcreteSimulator.h"

int main() 
{
    // === Objects ===
    ConcreteSimulator* simulator = ConcreteSimulator::getInstance();

    // === Variables ===
    const int MAX_TURNS = 20;
    FactionName factionTurn = Allies;

    // === Main Loop ===
    for (int i = 0; i < MAX_TURNS; i++)
    {
        std::cout << "Turn " << i << " - " << simulator->getFaction(factionTurn)->getName() << " turn" << std::endl;
        Faction* faction = ConcreteSimulator::getInstance()->getFaction(factionTurn);
        ConcreteSimulator::getInstance()->notify(faction);
        
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

