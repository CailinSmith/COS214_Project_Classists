#ifndef JADEPLANT_H
#define JADEPLANT_H

#include "Succulent.h"
#include "DryPlant.h"
#include "Thinning.h"

/**
 * @class JadePlant
 * @author Cailin Smith
 * @brief Represents a Jade Plant succulent.
 * Design Pattern: Abstract Factory
 * Participant: ConcreteProduct
 * 
 * This class represents a Jade Plant, which is a succulent with dry watering
 * requirements and thinning pruning strategy. The plant has a maximum height
 * of 120cm and is available for sale during the Spring season.
 * 
 * @see Succulent
 * @see DryPlant
 * @see Thinning
 */
class JadePlant : public Succulent {
public:
	/**
	 * @brief Constructs a JadePlant with default characteristics.
	 * 
	 * Initializes the Jade Plant with a maximum height of 120cm, dry watering strategy,
	 * thinning pruning strategy, and sets it as available for sale in Spring.
	 */
	JadePlant() : Succulent(120, new DryPlant(), new Thinning(), "JadePlant", "Spring") {}
	
	/**
	 * @brief Gets the image path for the Jade Plant.
	 * @return string The path to the Jade Plant image asset.
	 */
	string getImagePath() override {
		return "assets/jadeplant.jpg";
	}
};

#endif
