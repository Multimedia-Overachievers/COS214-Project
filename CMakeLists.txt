cmake_minimum_required(VERSION 3.22)
project(Project)

set(CMAKE_CXX_STANDARD 23)

add_executable(Project
        Driver/private/main.cpp
        Driver/private/Faction.cpp
        Driver/public/Faction.h
        Driver/private/ConcreteSimulator.cpp
        Driver/public/ConcreteSimulator.h
        Driver/public/Simulator.h

        Creation/private/HospitalBuilding.cpp
        Creation/public/HospitalBuilding.h
        Creation/private/BarracksBuilding.cpp
        Creation/public/BarracksBuilding.h
        Creation/private/BuildingFactory.cpp
        Creation/public/BuildingFactory.h
        Creation/public/Building.h

        Manipulation/private/Observer.cpp
        Manipulation/public/Observer.h
        )