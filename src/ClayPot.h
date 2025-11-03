#ifndef CLAYPOT_H
#define CLAYPOT_H

#include "Decorator.h"

/**
 * @class ClayPot
 * @author Jordan Naidoo
 * @brief 
 * Design Pattern: Decorator
 * Participant: Concrete Decorator
 * 
 * Adds a clay pot object to plant products that customers purchase which modifies its behaviour.
 * This impacts the price as well as the appearance of the plants in the nursery (via the getName and summary methods).
 * 
 * @see Decorator
 */
class ClayPot : public Decorator
{
public:
    /**
     * @brief Constructs a ClayPot decorator wrapping the specified product.
     * @param plant Pointer to the Product (plant or other decorator) to be decorated with a clay pot.
     */
    ClayPot(Product* plant);
    
    /**
     * @brief Destructor for the ClayPot decorator.
     */
    ~ClayPot();
    
    /**
     * @brief Calculates the total cost of the decorated product including the clay pot surcharge.
     * @param currentSeason The current season which affects plant pricing.
     * @return float The total cost of the plant product with the clay pot enhancement applied.
     */
    float calculateCost(string currentSeason);
    
    /**
     * @brief Generates a detailed description of the decorated product including clay pot details.
     * @return string A formatted string describing the complete decorated product with clay pot details.
     */
    string summary();
    
    /**
     * @brief Retrieves the name of the decorated product with clay pot designation.
     * @return string The name of the product including clay pot designation.
     */
    string getName();
};

#endif // CLAYPOT_H