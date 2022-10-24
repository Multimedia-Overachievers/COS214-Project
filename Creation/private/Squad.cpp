/*
 *  Squad.cpp
 *  Created on: 10/15/2022.
 *  Author: Tayla Orsmond (u21467456)
 */

#include "../public/Squad.h"

/**
 * @brief Construct a new Squad:: Squad object
 * 
 * @param name The name of the squad (enum) - default is SquadStd, options are SquadStd
 * @param state The state of the squad (enum) - default is Ready, options are Ready, Moving, Defeated
 */
Squad::Squad(Name name = SquadStd, State state = Ready) : Troops(name, state)
{
    setDMG(SquadDmg);
    setHP(SquadHp);
}

Squad::~Squad() = default; //dtor

/**
 * @brief This function is used to take damage from the enemy
 * @details Provide the total damage the squad will take
 * If the squad is defeated, it's state is set to Defeated, and it's hp and dmg are set to 0
 * 
 * @param total The total damage the squad will take
 * @return The hp left after the damage is taken
 */
int Squad::takeDMG(int total)
{
    int hp = getTotalHP();
    if(getState() != Moving && getState() != Defeated)
    {
        hp -= total;
        setHP(hp);
        if(hp <= 0)
        {
            setState(Defeated);
            setDMG(0);
            setHP(0);
        }
    }
    return hp;
}

/**
 * @brief This function is used to generate a report of the squad
 * @details This function will generate a report of the squad's name, state, hp and dmg
 * 
 * @return string 
 */
string Squad::getReport()
{
    string report = "";
    report += "Squad: \n";
    report += "\tHP: " + to_string(getTotalHP()) + " ";
    report += "\tDMG: " + to_string(getTotalDMG()) + " ";
    report += "\tState: " + to_string(getState()) + "\n";
    return report;
}

/**
 * @brief This function is used to disband the squad
 * @details This function will return a vector containing this squad
 * 
 * @return vector<Troops *> containing the squad
 */
vector<Troops *> Squad::disband()
{
    vector<Troops *> squads;
    squads.push_back(this);
    return squads;
}

/**
 * @brief This function is used to build the squad
 * @details This function will do nothing, and the memory will be freed and all pointers cleared
 * 
 * @param squads = vector<Troops *> containing the squads, will be deleted (!)
 */
void Squad::build(vector<Troops *> squads)
{
    for(int i = 0; i < squads.size(); i++){
        delete squads[i];
    }
    squads.clear();
}

/**
 * @brief This function is used to add a squad to the squad
 * @details This function will recycle the squad if it's current state is Defeated
 * Otherwise it will do nothing, and the memory will be freed and all pointers cleared
 * 
 * @param squad - the squad to be added, will be deleted (!)
 */
void Squad::add(Troops * squad)
{
    //recycle me if my state is DEFATED
    //otherwise do nothing
    if(getState() == Defeated)
    {
        setHP(squad->getTotalHP());
        setDMG(squad->getTotalDMG());
        setState(Ready);
    }
    delete squad;
    squad = nullptr;
}

/**
 * @brief This function is used to remove a squad from the squad
 * @details This function does nothing and will return an empty vector
 * 
 * @param noToRemove - the number of squads to remove
 * @return vector<Troops *> containing the squad - will be empty
 */
vector<Troops *> Squad::remove(int noToRemove)
{
    return vector<Troops *>();
}

