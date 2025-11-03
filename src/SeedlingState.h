#ifndef SEEDLINGSTATE_H
#define SEEDLINGSTATE_H

#include "PlantState.h"
#include "Plant.h"
#include "GrowingState.h"

#include <string>

using namespace std;

/**
 * @class SeedlingState
 * @author Edwin Kusel
 * 
 * @brief
 * Design pattern: State
 * Participant: ConcreteState
 * 
 * This class is a concrete state for when a plant is a seedling.
 * 
 * @see PlantState
 */
class SeedlingState : public PlantState {
public:
	/**
	 * @brief Changes the state of the plant.
	 * @param plant The plant to change the state of.
	 */
	virtual void change(Plant* plant) override;

	/**
	 * @brief Returns the name of the state.
	 * @return The name of the state.
	 */
	virtual string print() override;
};

#endif