#ifndef FLOWER_H
#define FLOWER_H

#include "Plant.h"

/**
 * @class Flower
 * @author Cailin Smith
 * @brief Represents a flowering plant type in the nursery system.
 * Design Pattern: Abstract Factory
 * Participant: AbstractProduct
 * 
 * This class represents ornamental flowering plants that are grown primarily for their
 * aesthetic blooms. Flowers have specific seasonal pricing and care requirements. This
 * class provides the base cost calculation and seasonal pricing adjustments specific
 * to flowering plants.
 * 
 * @see Plant
 */
class Flower : public Plant {
	
public:
	/**
	 * @brief Constructs a Flower plant with specified characteristics.
	 * @param maxHeight The maximum height the flower can reach in cm.
	 * @param wateringStrat Pointer to the watering strategy for this plant type.
	 * @param pruningStrat Pointer to the pruning strategy for this plant type.
	 * @param name The specific name/variety of the flower.
	 * @param sellSeason The season when this plant is typically available for sale.
	 */
	Flower(int maxHeight, WateringStrategy* wateringStrat, PruningStrategy* pruningStrat, string name, string sellSeason) : 
	Plant("Flower", maxHeight, wateringStrat, pruningStrat, name, sellSeason) {}

	/**
	 * @brief Virtual destructor for the Flower class.
	 */
	virtual ~Flower() {}
	
	/**
	 * @brief Calculates the base cost of the flower plant.
	 * @return float The base price of the flower before seasonal adjustments.
	 */
	virtual float baseCost() override;
	
	/**
	 * @brief Calculates seasonal cost adjustments for the flower.
	 * @param curSeason The current season affecting the pricing.
	 * @return float The seasonally adjusted price of the flower.
	 */
	virtual float seasonCost(string curSeason) override;
};

#endif
