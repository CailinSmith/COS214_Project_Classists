#ifndef SUCCULENT_H
#define SUCCULENT_H

#include "Plant.h"

/**
 * @class Succulent
 * @author Cailin Smith
 * @author Jordan Naidoo
 * @brief Represents a succulent plant category.
 * Design Pattern: Abstract Factory, Template Method
 * Participant: AbstractProduct (Abstract Factory), Concrete Class (Template Method)
 * 
 * This class serves as the base class for all succulent plants in the nursery.
 * Succulents are characterized by their thick, fleshy parts adapted to store
 * water, making them drought-resistant and low-maintenance. This class provides
 * specific cost calculations for succulent plants.
 * 
 * @see Plant
 * @see AloeVera
 * @see BarrelCactus
 * @see ChristmasCactus
 * @see Echeveria
 * @see JadePlant
 */
class Succulent : public Plant {

public:
	/**
	 * @brief Constructs a Succulent plant.
	 * @param maxHeight Maximum height the succulent can reach.
	 * @param wateringStrat Pointer to the watering strategy.
	 * @param pruningStrat Pointer to the pruning strategy.
	 * @param name Name of the specific succulent variety.
	 * @param sellSeason Optimal season for selling this succulent.
	 */
	Succulent(int maxHeight, WateringStrategy* wateringStrat, PruningStrategy* pruningStrat, string name, string sellSeason) : 
	Plant("Succulent", maxHeight, wateringStrat, pruningStrat, name, sellSeason) {}

	/**
	 * @brief Calculates the base cost for succulent plants (primitive operation for Template Method).
	 * @return float Base cost of the succulent.
	 */
	virtual float baseCost() override;
};

#endif
