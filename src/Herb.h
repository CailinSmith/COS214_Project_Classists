#ifndef HERB_H
#define HERB_H

#include "Plant.h"

/**
 * @class Herb
 * @author Cailin Smith
 * @brief Represents an herb plant type in the nursery system.
 * Design Pattern: Abstract Factory
 * Participant: AbstractProduct
 * 
 * This class represents culinary and aromatic herb plants that are typically grown
 * for their leaves, which are used in cooking, medicine, or fragrance. Herbs generally
 * have specific care requirements and pricing structures.
 * 
 * @see Plant
 */
class Herb : public Plant {
public:
	/**
	 * @brief Constructs an Herb plant with specified characteristics.
	 * @param maxHeight The maximum height the herb can reach in cm.
	 * @param wateringStrat Pointer to the watering strategy for this plant type.
	 * @param pruningStrat Pointer to the pruning strategy for this plant type.
	 * @param name The specific name/variety of the herb.
	 * @param sellSeason The season when this plant is available for sale.
	 */
	Herb(int maxHeight, WateringStrategy* wateringStrat, PruningStrategy* pruningStrat, string name, string sellSeason) : 
	Plant("Herb", maxHeight, wateringStrat, pruningStrat, name, sellSeason) {}

	/**
	 * @brief Virtual destructor for the Herb class.
	 */
	virtual ~Herb() {}
	
	/**
	 * @brief Calculates the base cost of the herb plant.
	 * @return float The base price of the herb before any adjustments.
	 */
	virtual float baseCost() override;
	
};

#endif
