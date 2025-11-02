#ifndef NOPRUNE_H
#define NOPRUNE_H

#include "PruningStrategy.h"
#include <string>
#include <iostream>
using namespace std;

/**
 * @class NoPrune
 * @author Cailin Smith
 * @brief Implements no pruning strategy for plants.
 * Design Pattern: Strategy
 * Participant: ConcreteStrategy
 * 
 * This class implements a pruning strategy where no pruning is performed on the plant.
 * This is appropriate for plants that grow naturally without requiring trimming or
 * shaping, or for plants that should not be pruned to maintain their natural form.
 * 
 * @see PruningStrategy
 * @see Plant
 */
class NoPrune : public PruningStrategy {

public:
	/**
	 * @brief Applies no pruning to the specified plant.
	 * @param plant Pointer to the Plant object (no actual pruning is performed).
	 */
	void prune(Plant* plant);

	/**
	 * @brief Returns a string description of this pruning strategy.
	 * @return string A text description indicating no pruning is performed.
	 */
	string print();
};

#endif
