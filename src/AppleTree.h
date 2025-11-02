#ifndef APPLETREE_H
#define APPLETREE_H

#include "Fruit.h"
#include "MediumMoisture.h"
#include "Thinning.h"

/**
 * @class AppleTree
 * @author Cailin Smith
 * @brief Represents an Apple Tree fruit plant.
 * Design Pattern: Abstract Factory
 * Participant: ConcreteProduct
 * 
 * This class represents an Apple Tree plant, which is a fruit-bearing plant with medium
 * moisture watering requirements and thinning pruning strategy. The plant has a maximum
 * height of 600cm and is available for sale during the Spring season.
 * 
 * @see Fruit
 * @see MediumMoisture
 * @see Thinning
 */
class AppleTree : public Fruit {
public:
	/**
	 * @brief Constructs an AppleTree plant with default characteristics.
	 * 
	 * Initializes the Apple Tree with a maximum height of 600cm, medium moisture watering
	 * strategy, thinning pruning strategy, and sets it as available for sale in Spring.
	 */
	AppleTree() : Fruit(600, new MediumMoisture(), new Thinning(), "Apple Tree", "Spring") {}
	
	/**
	 * @brief Gets the image path for the Apple Tree plant.
	 * @return string The path to the Apple Tree image asset.
	 */
	string getImagePath() override {
		return "assets/appletree.jpg";
	}
};

#endif
