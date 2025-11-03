#ifndef KALE_H
#define KALE_H

#include "Vegetable.h"
#include "HighMoisture.h"
#include "NoPrune.h"

/**
 * @class Kale
 * @author Cailin Smith
 * @brief Represents a Kale vegetable plant.
 * Design Pattern: Abstract Factory
 * Participant: ConcreteProduct
 * 
 * This class represents a Kale plant, which is a vegetable with high moisture watering
 * requirements and no pruning strategy. The plant has a maximum height of 60cm
 * and is available for sale during the Autumn season.
 * 
 * @see Vegetable
 * @see HighMoisture
 * @see NoPrune
 */
class Kale : public Vegetable {

public:
	/**
	 * @brief Constructs a Kale plant with default characteristics.
	 * 
	 * Initializes the Kale plant with a maximum height of 60cm, high moisture watering
	 * strategy, no pruning strategy, and sets it as available for sale in Autumn.
	 */
	Kale() : Vegetable(60, new HighMoisture(), new NoPrune(), "Kale", "Autumn") {}
	
	/**
	 * @brief Gets the image path for the Kale plant.
	 * @return string The path to the Kale image asset.
	 */
	string getImagePath() override {
		return "assets/kale.jpg";
	}
};

#endif
