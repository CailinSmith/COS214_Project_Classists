#ifndef CUCUMBER_H
#define CUCUMBER_H

#include "Vegetable.h"
#include "HighMoisture.h"
#include "Thinning.h"

/**
 * @class Cucumber
 * @author Cailin Smith
 * @brief Represents a Cucumber vegetable plant.
 * Design Pattern: Abstract Factory
 * Participant: ConcreteProduct
 * 
 * This class represents a Cucumber plant, which is a vegetable with high moisture watering
 * requirements and thinning pruning strategy. The plant has a maximum height of 300cm
 * and is available for sale during the Summer season.
 * 
 * @see Vegetable
 * @see HighMoisture
 * @see Thinning
 */
class Cucumber : public Vegetable {
public:
	/**
	 * @brief Constructs a Cucumber plant with default characteristics.
	 * 
	 * Initializes the Cucumber with a maximum height of 300cm, high moisture watering
	 * strategy, thinning pruning strategy, and sets it as available for sale in Summer.
	 */
	Cucumber() : Vegetable(300, new HighMoisture(), new Thinning(), "Cucumber", "Summer") {}
	
	/**
	 * @brief Gets the image path for the Cucumber plant.
	 * @return string The path to the Cucumber image asset.
	 */
	string getImagePath() override {
		return "assets/cucumber.jpg";
	}
};

#endif
