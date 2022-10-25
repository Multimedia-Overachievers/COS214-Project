#include <iostream>

#include "ConcreteSimulator.h"

int main() 
{
    
    // === Objects ===
    Simulator* simulator = ConcreteSimulator::getInstance();

    // === Variables ===
    const int MAX_TURNS = 20;
    FactionName factionTurn = Allies;

    // === Main Loop ===
    for (int i = 0; i < MAX_TURNS; i++)
    {
        // -?Ross- Ask group about casting 
        simulator->notify(((ConcreteSimulator*)simulator)->getFaction(factionTurn));
        
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

