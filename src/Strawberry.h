#ifndef STRAWBERRY_H
#define STRAWBERRY_H

#include "Fruit.h"
#include "MediumMoisture.h"
#include "Thinning.h"

/**
 * @class Strawberry
 * @author Cailin Smith
 * @brief Represents a strawberry fruit plant.
 * Design Pattern: Abstract Factory
 * Participant: ConcreteProduct
 * 
 * This class represents a strawberry plant with medium moisture requirements
 * and thinning pruning needs. Strawberries are popular fruit plants that
 * require regular watering and pruning to produce quality berries. They are
 * best sold in spring.
 * 
 * @see Fruit
 * @see MediumMoisture
 * @see Thinning
 */
class Strawberry : public Fruit {

public:
	/**
	 * @brief Constructs a Strawberry plant.
	 * 
	 * Initializes the strawberry with a maximum height of 25cm, medium moisture watering
	 * strategy, thinning pruning strategy, and spring as the best selling season.
	 */
	Strawberry() : Fruit(25, new MediumMoisture(), new Thinning(), "Strawberry", "Spring") {}
	
	/**
	 * @brief Gets the image path for the strawberry plant.
	 * @return string Path to the strawberry image.
	 */
	string getImagePath() override {
		return "assets/strawberry.jpg";
	}
};

#endif
