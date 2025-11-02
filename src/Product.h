#ifndef PRODUCT_H
#define PRODUCT_H
#include <string>
using namespace std;

// Forward declaration
class Plant;

/**
 * @class Product
 * @author Jordan Naidoo
 * @brief 
 * Design Pattern: Decorator
 * Participant: Component 
 * 
 * Defines the common interface for both Plant objects and Decorator objects in the nursery system.
 * This abstract base class allows plants to be decorated with various items such as pots, wrapping and fertilizer
 * while maintaining a uniform interface for cost calculation, naming, and information retrieval.
 * 
 * @see Plant
 * @see Decorator
 */
class Product {
public:
    /**
     * @brief Virtual destructor for proper cleanup of derived classes.
     */
    virtual ~Product() {}
    
    /**
     * @brief Calculates the cost of the product based on the current season.
     * @param currentSeason The current season affecting product pricing.
     * @return float The calculated cost of the product.
     */
    virtual float calculateCost(string currentSeason){
        (void)currentSeason; // Temporary solution to problem of unused parameter warning
        return 0.0;
    };
    
    /**
     * @brief Generates a detailed summary of the product.
     * @return string A formatted description of the product.
     */
    virtual string summary(){
        return "";
    };
    
    /**
     * @brief Retrieves the name of the product.
     * @return string The product name.
     */
    virtual string getName(){
        return "DefaultName";
    };
    
    /**
     * @brief Retrieves additional information about the product.
     * @return string Additional product information.
     */
    virtual string getInfo(){
        return "DefaultInfo";
    };
    
    /**
     * @brief Gets the cost of the product without season consideration.
     * @return float The base cost of the product.
     */
    virtual float getCost(){
        return calculateCost("");
    };
    
    /**
     * @brief Retrieves the base plant object if this product wraps a plant.
     * @return Plant* Pointer to the base plant, or nullptr if not applicable.
     */
    virtual Plant* getBasePlant(){
        return nullptr;
    }
};

#endif