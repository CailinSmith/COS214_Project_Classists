#ifndef ROSEMARY_H
#define ROSEMARY_H

#include "Herb.h"
#include "DryPlant.h"
#include "Thinning.h"

/**
 * @class Rosemary
 * @author Cailin Smith
 * @brief Represents a rosemary herb plant.
 * Design Pattern: Abstract Factory
 * Participant: ConcreteProduct
 * 
 * This class represents rosemary, a fragrant culinary herb with dry plant
 * watering requirements and thinning pruning needs. Rosemary is drought-
 * tolerant and requires minimal watering. It benefits from regular thinning
 * to maintain bushy growth. Best sold in spring.
 * 
 * @see Herb
 * @see DryPlant
 * @see Thinning
 */
class Rosemary : public Herb {
public:
	/**
	 * @brief Constructs a Rosemary plant.
	 * 
	 * Initializes the rosemary with a maximum height of 150cm, dry plant watering strategy,
	 * thinning pruning strategy, and spring as the best selling season.
	 */
	Rosemary() : Herb(150, new DryPlant(), new Thinning(), "Rosemary", "Spring") {}
	
	/**
	 * @brief Gets the image path for the rosemary plant.
	 * @return string Path to the rosemary image.
	 */
	string getImagePath() override {
		return "assets/rosemary.jpg";
	}
};

#endif
