#ifndef WATERINGSTRATEGY_H
#define WATERINGSTRATEGY_H

#include <string>
using namespace std;

class Plant;

/**
 * @class WateringStrategy
 * @author Cailin Smith
 * @brief Abstract strategy for watering plants.
 * Design Pattern: Strategy
 * Participant: Strategy
 * 
 * This abstract class defines the interface for different watering strategies.
 * Concrete implementations (HighMoisture, MediumMoisture, DryPlant) provide
 * specific watering techniques for different plant types. The strategy pattern
 * allows watering behavior to be changed at runtime.
 * 
 * @see Plant
 * @see HighMoisture
 * @see MediumMoisture
 * @see DryPlant
 */
class WateringStrategy {

public:
	/**
	 * @brief Virtual destructor for the WateringStrategy.
	 */
	virtual ~WateringStrategy() {}
	
	/**
	 * @brief Waters the given plant.
	 * @param plant Pointer to the plant to be watered.
	 */
	virtual void water(Plant* plant) = 0;

	/**
	 * @brief Gets a string representation of the watering strategy.
	 * @return string Description of the watering strategy.
	 */
	virtual string print() = 0;
};

#endif
