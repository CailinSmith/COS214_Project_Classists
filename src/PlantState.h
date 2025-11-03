#ifndef PLANTSTATE_H
#define PLANTSTATE_H

// Forward declaration to avoid circular dependency with Plant
class Plant;

#include <string>
using namespace std;

/**
 * @class PlantState
 * @author Edwin Kusel
 * 
 * @brief
 * Design pattern: State
 * Participant: State
 * 
 * This class is an abstract base class for the different states of a plant.
 * It defines the interface for changing the state of a plant.
 * 
 * @see Plant
 */
class PlantState {
public:
	/**
	 * @brief Destructor.
	 */
	virtual ~PlantState() {}

	/**
	 * @brief Changes the state of the plant.
	 * @param plant The plant to change the state of.
	 */
	virtual void change(Plant* plant) = 0;

	/**
	 * @brief Returns the name of the state.
	 * @return The name of the state.
	 */
	virtual string print() = 0;
};

#endif
