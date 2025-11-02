#ifndef LAVENDER_H
#define LAVENDER_H

#include "Herb.h"
#include "DryPlant.h"
#include "Reduction.h"

/**
 * @class Lavender
 * @author Cailin Smith
 * @brief Represents a Lavender herb plant.
 * Design Pattern: Abstract Factory
 * Participant: ConcreteProduct
 * 
 * This class represents a Lavender plant, which is an herb with dry watering
 * requirements and reduction pruning strategy. The plant has a maximum height
 * of 90cm and is available for sale during the Summer season.
 * 
 * @see Herb
 * @see DryPlant
 * @see Reduction
 */
class Lavender : public Herb {
public:
	/**
	 * @brief Constructs a Lavender plant with default characteristics.
	 * 
	 * Initializes the Lavender plant with a maximum height of 90cm, dry watering strategy,
	 * reduction pruning strategy, and sets it as available for sale in Summer.
	 */
	Lavender() : Herb(90, new DryPlant(), new Reduction(), "Lavender", "Summer") {}
	
	/**
	 * @brief Gets the image path for the Lavender plant.
	 * @return string The path to the Lavender image asset.
	 */
	string getImagePath() override {
		return "assets/lavender.jpg";
	}
};

#endif
