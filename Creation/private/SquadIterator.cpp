/*
 *  SquadIterator.cpp
 *  Created on: 10/15/2022.
 *  Author: Tayla Orsmond (u21467456)
 */

#include "../public/SquadIterator.h"

SquadIterator::SquadIterator() : TroopIterator() {}

SquadIterator::SquadIterator(Troops * soldiers) : TroopIterator(soldiers) {}

SquadIterator::~SquadIterator() = default;

Troops * SquadIterator::first()
{
    index = 0;
    if(mytroops->getTroops().size() > 0)
    {
        return mytroops->getTroops().at(index);
    }
    return nullptr;
}

Troops * SquadIterator::next()
{
    index++;
    if (index < mytroops->getTroops().size())
    {
        return mytroops->getTroops().at(index);
    }
    return nullptr;
}

bool SquadIterator::isDone()
{
    return index >= mytroops->getTroops().size();
}

Troops * SquadIterator::current()
{
    if (index < mytroops->getTroops().size())
    {
        return mytroops->getTroops().at(index);
    }
    return nullptr;
}

