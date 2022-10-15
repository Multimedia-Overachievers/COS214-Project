#include "../public/ConcreteSimulator.h"

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
