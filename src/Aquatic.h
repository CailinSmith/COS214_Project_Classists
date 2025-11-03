#ifndef AQUATIC_H
#define AQUATIC_H

#include "Plant.h"

/**
 * @class Aquatic
 * @author Cailin Smith
 * @author Jordan Naidoo
 * @brief Represents an aquatic plant type in the nursery system.
 * Design Pattern: Abstract Factory, Template Method
 * Participant: AbstractProduct (Abstract Factory), Concrete Class (Template Method)
 * 
 * This class represents aquatic plants that require specific water-based growing conditions.
 * Aquatic plants are characterized by their ability to thrive in high-moisture or water
 * environments and have unique care requirements compared to terrestrial plants.
 * 
 * @see Plant
 */
class Aquatic : public Plant {

public:
	/**
	 * @brief Constructs an Aquatic plant with specified characteristics.
	 * @param maxHeight The maximum height the aquatic plant can reach in cm.
	 * @param wateringStrat Pointer to the watering strategy for this plant type.
	 * @param pruningStrat Pointer to the pruning strategy for this plant type.
	 * @param name The specific name/variety of the aquatic plant.
	 * @param sellSeason The season when this plant is typically available for sale.
	 */
	Aquatic(int maxHeight, WateringStrategy* wateringStrat, PruningStrategy* pruningStrat, string name, string sellSeason) : 
	Plant("Aquatic", maxHeight, wateringStrat, pruningStrat, name, sellSeason) {}

	/**
	 * @brief Calculates the base cost of the aquatic plant (primitive operation for Template Method).
	 * @return float The base price of the aquatic plant before any decorators or seasonal adjustments.
	 */
	virtual float baseCost() override;
};

#endif
