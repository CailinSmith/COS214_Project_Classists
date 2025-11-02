#ifndef PRUNINGSTRATEGY_H
#define PRUNINGSTRATEGY_H

#include <string>
using namespace std;

class Plant;

/**
 * @class PruningStrategy
 * @author Cailin Smith
 * @brief Abstract strategy for pruning plants.
 * Design Pattern: Strategy
 * Participant: Strategy
 * 
 * This abstract class defines the interface for different pruning strategies.
 * Concrete implementations (DeadPruning, Thinning, NoPrune) provide specific
 * pruning techniques for different plant types. The strategy pattern allows
 * pruning behavior to be changed at runtime.
 * 
 * @see Plant
 * @see DeadPruning
 * @see Thinning
 * @see NoPrune
 */
class PruningStrategy {

public:
	/**
	 * @brief Virtual destructor for the PruningStrategy.
	 */
	virtual ~PruningStrategy() {}
	
	/**
	 * @brief Prunes the given plant.
	 * @param plant Pointer to the plant to be pruned.
	 */
	virtual void prune(Plant* plant) = 0;

	/**
	 * @brief Gets a string representation of the pruning strategy.
	 * @return string Description of the pruning strategy.
	 */
	virtual string print() = 0;
};

#endif
