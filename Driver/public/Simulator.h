#pragma once 
#include <string>
#include <iostream>

class Simulator
{
public:
    virtual void notify(std::string command) = 0;
};