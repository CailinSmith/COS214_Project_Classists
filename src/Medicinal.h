#ifndef MEDICINAL_H
#define MEDICINAL_H

#include "Plant.h"

/**
 * @class Medicinal
 * @author Cailin Smith
 * @brief Represents a medicinal plant type in the nursery system.
 * Design Pattern: Abstract Factory
 * Participant: AbstractProduct
 * 
 * This class represents plants that have medicinal properties and therapeutic uses.
 * Medicinal plants are valued for their health benefits and are often used in
 * herbal remedies, teas, and natural medicine. These plants have specific care
 * requirements and pricing structures.
 * 
 * @see Plant
 */
class Medicinal : public Plant {

public:
	/**
	 * @brief Constructs a Medicinal plant with specified characteristics.
	 * @param maxHeight The maximum height the medicinal plant can reach in cm.
	 * @param wateringStrat Pointer to the watering strategy for this plant type.
	 * @param pruningStrat Pointer to the pruning strategy for this plant type.
	 * @param name The specific name/variety of the medicinal plant.
	 * @param sellSeason The season when this plant is typically available for sale.
	 */
	Medicinal(int maxHeight, WateringStrategy* wateringStrat, PruningStrategy* pruningStrat, string name, string sellSeason) : 
	Plant("Medicinal", maxHeight, wateringStrat, pruningStrat, name, sellSeason) {}

	/**
	 * @brief Calculates the base cost of the medicinal plant.
	 * @return float The base price of the medicinal plant before any adjustments.
	 */
	virtual float baseCost() override;
};

#endif
