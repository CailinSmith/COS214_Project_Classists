#ifndef DRYPLANT_H
#define DRYPLANT_H

#include "WateringStrategy.h"
#include "Plant.h"
#include <string>
#include <iostream>
using namespace std;

/**
 * @class DryPlant
 * @author Cailin Smith
 * @brief Implements dry/low moisture watering strategy for plants.
 * Design Pattern: Strategy
 * Participant: ConcreteStrategy
 * 
 * This class implements a watering strategy for plants that require minimal water
 * and thrive in dry conditions. This strategy is typically used for drought-tolerant
 * plants such as cacti and succulents that need infrequent watering.
 * 
 * @see WateringStrategy
 * @see Plant
 */
class DryPlant : public WateringStrategy {
public:
	/**
	 * @brief Applies dry/minimal watering to the specified plant.
	 * @param plant Pointer to the Plant object to be watered using dry plant technique.
	 */
	void water(Plant* plant);
	
	/**
	 * @brief Returns a string description of this watering strategy.
	 * @return string A text description of the dry plant watering method.
	 */
	string print();
};

#endif
