#ifndef BASIL_H
#define BASIL_H

#include "Herb.h"
#include "HighMoisture.h"
#include "Thinning.h"

/**
 * @class Basil
 * @author Cailin Smith
 * @brief Represents a Basil herb plant.
 * Design Pattern: Abstract Factory
 * Participant: ConcreteProduct
 * 
 * This class represents a Basil plant, which is an herb with high moisture watering
 * requirements and thinning pruning strategy. The plant has a maximum height of 60cm
 * and is available for sale during the Summer season.
 * 
 * @see Herb
 * @see HighMoisture
 * @see Thinning
 */
class Basil : public Herb {
public:
	/**
	 * @brief Constructs a Basil plant with default characteristics.
	 * 
	 * Initializes the Basil plant with a maximum height of 60cm, high moisture watering
	 * strategy, thinning pruning strategy, and sets it as available for sale in Summer.
	 */
	Basil() : Herb(60, new HighMoisture(), new Thinning(), "Basil", "Summer") {}
	
	/**
	 * @brief Gets the image path for the Basil plant.
	 * @return string The path to the Basil image asset.
	 */
	string getImagePath() override {
		return "assets/basil.jpg";
	}
};

#endif
