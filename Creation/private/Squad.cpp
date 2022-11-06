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
Squad::Squad(Name name, State state) : Troops(Name::SquadStd, state)
{
    setDMG(SquadDmg);
    setHP(SquadHp);
}

Squad::~Squad() = default; // dtor

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
    if (getState() != Moving && getState() != Defeated)
    {
        hp -= total;
        setHP(hp);
        if (hp <= 0)
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
    string state;
    switch (getState())
    {
    case Ready:
        state = "Ready";
        break;
    case Moving:
        state = "Moving";
        break;
    case Defeated:
        state = "Defeated";
    }
    return "Squad: " + state + "\tHP: " + to_string(getTotalHP()) + "\tDMG: " + to_string(getTotalDMG()) + "\n";
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
 * @brief This function is used to remove a number of squads from the squad
 * @details This function does nothing and will return a vector containing this squad
 *
 * @param noToRemove - the number of squads to remove
 * @return vector<Troops *> containing the squad
 */
vector<Troops *> Squad::disband(int noToRemove)
{
    vector<Troops *> squads;
    squads.push_back(this);
    return squads;
}

/**
 * @brief This function is used to build the squad
 * @details This function will do nothing, because you cannot add squads to a squad
 * The memory will be freed and all pointers cleared
 * @note Assume anything you add to a squad is deleted
 *
 * @param squads = vector<Troops *> containing the squads, will be deleted (!)
 */
void Squad::build(vector<Troops *> squads)
{
    for (int i = 0; i < squads.size(); i++)
    {
        delete squads[i];
    }
    squads.clear();
}

/**
 * @brief This function is used to add a squad to the squad
 * @details This function will recycle the squad if it's current state is Defeated
 * Otherwise it will do nothing, and the memory will be freed and all pointers cleared
 * @note Assume anything you add to a squad is deleted
 *
 * @param squad - the squad to be added, will be deleted (!)
 */
void Squad::build(Troops *squad)
{
    // recycle me if my state is DEFATED
    // otherwise do nothing
    if (getState() == Defeated)
    {
        setHP(squad->getTotalHP());
        setDMG(squad->getTotalDMG());
        setState(Ready);
    }
    delete squad;
    squad = nullptr;
}

/**
 * @brief This function is used to add a number of squads to the squad (does nothing)
 * @details This function does nothing, because you cannot add squads to a squad
 * @note Assume anything you add to a squad is deleted
 *
 * @param noToAdd - the number of squads to add
 */
void Squad::build(int noToAdd)
{
    // do nothing
}

/**
 * @brief This function is used to get the total hp of the squad
 * @details This function will return the hp of the squad
 *
 * @return int - the hp of the squad
 */
int Squad::getTotalHP()
{
    if (getState() == Defeated || getState() == Moving)
    {
        return 0;
    }
    return this->getHP();
}

/**
 * @brief This function is used to get the total dmg of the squad
 * @details This function will return the dmg of the squad
 *
 * @return int - the dmg of the squad
 */
int Squad::getTotalDMG()
{
    if (getState() == Defeated || getState() == Moving)
    {
        return 0;
    }
    return this->getDMG();
}

/**
 * @brief This function is used to get the number of squads in the squad
 * @details This function will return 1 (the squad itself)
 *
 * @return int - the number of squads in the squad
 */
int Squad::getTotalTroops()
{
    return 1;
}

/**
 * @brief This function is used to create an iterator for the squad
 * @details This function will return a new SquadIterator
 *
 * @return TroopIterator* - the iterator for the squad
 */
TroopIterator *Squad::createIterator()
{
    return new SquadIterator(this);
}

/**
 * @brief This function is used to get the squads in the squad
 * @details This function will return a vector containing the squad
 *
 * @return vector<Troops *> - a vector containing the squad
 */
vector<Troops *> Squad::getTroops()
{
    vector<Troops *> squads;
    squads.push_back(this);
    return squads;
}