#ifndef SEASONSTATE_H
#define SEASONSTATE_H

#include <string>

class Nursery; 

/**
 * @class SeasonState
 * @author Edwin Kusel
 * @brief
 * Design pattern: State
 * Participant: State
 * 
 * This class is an abstract base class for the different seasons in the nursery. 
 * It defines the interface for changing seasons.
 * 
 * @see Nursery
 */
class SeasonState {
public:
    /**
     * @brief Virtual destructor for SeasonState.
     */
	virtual ~SeasonState() {}
    /**
     * @brief Pure virtual function to change the season in the nursery.
     * @param nursery Pointer to the Nursery context.
     */
	virtual void change(Nursery* nursery) = 0;
    /**
     * @brief Pure virtual function to print the current season.
     * @return The name of the season as a string.
     */
	virtual std::string print() = 0;
};

#endif