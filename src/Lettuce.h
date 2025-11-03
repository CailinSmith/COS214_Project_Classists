#ifndef LETTUCE_H
#define LETTUCE_H

#include "Vegetable.h"
#include "HighMoisture.h"
#include "NoPrune.h"

/**
 * @class Lettuce
 * @author Cailin Smith
 * @brief Represents a Lettuce vegetable plant.
 * Design Pattern: Abstract Factory
 * Participant: ConcreteProduct
 * 
 * This class represents a Lettuce plant, which is a vegetable with high moisture watering
 * requirements and no pruning strategy. The plant has a maximum height of 30cm
 * and is available for sale during the Spring season.
 * 
 * @see Vegetable
 * @see HighMoisture
 * @see NoPrune
 */
class Lettuce : public Vegetable {
public:
	/**
	 * @brief Constructs a Lettuce plant with default characteristics.
	 * 
	 * Initializes the Lettuce plant with a maximum height of 30cm, high moisture watering
	 * strategy, no pruning strategy, and sets it as available for sale in Spring.
	 */
	Lettuce() : Vegetable(30, new HighMoisture(), new NoPrune(), "Lettuce", "Spring") {}
	
	/**
	 * @brief Gets the image path for the Lettuce plant.
	 * @return string The path to the Lettuce image asset.
	 */
	string getImagePath() override {
		return "assets/lettuce.jpg";
	}
};

#endif
