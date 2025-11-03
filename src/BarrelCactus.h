#ifndef BARRELCACTUS_H
#define BARRELCACTUS_H

#include "Succulent.h"
#include "DryPlant.h"
#include "NoPrune.h"

/**
 * @class BarrelCactus
 * @author Cailin Smith
 * @brief Represents a Barrel Cactus succulent plant.
 * Design Pattern: Abstract Factory
 * Participant: ConcreteProduct
 * 
 * This class represents a Barrel Cactus plant, which is a succulent with dry watering
 * requirements and no pruning strategy. The plant has a maximum height of 120cm
 * and is available for sale during the Spring season.
 * 
 * @see Succulent
 * @see DryPlant
 * @see NoPrune
 */
class BarrelCactus : public Succulent {

public:
	/**
	 * @brief Constructs a BarrelCactus plant with default characteristics.
	 * 
	 * Initializes the Barrel Cactus with a maximum height of 120cm, dry watering strategy,
	 * no pruning strategy, and sets it as available for sale in Spring.
	 */
	BarrelCactus() : Succulent(120, new DryPlant(), new NoPrune(), "Barrel Cactus", "Spring") {}
	
	/**
	 * @brief Gets the image path for the Barrel Cactus plant.
	 * @return string The path to the Barrel Cactus image asset.
	 */
	string getImagePath() override {
		return "assets/barrelcactus.jpg";
	}
};

#endif
