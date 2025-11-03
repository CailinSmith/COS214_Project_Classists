#ifndef SEEDSTATE_H
#define SEEDSTATE_H

#include "PlantState.h"
#include "Plant.h"
#include "SeedlingState.h"

#include <string>
using namespace std;

/**
 * @class SeedState
 * @author Edwin Kusel
 * 
 * @brief
 * Design pattern: State
 * Participant: ConcreteState
 * 
 * This class is a concrete state for when a plant is a seed.
 * 
 * @see PlantState
 */
class SeedState : public PlantState {
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
