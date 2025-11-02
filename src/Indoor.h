#ifndef INDOOR_H
#define INDOOR_H

#include "Plant.h"

/**
 * @class Indoor
 * @author Cailin Smith
 * @author Jordan Naidoo
 * @brief Represents an indoor plant type in the nursery system.
 * Design Pattern: Abstract Factory, Template Method
 * Participant: AbstractProduct (Abstract Factory), Concrete Class (Template Method)
 * 
 * This class represents plants that are specifically suited for growing indoors,
 * typically requiring lower light conditions and controlled environments. Indoor
 * plants are popular for home and office decoration and have specific care needs
 * adapted to interior conditions.
 * 
 * @see Plant
 */
class Indoor : public Plant {

public:
	/**
	 * @brief Constructs an Indoor plant with specified characteristics.
	 * @param maxHeight The maximum height the indoor plant can reach in cm.
	 * @param wateringStrat Pointer to the watering strategy for this plant type.
	 * @param pruningStrat Pointer to the pruning strategy for this plant type.
	 * @param name The specific name/variety of the indoor plant.
	 * @param sellSeason The season when this plant is available for sale.
	 */
	Indoor(int maxHeight, WateringStrategy* wateringStrat, PruningStrategy* pruningStrat, string name, string sellSeason) : 
	Plant("Indoor", maxHeight, wateringStrat, pruningStrat, name, sellSeason) {}

	/**
	 * @brief Calculates the base cost of the indoor plant (primitive operation for Template Method).
	 * @return float The base price of the indoor plant before any adjustments.
	 */
	virtual float baseCost() override;
};

#endif
