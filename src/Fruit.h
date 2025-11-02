#ifndef FRUIT_H
#define FRUIT_H

#include "Plant.h"

/**
 * @class Fruit
 * @author Cailin Smith
 * @brief Represents a fruit-bearing plant type in the nursery system.
 * Design Pattern: Abstract Factory
 * Participant: AbstractProduct
 * 
 * This class represents fruit-producing plants such as trees and vines that bear
 * edible fruits. Fruit plants typically require specific care and have longer growth
 * periods. This class provides the base cost calculation and seasonal pricing
 * adjustments specific to fruit-bearing plants.
 * 
 * @see Plant
 */
class Fruit : public Plant {

public:
	/**
	 * @brief Constructs a Fruit plant with specified characteristics.
	 * @param maxHeight The maximum height the fruit plant can reach in cm.
	 * @param wateringStrat Pointer to the watering strategy for this plant type.
	 * @param pruningStrat Pointer to the pruning strategy for this plant type.
	 * @param name The specific name/variety of the fruit plant.
	 * @param sellSeason The season when this plant is available for sale.
	 */
	Fruit(int maxHeight, WateringStrategy* wateringStrat, PruningStrategy* pruningStrat, string name, string sellSeason) : 
	Plant("Fruit", maxHeight, wateringStrat, pruningStrat, name, sellSeason) {}

	/**
	 * @brief Virtual destructor for the Fruit class.
	 */
	virtual ~Fruit() {}
	
	/**
	 * @brief Calculates the base cost of the fruit plant.
	 * @return float The base price of the fruit plant before seasonal adjustments.
	 */
	virtual float baseCost() override;
	
	/**
	 * @brief Calculates seasonal cost adjustments for the fruit plant.
	 * @param curSeason The current season affecting the pricing.
	 * @return float The seasonally adjusted price of the fruit plant.
	 */
	virtual float seasonCost(string curSeason) override;
};

#endif
