#ifndef SUNFLOWER_H
#define SUNFLOWER_H

#include "Flower.h"
#include "MediumMoisture.h"
#include "NoPrune.h"

/**
 * @class Sunflower
 * @author Cailin Smith
 * @brief Represents a sunflower plant.
 * Design Pattern: Abstract Factory
 * Participant: ConcreteProduct
 * 
 * This class represents a sunflower, a tall flowering plant with medium
 * moisture requirements and no pruning needs. Sunflowers are iconic summer
 * flowers that can grow very tall and require consistent watering but minimal
 * maintenance. They are best sold in summer.
 * 
 * @see Flower
 * @see MediumMoisture
 * @see NoPrune
 */
class Sunflower : public Flower {

public:
	/**
	 * @brief Constructs a Sunflower plant.
	 * 
	 * Initializes the sunflower with a maximum height of 400cm, medium moisture watering
	 * strategy, no pruning strategy, and summer as the best selling season.
	 */
	Sunflower() : Flower(400, new MediumMoisture(), new NoPrune(), "Sunflower", "Summer") {}
	
	/**
	 * @brief Gets the image path for the sunflower plant.
	 * @return string Path to the sunflower image.
	 */
	string getImagePath() override {
		return "assets/sunflower.jpg";
	}
};

#endif
