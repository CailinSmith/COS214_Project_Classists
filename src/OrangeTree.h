#ifndef ORANGETREE_H
#define ORANGETREE_H

#include "Fruit.h"
#include "MediumMoisture.h"
#include "Thinning.h"

/**
 * @class OrangeTree
 * @author Cailin Smith
 * @brief Represents an Orange Tree fruit plant.
 * Design Pattern: Abstract Factory
 * Participant: ConcreteProduct
 * 
 * This class represents an Orange Tree plant, which is a fruit-bearing plant with medium
 * moisture watering requirements and thinning pruning strategy. The plant has a maximum
 * height of 600cm and is available for sale during the Winter season.
 * 
 * @see Fruit
 * @see MediumMoisture
 * @see Thinning
 */
class OrangeTree : public Fruit {
public:
	/**
	 * @brief Constructs an OrangeTree plant with default characteristics.
	 * 
	 * Initializes the Orange Tree with a maximum height of 600cm, medium moisture watering
	 * strategy, thinning pruning strategy, and sets it as available for sale in Winter.
	 */
	OrangeTree() : Fruit(600, new MediumMoisture(), new Thinning(), "Orange Tree", "Winter") {}
	
	/**
	 * @brief Gets the image path for the Orange Tree plant.
	 * @return string The path to the Orange Tree image asset.
	 */
	string getImagePath() override {
		return "assets/orangetree.jpg";
	}
};

#endif
