#ifndef CHAMOMILE_H
#define CHAMOMILE_H

#include "Medicinal.h"
#include "MediumMoisture.h"
#include "Thinning.h"

/**
 * @class Chamomile
 * @author Cailin Smith
 * @brief Represents a Chamomile medicinal plant.
 * Design Pattern: Abstract Factory
 * Participant: ConcreteProduct
 * 
 * This class represents a Chamomile plant, which is a medicinal plant with medium moisture
 * watering requirements and thinning pruning strategy. The plant has a maximum height of
 * 60cm and is available for sale during the Summer season.
 * 
 * @see Medicinal
 * @see MediumMoisture
 * @see Thinning
 */
class Chamomile : public Medicinal {

public:
	/**
	 * @brief Constructs a Chamomile plant with default characteristics.
	 * 
	 * Initializes the Chamomile plant with a maximum height of 60cm, medium moisture
	 * watering strategy, thinning pruning strategy, and sets it as available for sale in Summer.
	 */
	Chamomile() : Medicinal(60, new MediumMoisture(), new Thinning(), "Chamomile", "Summer") {}
	
	/**
	 * @brief Gets the image path for the Chamomile plant.
	 * @return string The path to the Chamomile image asset.
	 */
	string getImagePath() override {
		return "assets/chamomile.jpg";
	}
};

#endif
