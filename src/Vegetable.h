#ifndef VEGETABLE_H
#define VEGETABLE_H

#include "Plant.h"

/**
 * @class Vegetable
 * @author Cailin Smith
 * @author Jordan Naidoo
 * @brief Represents a vegetable plant category.
 * Design Pattern: Abstract Factory, Template Method
 * Participant: AbstractProduct (Abstract Factory), Concrete Class (Template Method)
 * 
 * This class serves as the base class for all vegetable plants in the nursery.
 * Vegetables are plants cultivated for their edible parts and typically have
 * specific growing seasons. This class provides specific cost calculations
 * including base cost and seasonal pricing adjustments for vegetable plants.
 * 
 * @see Plant
 * @see Cucumber
 * @see Kale
 * @see Lettuce
 * @see Pumpkin
 */
class Vegetable : public Plant {
public:
	/**
	 * @brief Constructs a Vegetable plant.
	 * @param maxHeight Maximum height the vegetable can reach.
	 * @param wateringStrat Pointer to the watering strategy.
	 * @param pruningStrat Pointer to the pruning strategy.
	 * @param name Name of the specific vegetable variety.
	 * @param sellSeason Optimal season for selling this vegetable.
	 */
	Vegetable(int maxHeight, WateringStrategy* wateringStrat, PruningStrategy* pruningStrat, string name, string sellSeason) : 
	Plant("Vegetable", maxHeight, wateringStrat, pruningStrat, name, sellSeason) {}

	/**
	 * @brief Calculates the base cost for vegetable plants (primitive operation for Template Method).
	 * @return float Base cost of the vegetable.
	 */
	virtual float baseCost() override;
	
	/**
	 * @brief Calculates the seasonal cost adjustment for vegetables (primitive operation for Template Method).
	 * @param curSeason The current season.
	 * @return float Seasonal cost multiplier or adjustment.
	 */
	virtual float seasonCost(string curSeason) override;
};

#endif
