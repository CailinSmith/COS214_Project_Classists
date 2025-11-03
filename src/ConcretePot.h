#ifndef CONCRETEPOT_H
#define CONCRETEPOT_H

#include "Decorator.h"

/**
 * @class ConcretePot
 * @author Jordan Naidoo
 * @brief 
 * Design Pattern: Decorator
 * Participant: Concrete Decorator
 * 
 * Adds a concrete pot object to plant products that customers purchase which modifies its behaviour.
 * This impacts the price as well as the appearance of the plants in the nursery (via the getName and summary methods).
 * 
 * @see Decorator
 */
class ConcretePot : public Decorator
{
public:
	/**
	 * @brief Constructs a ConcretePot decorator wrapping the specified product.
	 * @param plant Pointer to the Product (plant or other decorator) to be decorated with a concrete pot.
	 */
	ConcretePot(Product* plant);
	
	/**
	 * @brief Destructor for the ConcretePot decorator.
	 */
	~ConcretePot();
	
	/**
	 * @brief Calculates the total cost of the decorated product including the concrete pot surcharge.
	 * @param currentSeason The current season which affects plant pricing.
	 * @return float The total cost of the plant product with the concrete pot enhancement applied.
	 */
	float calculateCost(string currentSeason);
	
	/**
	 * @brief Generates a detailed description of the decorated product including concrete pot details.
	 * @return string A formatted string describing the complete decorated product with concrete pot details.
	 */
	string summary();
	
	/**
	 * @brief Retrieves the name of the decorated product with concrete pot designation.
	 * @return string The name of the product including concrete pot designation.
	 */
	string getName();
};

#endif // CONCRETEPOT_H

