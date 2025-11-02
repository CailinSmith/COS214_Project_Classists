#ifndef CHRISTMASCACTUS_H
#define CHRISTMASCACTUS_H

#include "Succulent.h"
#include "MediumMoisture.h"
#include "Thinning.h"

/**
 * @class ChristmasCactus
 * @author Cailin Smith
 * @brief Represents a Christmas Cactus succulent plant.
 * Design Pattern: Abstract Factory
 * Participant: ConcreteProduct
 * 
 * This class represents a Christmas Cactus plant, which is a succulent with medium moisture
 * watering requirements and thinning pruning strategy. The plant has a maximum height of
 * 60cm and is available for sale during the Autumn season.
 * 
 * @see Succulent
 * @see MediumMoisture
 * @see Thinning
 */
class ChristmasCactus : public Succulent {

public:
	/**
	 * @brief Constructs a ChristmasCactus plant with default characteristics.
	 * 
	 * Initializes the Christmas Cactus with a maximum height of 60cm, medium moisture
	 * watering strategy, thinning pruning strategy, and sets it as available for sale in Autumn.
	 */
	ChristmasCactus() : Succulent(60, new MediumMoisture(), new Thinning(), "Christmas Cactus", "Autumn"){}
	
	/**
	 * @brief Gets the image path for the Christmas Cactus plant.
	 * @return string The path to the Christmas Cactus image asset.
	 */
	string getImagePath() override {
		return "assets/christmascactus.jpg";
	}
};

#endif
