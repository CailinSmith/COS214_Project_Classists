#ifndef THINNING_H
#define THINNING_H

#include "PruningStrategy.h"
#include <string>
using namespace std;

/**
 * @class Thinning
 * @author Cailin Smith
 * @brief Concrete pruning strategy for thinning.
 * Design Pattern: Strategy
 * Participant: ConcreteStrategy
 * 
 * This class implements a thinning pruning strategy, which involves
 * selectively removing branches, stems, or foliage to improve air
 * circulation and light penetration. This technique helps promote
 * healthier growth and better plant structure.
 * 
 * @see PruningStrategy
 * @see Plant
 */
class Thinning : public PruningStrategy {

public:
	/**
	 * @brief Performs thinning pruning on the given plant.
	 * @param plant Pointer to the plant to be pruned.
	 */
	void prune(Plant* plant) ;

	/**
	 * @brief Gets a string representation of this strategy.
	 * @return string Description of the thinning pruning strategy.
	 */
	string print() ;
};

#endif
