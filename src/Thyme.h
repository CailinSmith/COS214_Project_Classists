#ifndef THYME_H
#define THYME_H

#include "Herb.h"
#include "DryPlant.h"
#include "Thinning.h"

/**
 * @class Thyme
 * @author Cailin Smith
 * @brief Represents a thyme herb plant.
 * Design Pattern: Abstract Factory
 * Participant: ConcreteProduct
 * 
 * This class represents thyme, a small aromatic culinary herb with dry
 * plant watering requirements and thinning pruning needs. Thyme is a
 * drought-tolerant Mediterranean herb that requires minimal watering
 * and benefits from regular thinning. Best sold in summer.
 * 
 * @see Herb
 * @see DryPlant
 * @see Thinning
 */
class Thyme : public Herb {

public:
	/**
	 * @brief Constructs a Thyme plant.
	 * 
	 * Initializes the thyme with a maximum height of 30cm, dry plant watering strategy,
	 * thinning pruning strategy, and summer as the best selling season.
	 */
	Thyme() : Herb(30, new DryPlant(), new Thinning(), "Thyme", "Summer") {}
	
	/**
	 * @brief Gets the image path for the thyme plant.
	 * @return string Path to the thyme image.
	 */
	string getImagePath() override {
		return "assets/thyme.jpg";
	}
};

#endif
