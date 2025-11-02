#ifndef DECORATOR_H
#define DECORATOR_H

#include "Product.h"
#include "Plant.h"

/**
 * @class Decorator
 * @author Jordan Naidoo
 * @brief 
 * Design Pattern: Decorator
 * Participant: Decorator 
 * 
 * Abstract base class for all product decorators in the nursery system. Wraps a Product object
 * and provides a foundation for concrete decorators to add functionality such as pots, wrapping,
 * and fertilizer enhancements. Maintains a reference to the wrapped product and delegates operations
 * while allowing subclasses to augment behavior and pricing.
 * 
 * @see Product
 * @see CeramicPot
 * @see ClayPot
 * @see ConcretePot
 * @see KraftWrapping
 * @see ExtraFertilizer
 */
class Decorator : public Product {

public: 
	/**
	 * @brief Constructs a Decorator wrapping the specified product.
	 * @param plant Pointer to the Product (plant or another decorator) to be wrapped.
	 */
	Decorator (Product* plant);
	
	/**
	 * @brief Virtual destructor for proper cleanup.
	 */
	virtual ~Decorator();
	
	/**
	 * @brief Calculates the cost of the decorated product.
	 * @param currentSeason The current season affecting pricing.
	 * @return float The total cost including decorations.
	 */
	virtual float calculateCost(string currentSeason);
	
	/**
	 * @brief Generates a summary of the decorated product.
	 * @return string A formatted description including decoration details.
	 */
	virtual string summary();
	
	/**
	 * @brief Retrieves the name of the decorated product.
	 * @return string The product name including decoration designation.
	 */
	virtual string getName();
	
	/**
	 * @brief Removes this decorator and returns the wrapped product.
	 * @return Product* Pointer to the inner wrapped product.
	 */
	Product* removeDecorator();
	
	/**
	 * @brief Retrieves the base plant object from the decorator chain.
	 * @return Plant* Pointer to the base plant at the core of the decoration chain.
	 */
	Plant* getBasePlant() override;

private:
	Product* plant;
};

#endif
