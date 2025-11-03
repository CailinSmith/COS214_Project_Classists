#ifndef ALOEVERA_H
#define ALOEVERA_H

#include "Medicinal.h"
#include "DryPlant.h"
#include "Thinning.h"

/**
 * @class AloeVera
 * @author Cailin Smith
 * @brief Represents an Aloe Vera medicinal plant.
 * Design Pattern: Abstract Factory
 * Participant: ConcreteProduct
 * 
 * This class represents an Aloe Vera plant, which is a medicinal plant with dry watering
 * requirements and thinning pruning strategy. The plant has a maximum height of 60cm
 * and is available for sale during the Summer season.
 * 
 * @see Medicinal
 * @see DryPlant
 * @see Thinning
 */
class AloeVera : public Medicinal {
public:
	/**
	 * @brief Constructs an AloeVera plant with default characteristics.
	 * 
	 * Initializes the Aloe Vera plant with a maximum height of 60cm, dry watering strategy,
	 * thinning pruning strategy, and sets it as available for sale in Summer.
	 */
	AloeVera() : Medicinal(60, new DryPlant(), new Thinning(), "Aloe Vera", "Summer") {}
	
	/**
	 * @brief Gets the image path for the Aloe Vera plant.
	 * @return string The path to the Aloe Vera image asset.
	 */
	string getImagePath() override {
		return "assets/aloevera.jpg";
	}
};

#endif
