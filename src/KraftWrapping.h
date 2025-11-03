#ifndef KRAFTWRAPPING_H
#define KRAFTWRAPPING_H

#include "Decorator.h"

/**
 * @class KraftWrapping
 * @author Jordan Naidoo
 * @brief 
 * Design Pattern: Decorator
 * Participant: Concrete Decorator
 * 
 * Adds kraft paper wrapping to plant products that customers purchase which modifies its behaviour.
 * This impacts the price as well as the appearance of the plants in the nursery (via the getName and summary methods).
 * Kraft wrapping provides an eco-friendly packaging option for customers.
 * 
 * @see Decorator
 */
class KraftWrapping : public Decorator
{
public:
    /**
     * @brief Constructs a KraftWrapping decorator wrapping the specified product.
     * @param plant Pointer to the Product (plant or other decorator) to be decorated with kraft wrapping.
     */
    KraftWrapping(Product* plant);
    
    /**
     * @brief Destructor for the KraftWrapping decorator.
     */
    ~KraftWrapping();
    
    /**
     * @brief Calculates the total cost of the decorated product including the kraft wrapping surcharge.
     * @param currentSeason The current season which affects plant pricing.
     * @return float The total cost of the plant product with the kraft wrapping enhancement applied.
     */
    float calculateCost(string currentSeason);
    
    /**
     * @brief Generates a detailed description of the decorated product including kraft wrapping details.
     * @return string A formatted string describing the complete decorated product with kraft wrapping details.
     */
    string summary();
    
    /**
     * @brief Retrieves the name of the decorated product with kraft wrapping designation.
     * @return string The name of the product including kraft wrapping designation.
     */
    string getName();
};

#endif // KRAFTWRAPPING_H
