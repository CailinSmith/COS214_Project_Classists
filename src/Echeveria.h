#ifndef ECHEVERIA_H
#define ECHEVERIA_H

#include "Succulent.h"
#include "DryPlant.h"
#include "Thinning.h"

/**
 * @class Echeveria
 * @author Cailin Smith
 * @brief Represents an Echeveria succulent plant.
 * Design Pattern: Abstract Factory
 * Participant: ConcreteProduct
 * 
 * This class represents an Echeveria plant, which is a succulent with dry watering
 * requirements and thinning pruning strategy. The plant has a maximum height of 30cm
 * and is available for sale during the Summer season.
 * 
 * @see Succulent
 * @see DryPlant
 * @see Thinning
 */
class Echeveria : public Succulent {

public:
	/**
	 * @brief Constructs an Echeveria plant with default characteristics.
	 * 
	 * Initializes the Echeveria with a maximum height of 30cm, dry watering strategy,
	 * thinning pruning strategy, and sets it as available for sale in Summer.
	 */
	Echeveria() : Succulent(30, new DryPlant(), new Thinning(), "Echeveria", "Summer") {}
	
	/**
	 * @brief Gets the image path for the Echeveria plant.
	 * @return string The path to the Echeveria image asset.
	 */
	string getImagePath() override {
		return "assets/echeveria.jpg";
	}
};

#endif
