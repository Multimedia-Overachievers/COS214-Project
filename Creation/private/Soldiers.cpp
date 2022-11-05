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
 * The starting hp and dmg are set to it's type
 * - this later changes when squads are added, and becomes the total of all squads + the soldier's bonus hp and dmg respectively
 * The bonus hp and dmg are set to the soldier's type and change as the name changes (see changeName())
 *
 * @param name The name of the soldiers (enum) - default is SquadStd, options are SquadStd, Platoon, Company, Battalion, Army
 * @param state The state of the soldiers (enum) - default is Readt, options are Ready, Moving, Defeated
 */
Soldiers::Soldiers(Name name, State state) : Troops(name, state)
{
    switch (name)
    {
    case Platoon:
        setDMG(PlatoonDmg);
        setHP(PlatoonHp);
        this->bonusDMG = PlatoonDmg;
        this->bonusHP = PlatoonHp;
        break;
    case Company:
        setDMG(CompanyDmg);
        setHP(CompanyHp);
        this->bonusDMG = CompanyDmg;
        this->bonusHP = CompanyHp;
        break;
    case Battalion:
        setDMG(BattalionDmg);
        setHP(BattalionHp);
        this->bonusDMG = BattalionDmg;
        this->bonusHP = BattalionHp;
        break;
    case Army:
        setDMG(ArmyDmg);
        setHP(ArmyHp);
        this->bonusDMG = ArmyDmg;
        this->bonusHP = ArmyHp;
        break;
    default:
        setDMG(SquadDmg);
        setHP(SquadHp);
        this->bonusDMG = SquadDmg;
        this->bonusHP = SquadHp;
        break;
    }
}

/**
 * @brief Destroy the Soldiers:: Soldiers object
 * @details Deletes all squads associated with it
 * @attention Composite will destroy itself - no need to delete leaves / components
 *
 */
Soldiers::~Soldiers()
{
    TroopIterator *it = createIterator();
    it->first();
    while (!it->isDone())
    {
        delete it->current();
        it->next();
    }
    squads.clear();
    delete it;
    it = nullptr;
}

/**
 * @brief This function allows soldiers to take damage if they are not moving or defeated
 * @details This function will take the total damage and distribute it to the squads
 * The first squad in the vector will be affected first, than any leftovers will be distributed to the next squad, and so on
 * Moving or Defeated soldiers / squads cannot take damage and will not be affected (the damage will be ignored and the function will return 0)
 * The damage is first checked against the composite's total hp, if the damage is greater than the total hp, the composite is automatically defeated
 * @attention Any squads that are defeated will be removed from the vector and deleted automatically (!)
 *
 * @param total The total damage the soldiers will take
 * @return int The remaining hp of the soldiers
 */
int Soldiers::takeDMG(int total)
{
    int hp = getTotalHP();
    if (getState() != Defeated && getState() != Moving)
    {
        hp -= total;
        TroopIterator *it = createIterator();
        if (hp <= 0)
        { // if the damage is greater than the total hp, the composite is automatically defeated
            setState(Defeated);
            setDMG(0);
            setHP(0);
            // set all my squads to defeated
            it->first();
            while (!it->isDone())
            {
                it->current()->takeDMG(total);
                it->next();
            }
        }
        else
        { // if the damage is less than the total hp, the composite will take the damage (and still live)
            // let the squads take the damage
            // start at the first squad
            // if that squad is defeated, let the next squad take the damage and so on
            int i = 0;
            it->first();
            do
            {
                if (squads[i]->getState() != Defeated || squads[i]->getState() != Moving)
                {
                    int DMGTaken = it->current()->getTotalHP(); // get the total hp of the squad before attacking
                    it->current()->takeDMG(total);              // attack the squad
                    // if the squad is defeated, subtract the damage taken (original HP) from the total damage needed to be distributed and move on to the next squad
                    // if it is not defeated, the total damage will move to <= 0 and thus the loop will end
                    total -= DMGTaken;
                }
                it->next();
            } while (total > 0 && !it->isDone());
            // recalculate the total hp and dmg of the composite
            setHP(hp);
            setDMG(getTotalDMG());
        }
        // clean up any squads that are defeated
        clearSquads();
        changeName();
        delete it;
    }
    return hp;
}

string Soldiers::getReport()
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
    string name = "";
    switch (getName())
    {
    case SquadStd:
        name = "Squad";
        break;
    case Platoon:
        name = "Platoon";
        break;
    case Company:
        name = "Company";
        break;
    case Battalion:
        name = "Battalion";
        break;
    case Army:
        name = "Army";
        break;
    }
    string report = "";
    report += "Soldiers: " + name + " of " + to_string(squads.size()) + " troops\n";
    report += "\t HP: " + to_string(getTotalHP()) + " DMG: " + to_string(getTotalDMG()) + " State: " + state + "\n";
    // get the report of the squads
    TroopIterator *it = createIterator();
    it->first();
    while (!it->isDone())
    {
        report += it->current()->getReport();
        it->next();
    }
    delete it;
    return report;
}

/**
 * @brief This function is used to disband the soldiers into squads (completely emptying the soldiers / unravelling the composite)
 * @details This function will disband the soldiers into squads, iterating down the composite and unraveling each one
 * Any Defeated squads will be removed from the vector and deleted automatically (memory will be cleared)
 * All other squads will be added to the vector and returned
 * @warning This disbands the soldiers entirely, so the soldiers will be empty after this function is called
 *
 * @return vector<Troops *> All of the squads that were contained in the soldiers
 */
vector<Troops *> Soldiers::disband()
{
    vector<Troops *> disbandedSquads;
    int left = clearSquads();
    if (left == 0)
    {
        return vector<Troops *>();
    }
    TroopIterator *it = createIterator();
    it->first();
    while (!it->isDone())
    {
        vector<Troops *> temp = it->current()->disband();
        move(temp.begin(), temp.end(), back_inserter(disbandedSquads));
        temp.clear();
        it->next();
    }
    squads.clear();
    changeName();
    delete it;
    return disbandedSquads;
}

/**
 * @brief This function is used to build the soldiers composite from a vector of squads (which will then be cleared)
 * @details This function will build the soldiers composite, adding the given squads to the vector
 * @attention Any squads that are Defeated will be removed from the vector and deleted automatically (memory will be cleared)
 * The soldiers will then be updated automatically with new state, hp, dmg and buffs as needed
 * Defeated soldiers will be recycled
 * @warning The given vector will be cleared after this function is called to avoid memory leaks / dangling pointers
 *
 * @param squads The squads to be added to the soldiers
 */
void Soldiers::build(vector<Troops *> squads)
{
    if (getState() == Defeated)
    {
        clearSquads();
        setState(Ready);
    }
    for (int i = 0; i < squads.size(); i++)
    {
        if (squads[i]->getState() != Defeated)
        {
            this->squads.push_back(squads[i]);
        }
        else
        {
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
 * If the given squad is Defeated, it will be deleted automatically (memory will be cleared)
 * The soldiers will then be updated automatically with new state, hp, dmg and buffs as needed
 * Defeated soldiers will be recycled
 *
 * @param squad The squad to be added to the soldiers
 */
void Soldiers::add(Troops *squad)
{
    if (squad->getState() == Defeated)
    {
        delete squad;
        squad == nullptr;
        return;
    }
    if (getState() == Defeated)
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
 * @details This function will remove the given number of squads from the soldiers vector (starting at the beginning)
 * Any squads that are Defeated will be removed from the vector and deleted automatically (memory will be cleared)
 * The soldiers will then be updated automatically with new state, hp, dmg and buffs as needed
 * @attention May return an empty vector if there are no squads to remove
 *
 * @param noToRemove The number of squads to remove
 * @return vector<Troops *> The squads that were removed
 */
vector<Troops *> Soldiers::remove(int noToRemove)
{
    int left = clearSquads();
    if (left == 0)
    {
        return vector<Troops *>();
    }
    vector<Troops *> removedSquads;
    if (noToRemove > this->squads.size())
    { // bounds checking
        noToRemove = this->squads.size();
    }
    TroopIterator *it = createIterator();
    it->first();
    while (!it->isDone() && noToRemove > 0)
    {
        removedSquads.push_back(squads[it->getIndex()]);
        squads.erase(squads.begin() + it->getIndex());
        it->next();
    }
    setHP(getTotalHP());
    setDMG(getTotalDMG());
    changeName();
    delete it;
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
    if (getState() == Defeated || getState() == Moving)
    {
        return 0;
    }
    int total = this->bonusHP;
    TroopIterator *it = createIterator();
    it->first();
    while (!it->isDone())
    {
        total += it->current()->getTotalHP();
        it->next();
    }
    delete it;
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
    if (getState() == Defeated || getState() == Moving)
    {
        return 0;
    }
    int total = this->bonusDMG;
    TroopIterator *it = createIterator();
    it->first();
    while (!it->isDone())
    {
        total += it->current()->getTotalDMG();
        it->next();
    }
    delete it;
    return total;
}

/**
 * @brief This function is used to get the total number of squads in the soldiers
 * @details This function will get the total number of squads in the soldiers by iterating through the squads and adding their number
 *
 * @return int The total number of squads in the soldiers
 */
int Soldiers::getTotalTroops()
{
    int total = 0;
    TroopIterator *it = createIterator();
    it->first();
    while (!it->isDone())
    {
        total += it->current()->getTotalTroops();
        it->next();
    }
    delete it;
    return total;
}

/**
 * @brief This function is used to change the state of the soldiers
 * @details This function will change the state of the soldiers and all squads in the vector
 *
 */
void Soldiers::changeState()
{
    Troops::changeState();
    TroopIterator *it = createIterator();
    it->first();
    while (!it->isDone())
    {
        it->current()->changeState();
        it->next();
    }
    delete it;
}

/**
 * @brief This function is used to dynamically change the name of the soldiers
 * The name of the composite (and its buff if it has one) will be changed to reflect the number of squads it contains
 *
 */
void Soldiers::changeName()
{
    // change the name of the composite to reflect the number of squads it contains
    if (squads.size() <= 1)
    { // SQUAD -> 0-1 squads
        setName(SquadStd);
        this->bonusDMG = SquadDmg;
        this->bonusHP = SquadHp;
    }
    else if (squads.size() <= 4)
    { // PLATOON -> 2-4 squads
        setName(Platoon);
        this->bonusDMG = PlatoonDmg;
        this->bonusHP = PlatoonHp;
    }
    else if (squads.size() <= 20)
    { // COMPANY -> 3-5 platoons = 6-20 squads
        setName(Company);
        this->bonusDMG = CompanyDmg;
        this->bonusHP = CompanyHp;
    }
    else if (squads.size() <= 60)
    { // BATTALION -> 4-6 companies = 24-60 squads
        setName(Battalion);
        this->bonusDMG = BattalionDmg;
        this->bonusHP = BattalionHp;
    }
    else
    { // ARMY -> <8 battalions = 96-180 squads
        setName(Army);
        this->bonusDMG = ArmyDmg;
        this->bonusHP = ArmyHp;
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
    TroopIterator *it = createIterator();
    it->first();
    while (!it->isDone())
    {
        if (it->current()->getState() == Defeated)
        {
            delete it->current();
            squads[it->getIndex()] = nullptr;
            squads.erase(squads.begin() + it->getIndex());
        }
        it->next();
    }
    delete it;
    return this->squads.size();
}

/**
 * @brief This function is used to create a squadIterator for the soldiers
 * @details This function will create a squadIterator for the soldiers
 * The squadIterator will be used to iterate through the squads vector
 * @attention The squadIterator will be deleted automatically when the soldiers is deleted
 *
 * @return TroopIterator * The squadIterator for the soldiers
 */
TroopIterator *Soldiers::createIterator()
{
    return new SquadIterator(this);
}
/**
 * @brief This function is used to get the squads vector
 * @details This function will return the squads vector
 *
 * @return vector<Troops *> The squads vector
 */
vector<Troops *> Soldiers::getTroops()
{
    return this->squads;
}