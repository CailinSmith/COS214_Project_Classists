#ifndef DEADPRUNING_H
#define DEADPRUNING_H

#include "PruningStrategy.h"
#include "Plant.h"
#include <string>
#include <iostream>
using namespace std;

/**
 * @class DeadPruning
 * @author Cailin Smith
 * @brief Implements dead heading pruning strategy for plants.
 * Design Pattern: Strategy
 * Participant: ConcreteStrategy
 * 
 * This class implements a dead heading pruning strategy where dead or spent flowers
 * and foliage are removed to encourage new growth and maintain plant health. This
 * strategy is commonly used for flowering plants to promote continuous blooming.
 * 
 * @see PruningStrategy
 * @see Plant
 */
class DeadPruning : public PruningStrategy {
public:
	/**
	 * @brief Applies dead heading pruning to the specified plant.
	 * @param plant Pointer to the Plant object to be pruned using dead heading technique.
	 */
	void prune(Plant* plant);
	
	/**
	 * @brief Returns a string description of this pruning strategy.
	 * @return string A text description of the dead heading pruning method.
	 */
	string print();
};

#endif
