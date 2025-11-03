#ifndef TOMATO_H
#define TOMATO_H

#include "Fruit.h"
#include "MediumMoisture.h"
#include "Thinning.h"

/**
 * @class Tomato
 * @author Cailin Smith
 * @brief Represents a tomato fruit plant.
 * Design Pattern: Abstract Factory
 * Participant: ConcreteProduct
 * 
 * This class represents a tomato plant with medium moisture requirements
 * and thinning pruning needs. Tomatoes are popular fruit-bearing plants
 * that require regular watering and pruning to produce quality fruit.
 * They are best sold in summer.
 * 
 * @see Fruit
 * @see MediumMoisture
 * @see Thinning
 */
class Tomato : public Fruit {

public:
	/**
	 * @brief Constructs a Tomato plant.
	 * 
	 * Initializes the tomato with a maximum height of 150cm, medium moisture watering
	 * strategy, thinning pruning strategy, and summer as the best selling season.
	 */
	Tomato() : Fruit(150, new MediumMoisture(), new Thinning(), "Tomato", "Summer") {}
	
	/**
	 * @brief Gets the image path for the tomato plant.
	 * @return string Path to the tomato image.
	 */
	string getImagePath() override {
		return "assets/tomato.jpg";
	}
};

#endif
