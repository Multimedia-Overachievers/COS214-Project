/*
 *  Soldiers.cpp
 *  Created on: 10/15/2022.
 *  Author: Tayla Orsmond (u21467456)
 */

#include <iostream>
#include "../public/Soldiers.h"


/**
 * @brief Construct a new Soldiers:: Soldiers object
 * @details Defaults everything to SquadStd if no parameters are provided
 * 
 * @param name The name of the soldiers (enum) - default is SquadStd, options are SquadStd, Platoon, Company, Battalion, Army
 * @param state The state of the soldiers (enum) - default is Readt, options are Ready, Moving, Defeated
 */
Soldiers::Soldiers(Name name = SquadStd, State state = Ready) : Troops(name, state)
{
    switch(name)
    {
        case SquadStd:
            setDMG(SquadDmg);
            setHP(SquadHp);
            break;
        case Company:
            setDMG(CompanyDmg);
            setHP(CompanyHp);
            break;
        case Battalion:
            setDMG(BattalionDmg);
            setHP(BattalionHp);
            break;
        case Army:
            setDMG(ArmyDmg);
            setHP(ArmyHp);
            break;
        default:
            setDMG(PlatoonDmg);
            setHP(PlatoonHp);
            break;
    }
}

// Soldiers::Soldiers(Name name = Platoon) : Troops(name)
// {
//     switch(name)
//     {
//         case Platoon:
//             setDMG(PlatoonDmg);
//             setHP(PlatoonHp);
//             break;
//         case Company:
//             setDMG(CompanyDmg);
//             setHP(CompanyHp);
//             break;
//         case Battalion:
//             setDMG(BattalionDmg);
//             setHP(BattalionHp);
//             break;
//         case Army:
//             setDMG(ArmyDmg);
//             setHP(ArmyHp);
//             break;
//         default:
//             setDMG(PlatoonDmg);
//             setHP(PlatoonHp);
//             break;
//     }
// }

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
 * Moving and Defeated soldiers cannot take damage and will not be affected
 * The damage is first checked against the composite's total hp, if the damage is greater than the total hp, the composite is automatically defeated
 * Any squads that are defeated will be removed from the vector and deleted automatically
 * 
 * @param total The total damage the soldiers will take
 * @return int The remaining hp of the soldiers
 */
int Soldiers::takeDMG(int total)
{
    if(getState() != Defeated && getState() != Moving)
    {
        int hp = getTotalHP();
        hp -= total;
        if(hp <= 0)
        
        {
            setState(Defeated);
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
                    setState(Defeated);
                    setDMG(0);
                    setHP(0);
                    break;
                }
                else if(squads[i]->getState() != Defeated || squads[i]->getState() != Moving)
                {
                    total -= squads[i]->takeDMG(total);
                    if(squads[i]->getState() == Defeated)
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
            setState(Defeated);
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

// void Soldiers::buffDMG(int buff)
// {
//     //if my state is not defeated
//     //then buff the damage of all my squads
//     if(getState() != Defeated)
//     {
//         for(int i = 0; i < squads.size(); i++)
//         {
//             if(squads[i]->getState() != Defeated)
//             {
//                 squads[i]->buffDMG(buff);
//             }
//         }
//         setBuffDMG(buff);
//     }
// }

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
 * Any Defeated squads will be removed from the vector and deleted automatically (memory will be cleared)
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
 * Any squads that are Defeated will be removed from the vector and deleted automatically (memory will be cleared)
 * The soldiers will then be updated automatically with new state, hp, dmg and buffs as needed
 * Defeated soldiers will be recycled
 * 
 * @param squads The squads to be added to the soldiers
 */
void Soldiers::build(vector<Troops *> squads)
{
    if(getState() == Defeated)
    {
        clearSquads();
        setState(Ready);
    }
    for(int i = 0; i < squads.size(); i++){
        if(squads[i]->getState() != Defeated){
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
 * Defeated soldiers will be recycled
 * 
 * @param squad The squad to be added to the soldiers
 */
void Soldiers::add(Troops * squad)
{
    if(squad->getState() == Defeated)
    {
        delete squad;
        squad == nullptr;
        return;
    }
    if(getState() == Defeated)
    {
        clearSquads();
        setState(Ready);
    }
    squads.push_back(squad);
    setHP(getTotalHP());
    setDMG(getTotalDMG());
    changeName();
}

/**
 * @brief This function is used to remove squads from the soldiers
 * @details This function will remove the given number of squads from the soldiers vector (starting at the end)
 * Any squads that are Defeated will be removed from the vector and deleted automatically (memory will be cleared)
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
    if(getState() == Defeated)
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
    if(getState() == Defeated)
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
        setName(Platoon);
        this->compositeBuff = 10;
    }
    else if(squads.size() < 6 && squads.size() > 2){
        setName(Platoon);
        this->compositeBuff = 20;
    }
    else if(squads.size() < 24 && squads.size() > 6){
        setName(Battalion);
        this->compositeBuff = 30;
    }
    else{
        setName(Army);
        this->compositeBuff = 40;
    }  
}

/**
 * @brief This function is used to clear the squads vector of any Defeated squads
 * @details This function will iterate through the squads vector and remove any Defeated squads
 * Any squads that are Defeated will be removed from the vector and deleted automatically (memory will be cleared)
 * 
 * @return int The number of squads left in the vector
 */
int Soldiers::clearSquads()
{
    for(int i = 0; i < this->squads.size(); i++)
    {
        if(this->squads[i]->getState() == Defeated || this->squads[i]->getTotalHP() == 0)
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