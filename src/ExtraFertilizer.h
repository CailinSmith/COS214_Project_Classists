#ifndef EXTRAFERTILIZER_H
#define EXTRAFERTILIZER_H

#include "Decorator.h"

/**
 * @class ExtraFertilizer
 * @author Jordan Naidoo
 * @brief 
 * Design Pattern: Decorator
 * Participant: Concrete Decorator
 * 
 * Adds extra fertilizer to plant products that customers purchase which modifies its behaviour.
 * This impacts the price as well as the appearance of the plants in the nursery (via the getName and summary methods).
 * Extra fertilizer enhances plant health and growth potential, providing added value to customers.
 * 
 * @see Decorator
 */
class ExtraFertilizer : public Decorator
{
public:
    /**
     * @brief Constructs an ExtraFertilizer decorator wrapping the specified product.
     * @param plant Pointer to the Product (plant or other decorator) to be decorated with extra fertilizer.
     */
    ExtraFertilizer(Product* plant);
    
    /**
     * @brief Destructor for the ExtraFertilizer decorator.
     */
    ~ExtraFertilizer();
    
    /**
     * @brief Calculates the total cost of the decorated product including the extra fertilizer surcharge.
     * @param currentSeason The current season which affects plant pricing.
     * @return float The total cost of the plant product with the extra fertilizer enhancement applied.
     */
    float calculateCost(string currentSeason);
    
    /**
     * @brief Generates a detailed description of the decorated product including extra fertilizer details.
     * @return string A formatted string describing the complete decorated product with extra fertilizer details.
     */
    string summary();
    
    /**
     * @brief Retrieves the name of the decorated product with extra fertilizer designation.
     * @return string The name of the product including extra fertilizer designation.
     */
    string getName();
};

#endif // EXTRAFERTILIZER_H
