#ifndef CERAMICPOT_H
#define CERAMICPOT_H

#include "Decorator.h"

/**
 * @class CeramicPot
 * @author Jordan Naidoo
 * @brief 
 * Design Pattern: Decorator
 * Participant: Concrete Decorator
 * 
 * Adds a ceramic pot object to plant products that customers purchase which modifies its behaviour.
 * This impacts the price as well as the appearance of the plants in the nursery (via the getName and summary methods).
 * 
 * @see Decorator
 */
class CeramicPot : public Decorator
{
public:
    /**
     * @brief Constructs a CeramicPot decorator wrapping the specified product.
     * @param plant Pointer to the Product (plant or other decorator) to be decorated with a ceramic pot.
     */
    CeramicPot(Product* plant);
    
    /**
     * @brief Destructor for the CeramicPot decorator.
     */
    ~CeramicPot();
    
    /**
     * @brief Calculates the total cost of the decorated product including the ceramic pot surcharge.
     * @param currentSeason The current season which affects plant pricing.
     * @return float The total cost of the plant product with the ceramic pot enhancement applied.
     */
    float calculateCost(string currentSeason);
    
    /**
     * @brief Generates a detailed description of the decorated product including ceramic pot details.
     * @return string A formatted string describing the complete decorated product with ceramic pot details.
     */
    string summary();
    
    /**
     * @brief Retrieves the name of the decorated product with ceramic pot designation.
     * @return string The name of the product including ceramic pot designation.
     */
    string getName();
};

#endif // CERAMICPOT_H
