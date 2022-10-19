#include "../public/Faction.h"

Faction::Faction(Simulator *simulator, std::string name) {
    this->simulator = simulator;

    if (name == "Allies")
    {
//        these are just examples of countries generated by copilot to get an idea of what the code should look like
        countries.push_back(new Country("France", 100, 100, 100, 100, 100, 100, 100, 100, 100, 100));
        countries.push_back(new Country("United Kingdom", 100, 100, 100, 100, 100, 100, 100, 100, 100, 100));
        countries.push_back(new Country("United States", 100, 100, 100, 100, 100, 100, 100, 100, 100, 100));
    }
    else if (name == "Axis")
    {
        countries.push_back(new Country("Germany", 100, 100, 100, 100, 100, 100, 100, 100, 100, 100));
        countries.push_back(new Country("Italy", 100, 100, 100, 100, 100, 100, 100, 100, 100, 100));
        countries.push_back(new Country("Japan", 100, 100, 100, 100, 100, 100, 100, 100, 100, 100));
    }
    else
    {
        std::cout << "Invalid faction name" << std::endl;
    }
}

void Faction::attack() {
    simulator->notify("attack");
}

void Faction::reStock() {
    simulator->notify("reStock");
}

/**
 * @description Gets the current state of the faction.
 * @return FactionState
 */
FactionState *Faction::getState() {
    std::vector<Country*> countries;
    for (Country* country : this->countries)
    {
        countries.push_back(country);
    }
    return new FactionState(countries);
}

/**
 * @description Gets the number of countries in the faction.
 * @return int - Strength of the faction.
 */
int Faction::getStrength() {
    return countries.size();
}