#ifndef SNAKEPLANT_H
#define SNAKEPLANT_H

#include "Indoor.h"
#include "DryPlant.h"
#include "NoPrune.h"

/**
 * @class SnakePlant
 * @author Cailin Smith
 * @brief Represents a snake plant indoor plant.
 * Design Pattern: Abstract Factory
 * Participant: ConcreteProduct
 * 
 * This class represents a snake plant (Sansevieria), a hardy indoor plant
 * with very low maintenance needs. It has dry plant watering requirements
 * and requires no pruning. Snake plants are extremely drought-tolerant and
 * perfect for beginners. They are best sold in winter.
 * 
 * @see Indoor
 * @see DryPlant
 * @see NoPrune
 */
class SnakePlant : public Indoor {
public:
	/**
	 * @brief Constructs a SnakePlant.
	 * 
	 * Initializes the snake plant with a maximum height of 120cm, dry plant watering strategy,
	 * no pruning strategy, and winter as the best selling season.
	 */
	SnakePlant() : Indoor(120, new DryPlant(), new NoPrune(), "SnakePlant", "Winter") {}
	
	/**
	 * @brief Gets the image path for the snake plant.
	 * @return string Path to the snake plant image.
	 */
	string getImagePath() override {
		return "assets/snakeplant.jpg";
	}
};

#endif
