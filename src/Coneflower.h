#ifndef CONEFLOWER_H
#define CONEFLOWER_H

#include "Medicinal.h"
#include "MediumMoisture.h"
#include "DeadPruning.h"

/**
 * @class Coneflower
 * @author Cailin Smith
 * @brief Represents a Coneflower medicinal plant.
 * Design Pattern: Abstract Factory
 * Participant: ConcreteProduct
 * 
 * This class represents a Coneflower plant, which is a medicinal plant with medium moisture
 * watering requirements and dead heading pruning strategy. The plant has a maximum height
 * of 90cm and is available for sale during the Summer season.
 * 
 * @see Medicinal
 * @see MediumMoisture
 * @see DeadPruning
 */
class Coneflower : public Medicinal {

public:
	/**
	 * @brief Constructs a Coneflower plant with default characteristics.
	 * 
	 * Initializes the Coneflower with a maximum height of 90cm, medium moisture watering
	 * strategy, dead heading pruning strategy, and sets it as available for sale in Summer.
	 */
	Coneflower() : Medicinal(90, new MediumMoisture(), new DeadPruning(), "Coneflower", "Summer") {}
	
	/**
	 * @brief Gets the image path for the Coneflower plant.
	 * @return string The path to the Coneflower image asset.
	 */
	string getImagePath() override {
		return "assets/coneflower.jpg";
	}
};

#endif
