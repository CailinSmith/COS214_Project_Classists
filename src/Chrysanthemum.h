#ifndef CHRYSANTHEMUM_H
#define CHRYSANTHEMUM_H

#include "Flower.h"
#include "MediumMoisture.h"
#include "DeadPruning.h"

/**
 * @class Chrysanthemum
 * @author Cailin Smith
 * @brief Represents a Chrysanthemum flower plant.
 * Design Pattern: Abstract Factory
 * Participant: ConcreteProduct
 * 
 * This class represents a Chrysanthemum plant, which is a flowering plant with medium
 * moisture watering requirements and dead heading pruning strategy. The plant has a
 * maximum height of 60cm and is available for sale during the Autumn season.
 * 
 * @see Flower
 * @see MediumMoisture
 * @see DeadPruning
 */
class Chrysanthemum : public Flower {
public:
	/**
	 * @brief Constructs a Chrysanthemum plant with default characteristics.
	 * 
	 * Initializes the Chrysanthemum with a maximum height of 60cm, medium moisture watering
	 * strategy, dead heading pruning strategy, and sets it as available for sale in Autumn.
	 */
	Chrysanthemum() : Flower(60, new MediumMoisture(), new DeadPruning(), "Chrysanthemum", "Autumn") {}
	
	/**
	 * @brief Gets the image path for the Chrysanthemum plant.
	 * @return string The path to the Chrysanthemum image asset.
	 */
	string getImagePath() override {
		return "assets/chrysanthemum.jpg";
	}
};

#endif
