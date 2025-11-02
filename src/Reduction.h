#ifndef REDUCTION_H
#define REDUCTION_H

#include "PruningStrategy.h"
#include <string>
using namespace std;

/**
 * @class Reduction
 * @author Cailin Smith
 * @brief Concrete pruning strategy for reduction pruning.
 * Design Pattern: Strategy
 * Participant: ConcreteStrategy
 * 
 * This class implements a reduction pruning strategy, which involves
 * cutting back plant growth to control size and shape. This technique
 * is used for plants that need significant trimming to maintain health
 * and appearance.
 * 
 * @see PruningStrategy
 * @see Plant
 */
class Reduction : public PruningStrategy {
public:
	/**
	 * @brief Performs reduction pruning on the given plant.
	 * @param plant Pointer to the plant to be pruned.
	 */
	void prune(Plant* plant);
	
	/**
	 * @brief Gets a string representation of this strategy.
	 * @return string Description of the reduction pruning strategy.
	 */
	string print();
};

#endif
