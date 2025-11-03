#ifndef AUTUMN_H
#define AUTUMN_H

#include "SeasonState.h"
#include "Nursery.h"
#include "Winter.h"
#include "WinterFactory.h"

#include <string>
using namespace std;

/**
 * @class Autumn
 * @author Edwin Kusel
 * 
 * @brief
 * Design pattern: State
 * Participant: ConcreteState
 * 
 * This class is a concrete state for the Autumn season.
 * 
 * @see SeasonState
 */
class Autumn : public SeasonState {
public:
	/**
	 * @brief Changes the season to the next season.
	 * @param nursery The nursery to change the season of.
	 */
	virtual void change(Nursery* nursery) override;

	/**
	 * @brief Returns the name of the season.
	 * @return The name of the season as a string.
	 */
	virtual string print() override;
};

#endif