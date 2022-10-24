/*
 *  Soldiers.cpp
 *  Created on: 10/15/2022.
 *  Author: Tayla Orsmond (u21467456)
 */

#include "../public/Soldiers.h"

/**
 * @brief Construct a new Soldiers:: Soldiers object
 * @details Defaults everything to SQUAD if no parameters are provided
 * 
 * @param name The name of the soldiers (enum) - default is SQUAD, options are SQUAD, PLATOON, COMPANY, BATTALION, ARMY
 * @param state The state of the soldiers (enum) - default is READY, options are READY, MOVING, DEFEATED
 */
Soldiers::Soldiers(NAME name = SQUAD, STATE state = READY) : Troops(name, state)
{
    switch(name)
    {
        case SQUAD:
            setDMG(SquadDmg);
            setHP(SquadHp);
            break;
        case PLATOON:
            setDMG(PlatoonDmg);
            setHP(PlatoonHp);
            break;
        case COMPANY:
            setDMG(CompanyDmg);
            setHP(CompanyHp);
            break;
        case BATTALION:
            setDMG(BattalionDmg);
            setHP(BattalionHp);
            break;
        case ARMY:
            setDMG(ArmyDmg);
            setHP(ArmyHp);
            break;
        default:
            setDMG(SquadDmg);
            setHP(SquadHp);
            break;
    }
}

/**
 * @brief Destroy the Soldiers:: Soldiers object
 * @details Deletes all squads associated with it
 * Composite will destroy itself - no need to delete leaves
 * 
 */
Soldiers::~Soldiers()
{
    for(int i = 0; i < squads.size(); i++)
    {
        delete squads[i];
    }
    squads.clear();
}

/**
 * @brief This function allows soldiers to take damage
 * @details This function will take the total damage and distribute it to the squads
 * The first squad in the vector will be affected first, than any leftovers will be distributed to the next squad, and so on
 * MOVING and DEFEATED soldiers cannot take damage and will not be affected
 * The damage is first checked against the composite's total hp, if the damage is greater than the total hp, the composite is automatically defeated
 * Any squads that are defeated will be removed from the vector and deleted automatically
 * 
 * @param total The total damage the soldiers will take
 * @return int The remaining hp of the soldiers
 */
int Soldiers::takeDMG(int total)
{
    if(getState() != DEFEATED && getState() != MOVING)
    {
        int hp = getTotalHP();
        hp -= total;
        if(hp <= 0)
        {
            setState(DEFEATED);
            setDMG(0);
            setHP(0);
            //set all my squads to defeated
            for(int i = 0; i < squads.size(); i++)
            {
                squads[i]->takeDMG(squads[i]->getTotalHP());
            }
        }
        else 
        {
            //else let the squads take the damage
            //start at the first squad
            //if that squad is defeated, then move to the next one
            //if all squads are defeated, then set my state to defeated
            int i = 0;
            while(total > 0)
            {
                if(i >= squads.size())
                {
                    setState(DEFEATED);
                    setDMG(0);
                    setHP(0);
                    break;
                }
                else if(squads[i]->getState() != DEFEATED && squads[i]->getState() != MOVING)
                {
                    total -= squads[i]->takeDMG(total);
                    if(squads[i]->getState() == DEFEATED)
                    {
                        i++;
                    }
                }
                else
                {
                    i++;
                }
            }
        }
        int left = clearSquads();
        if(left == 0){
            setState(DEFEATED);
            setDMG(0);
            setHP(0);
            squads.clear();
        }
        setHP(getTotalHP());
        setDMG(getTotalDMG());
        changeName();
    }
    return getTotalHP();
}

/**
 * @brief This function is used to generate a report of the soldiers
 * @details This function will generate a report of hp, dmg, number and state of the soldiers and all squads associated with it
 * 
 * @return string 
 */

string Soldiers::getReport()
{
    string report = "";
    report += "Soldiers: " + to_string(getName()) + " of " + to_string(squads.size()) + " squads\n";
    report += "\tHP: " + to_string(getTotalHP()) + " ";
    report += "\tDMG: " + to_string(getTotalDMG()) + " ";
    report += "\tState: " + to_string(getState()) + "\n";
    //get the report of the squads
    for(int i = 0; i < squads.size(); i++)
    {
        report += squads[i]->getReport();
    }
    return report;
}

/**
 * @brief This function is used to disband the soldiers into squads
 * @details This function will disband the soldiers into squads, iterating down the composite and unraveling each one
 * Any DEFEATED squads will be removed from the vector and deleted automatically (memory will be cleared)
 * All other squads will be added to the vector and returned
 * 
 * @return vector<Troops *> All of the squads that were contained in the soldiers
 */
vector<Troops *> Soldiers::disband()
{
    vector<Troops *> disbandedSquads;
    int left = clearSquads();
    if(left == 0){
        return vector<Troops *>();
    }
    for(int i = 0; i < squads.size(); i++)
    {
        vector<Troops *> temp = squads[i]->disband();
        move(temp.begin(), temp.end(), back_inserter(disbandedSquads));
        temp.clear();
    }
    setHP(getTotalHP());
    setDMG(getTotalDMG());
    changeName();
    return disbandedSquads;
}

/**
 * @brief This function is used to build the soldiers composite
 * @details This function will build the soldiers composite, adding the given squads to the vector
 * Any squads that are DEFEATED will be removed from the vector and deleted automatically (memory will be cleared)
 * The soldiers will then be updated automatically with new state, hp, dmg and buffs as needed
 * DEFEATED soldiers will be recycled
 * 
 * @param squads The squads to be added to the soldiers
 */
void Soldiers::build(vector<Troops *> squads)
{
    if(getState() == DEFEATED)
    {
        clearSquads();
        setState(READY);
    }
    for(int i = 0; i < squads.size(); i++){
        if(squads[i]->getState() != DEFEATED){
            this->squads.push_back(squads[i]);
        }
        else{
            delete squads[i];
        }
    }
    squads.clear();
    setHP(getTotalHP());
    setDMG(getTotalDMG());
    changeName();
}

/**
 * @brief This function is used to add a squad to the soldiers
 * @details This function will add a squad to the squads vector
 * The soldiers will then be updated automatically with new state, hp, dmg and buffs as needed
 * DEFEATED soldiers will be recycled
 * 
 * @param squad The squad to be added to the soldiers
 */
void Soldiers::add(Troops * squad)
{
    if(squad->getState() == DEFEATED)
    {
        delete squad;
        squad == nullptr;
        return;
    }
    if(getState() == DEFEATED)
    {
        clearSquads();
        setState(READY);
    }
    squads.push_back(squad);
    setHP(getTotalHP());
    setDMG(getTotalDMG());
    changeName();
}

/**
 * @brief This function is used to remove squads from the soldiers
 * @details This function will remove the given number of squads from the soldiers vector (starting at the end)
 * Any squads that are DEFEATED will be removed from the vector and deleted automatically (memory will be cleared)
 * The soldiers will then be updated automatically with new state, hp, dmg and buffs as needed
 * 
 * @param noToRemove The number of squads to remove
 * @return vector<Troops *> The squads that were removed
 */
vector<Troops *> Soldiers::remove(int noToRemove)
{
    int left = clearSquads();
    if(left == 0)
    {
        return vector<Troops *>();
    }
    vector<Troops *> removedSquads;
    if(noToRemove > this->squads.size())
    {
        noToRemove = this->squads.size();
    }
    for(int i = 0; i < noToRemove; i++)
    {
        removedSquads.push_back(this->squads[i]);
    }
    this->squads.erase(this->squads.begin(), this->squads.begin() + noToRemove);
    setHP(getTotalHP());
    setDMG(getTotalDMG());
    changeName();
    return removedSquads;
}

/**
 * @brief This function is used to get the total hp of the soldiers
 * @details This function will get the total hp of the soldiers by iterating through the squads and adding their hp
 * 
 * @return int The total hp of the soldiers
 */
int Soldiers::getTotalHP()
{
    if(getState() == DEFEATED)
    {
        return 0;
    }
    int total = 0;
    for(int i = 0; i < squads.size(); i++)
    {
        total += squads[i]->getTotalHP();
    }
    return total;
}

/**
 * @brief This function is used to get the total dmg of the soldiers
 * @details This function will get the total dmg of the soldiers by iterating through the squads and adding their dmg
 * 
 * @return int The total dmg of the soldiers
 */
int Soldiers::getTotalDMG()
{
    if(getState() == DEFEATED)
    {
        return 0;
    }
    int total = 0;
    for(int i = 0; i < squads.size(); i++)
    {
        total += squads[i]->getTotalDMG();
    }
    return total;
}

/**
 * @brief This function is used to dynamically change the name of the soldiers
 * The name of the composite (and its buff if it has one) will be changed to reflect the number of squads it contains
 * 
 */
void Soldiers::changeName()
{
    //change my name depending on the number of squads
    if(squads.size() < 2){
        setName(PLATOON);
        this->compositeBuff = 10;
    }
    else if(squads.size() < 6 && squads.size() > 2){
        setName(COMPANY);
        this->compositeBuff = 20;
    }
    else if(squads.size() < 24 && squads.size() > 6){
        setName(BATTALION);
        this->compositeBuff = 30;
    }
    else{
        setName(ARMY);
        this->compositeBuff = 40;
    }  
}

/**
 * @brief This function is used to clear the squads vector of any DEFEATED squads
 * @details This function will iterate through the squads vector and remove any DEFEATED squads
 * Any squads that are DEFEATED will be removed from the vector and deleted automatically (memory will be cleared)
 * 
 * @return int The number of squads left in the vector
 */
int Soldiers::clearSquads()
{
    for(int i = 0; i < this->squads.size(); i++)
    {
        if(this->squads[i]->getState() == DEFEATED || this->squads[i]->getTotalHP() == 0)
        {
            delete this->squads[i];
            this->squads.erase(this->squads.begin() + i);
        }
    }
    return this->squads.size();
}

TroopIterator * Soldiers::createIterator()
{
    return new SquadIterator(this);
}