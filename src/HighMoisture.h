#ifndef HIGHMOISTURE_H
#define HIGHMOISTURE_H

#include "WateringStrategy.h"
#include "Plant.h"
#include <string>
#include <iostream>
using namespace std;

/**
 * @class HighMoisture
 * @author Cailin Smith
 * @brief Implements high moisture watering strategy for plants.
 * Design Pattern: Strategy
 * Participant: ConcreteStrategy
 * 
 * This class implements a watering strategy for plants that require frequent watering
 * and consistently moist soil. This strategy is typically used for water-loving plants
 * such as certain vegetables, aquatic plants, and tropical species.
 * 
 * @see WateringStrategy
 * @see Plant
 */
class HighMoisture : public WateringStrategy {
public:
	/**
	 * @brief Applies high moisture watering to the specified plant.
	 * @param plant Pointer to the Plant object to be watered with high moisture technique.
	 */
	void water(Plant* plant);
	
	/**
	 * @brief Returns a string description of this watering strategy.
	 * @return string A text description of the high moisture watering method.
	 */
	string print();
};

#endif
