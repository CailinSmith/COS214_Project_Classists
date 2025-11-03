#ifndef CATTAILS_H
#define CATTAILS_H

#include "Aquatic.h"
#include "HighMoisture.h"
#include "Reduction.h"

/**
 * @class Cattails
 * @author Cailin Smith
 * @brief Represents a Cattails aquatic plant.
 * Design Pattern: Abstract Factory
 * Participant: ConcreteProduct
 * 
 * This class represents a Cattails plant, which is an aquatic plant with high moisture
 * watering requirements and reduction pruning strategy. The plant has a maximum height
 * of 300cm and is available for sale during the Summer season.
 * 
 * @see Aquatic
 * @see HighMoisture
 * @see Reduction
 */
class Cattails : public Aquatic {
	
public:
	/**
	 * @brief Constructs a Cattails plant with default characteristics.
	 * 
	 * Initializes the Cattails plant with a maximum height of 300cm, high moisture watering
	 * strategy, reduction pruning strategy, and sets it as available for sale in Summer.
	 */
	Cattails() : Aquatic(300, new HighMoisture(), new Reduction(), "Cattails", "Summer") {}
	
	/**
	 * @brief Gets the image path for the Cattails plant.
	 * @return string The path to the Cattails image asset.
	 */
	string getImagePath() override {
		return "assets/cattails.jpg";
	}
};

#endif
