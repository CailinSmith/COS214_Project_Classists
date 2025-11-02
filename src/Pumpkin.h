#ifndef PUMPKIN_H
#define PUMPKIN_H

#include "Vegetable.h"
#include "HighMoisture.h"
#include "Thinning.h"

/**
 * @class Pumpkin
 * @author Cailin Smith
 * @brief Represents a pumpkin vegetable plant.
 * Design Pattern: Abstract Factory
 * Participant: ConcreteProduct
 * 
 * This class represents a pumpkin plant with high moisture requirements
 * and thinning pruning needs. Pumpkins are autumn vegetables that require
 * regular watering and pruning to produce quality fruits. They are best
 * sold during autumn.
 * 
 * @see Vegetable
 * @see HighMoisture
 * @see Thinning
 */
class Pumpkin : public Vegetable {
public:
	/**
	 * @brief Constructs a Pumpkin plant.
	 * 
	 * Initializes the pumpkin with a maximum height of 60cm, high moisture watering strategy,
	 * thinning pruning strategy, and autumn as the best selling season.
	 */
	Pumpkin() : Vegetable(60, new HighMoisture(), new Thinning(), "Pumpkin", "Autumn") {}
	
	/**
	 * @brief Gets the image path for the pumpkin plant.
	 * @return string Path to the pumpkin image.
	 */
	string getImagePath() override {
		return "assets/pumpkin.jpg";
	}
};

#endif
