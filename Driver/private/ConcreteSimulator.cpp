#include "../public/ConcreteSimulator.h"
#include "../public/FactionAction.h"

/**
 * @brief Constructor that initializes the factions
 */
ConcreteSimulator::ConcreteSimulator() {
    factions.push_back(new Faction(this, "Allies"));
    factions.push_back(new Faction(this, "Axis"));
}

/**
 * @brief Basic function to show how google tests work.
 * @param a - First number to add.
 * @param b - Second number to add.
 * @return int - Sum of a and b.
 */
int ConcreteSimulator::TestFunction(int a, int b)
{
    return a + b;
}

/**
 * @description Notifies the simulator of a command.
 * @param command - Command to notify the simulator of.
 */
void ConcreteSimulator::notify(std::string command) {
    if (command == "attack")
    {
        // Do attack stuff
    }
    else if (command == "reStock")
    {
        // Do supply stuff
    }
    else
    {
        std::cout << "Invalid command" << std::endl;
    }
}

/**
 * @description Performs an action on a faction.
 * @param factionAction - Action to perform on a faction.
 */
void ConcreteSimulator::action(FactionAction *factionAction) {
    factionAction->execute();
}

/**
 * @description Decides what action to perform on a faction.
 * @param faction - Faction to decide an action for.
 * @return FactionAction - Action to perform on the faction.
 */
FactionAction* ConcreteSimulator::decideAction(Faction *faction) {
    double weights[2]; // Weights for the different actions 0 -> 0.5 = attack, 0.5 -> 1 = reStock

    if(faction->getStance() == FactionStance::Aggressive)
    {
        weights[0] = 0.75; // 75%
        weights[1] = 1; // 25%
    }
    else if(faction->getStance() == FactionStance::Passive)
    {
        weights[0] = 0.5; // 50% 
        weights[1] = 1; // 50%
    }
    else if(faction->getStance() == FactionStance::Defensive)
    {   
        weights[0] = 0.25; // 25%
        weights[1] = 1; // 75%
    }

    if(faction->getStrength() < 3)
    {
        weights[0] /= 0.25; // Make the faction (25%) more likely to reStock
    }
    else if(faction->getStrength() > 3 && faction->getStrength() <= 5)
    {
        // No change
    }
    else if(faction->getStrength() > 6)
    {
        weights[0] *= 0.25; // Make the faction (25%) more likely to attack
    }

    double random = (double)rand() / RAND_MAX; // Random number between 0 and 1

    if(random < weights[0])
    {
        //return new AttackAction(faction);
    }
    else
    {
        //return new ReStockAction(faction);
    }

}