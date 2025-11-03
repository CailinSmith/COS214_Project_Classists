#ifndef GINGER_H
#define GINGER_H

#include "Medicinal.h"
#include "MediumMoisture.h"
#include "Thinning.h"

/**
 * @class Ginger
 * @author Cailin Smith
 * @brief Represents a Ginger medicinal plant.
 * Design Pattern: Abstract Factory
 * Participant: ConcreteProduct
 * 
 * This class represents a Ginger plant, which is a medicinal plant with medium moisture
 * watering requirements and thinning pruning strategy. The plant has a maximum height
 * of 120cm and is available for sale during the Summer season.
 * 
 * @see Medicinal
 * @see MediumMoisture
 * @see Thinning
 */
class Ginger : public Medicinal {

public:
	/**
	 * @brief Constructs a Ginger plant with default characteristics.
	 * 
	 * Initializes the Ginger plant with a maximum height of 120cm, medium moisture
	 * watering strategy, thinning pruning strategy, and sets it as available for sale in Summer.
	 */
	Ginger() : Medicinal(120, new MediumMoisture(), new Thinning(), "Ginger", "Summer") {}
	
	/**
	 * @brief Gets the image path for the Ginger plant.
	 * @return string The path to the Ginger image asset.
	 */
	string getImagePath() override {
		return "assets/ginger.jpg";
	}
};

#endif
