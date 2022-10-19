#include "../public/HospitalFactory.h"

/**
 * @brief Construct a new Hospital Factory:: Hospital Factory object
 * 
 */
HospitalFactory::HospitalFactory() {};

/**
 * @brief Destroy the Hospital Factory:: Hospital Factory object
 * 
 */
HospitalFactory::~HospitalFactory() {};

/**
 * @brief factoryMethod() used to create a HospitalBuilding object
 * 
 * @return Building* 
 */
Building* HospitalFactory::createBuilding()
{
    return new HospitalBuilding();
}