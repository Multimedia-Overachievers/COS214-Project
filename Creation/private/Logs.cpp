#include "../public/Logs.h"

/**
 * Constructor for Logs
 */
Logs::Logs() {}

/**
 * Destructor for Logs
 */
Logs::~Logs() 
{
    for (int i = 0; i < this->logs.size(); i++)
    {
        delete this->logs[i];
    }
}

/**
 * Gets the logs
 * @return logs
 */
MapState* Logs::getLogs() {
    return this->logs;
}

/**
 * Creates a log and pushes it to the logs vector
 * @param state
 */
void Logs::CreateLog(MapState* state) {
    this->logs.push_back(state);
}