#ifndef PANSY_H
#define PANSY_H

#include "Flower.h"
#include "MediumMoisture.h"
#include "DeadPruning.h"

/**
 * @class Pansy
 * @author Cailin Smith
 * @brief Represents a Pansy flower plant.
 * Design Pattern: Abstract Factory
 * Participant: ConcreteProduct
 * 
 * This class represents a Pansy plant, which is a flowering plant with medium moisture
 * watering requirements and dead heading pruning strategy. The plant has a maximum
 * height of 25cm and is available for sale during the Spring season.
 * 
 * @see Flower
 * @see MediumMoisture
 * @see DeadPruning
 */
class Pansy : public Flower {
public:
	/**
	 * @brief Constructs a Pansy plant with default characteristics.
	 * 
	 * Initializes the Pansy with a maximum height of 25cm, medium moisture watering
	 * strategy, dead heading pruning strategy, and sets it as available for sale in Spring.
	 */
	Pansy() : Flower(25, new MediumMoisture(), new DeadPruning(), "Pansy", "Spring") {}
	
	/**
	 * @brief Gets the image path for the Pansy plant.
	 * @return string The path to the Pansy image asset.
	 */
	string getImagePath() override {
		return "assets/pansy.jpg";
	}
};

#endif
