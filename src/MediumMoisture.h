#ifndef MEDIUMMOISTURE_H
#define MEDIUMMOISTURE_H

#include "WateringStrategy.h"
#include <string>
#include <iostream>
using namespace std;

/**
 * @class MediumMoisture
 * @author Cailin Smith
 * @brief Implements medium moisture watering strategy for plants.
 * Design Pattern: Strategy
 * Participant: ConcreteStrategy
 * 
 * This class implements a watering strategy for plants that require moderate watering
 * frequency and soil moisture levels. This balanced approach is suitable for most
 * common plants that need regular but not excessive watering.
 * 
 * @see WateringStrategy
 * @see Plant
 */
class MediumMoisture : public WateringStrategy {
public:
	/**
	 * @brief Applies medium moisture watering to the specified plant.
	 * @param plant Pointer to the Plant object to be watered with medium moisture technique.
	 */
	void water(Plant* plant);
	
	/**
	 * @brief Returns a string description of this watering strategy.
	 * @return string A text description of the medium moisture watering method.
	 */
	string print();
};

#endif
