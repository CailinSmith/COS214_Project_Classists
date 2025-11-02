#ifndef WINTER_H
#define WINTER_H

#include "SeasonState.h"
#include "Nursery.h"
#include "Spring.h"
#include "SpringFactory.h"

#include <string>
using namespace std;

/**
 * @class Winter
 * @author Edwin Kusel
 * 
 * @brief
 * Design pattern: State
 * Participant: ConcreteState
 * 
 * This class is a concrete state for the Winter season.
 * 
 * @see SeasonState
 */
class Winter : public SeasonState {
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
