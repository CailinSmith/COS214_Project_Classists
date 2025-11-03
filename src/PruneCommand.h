#ifndef PRUNECOMMAND_H
#define PRUNECOMMAND_H

#include "StaffCommand.h"
#include "Plant.h"

/**
 * @class PruneCommand
 * @author Cailin Smith
 * @brief Command for pruning a plant.
 * Design Pattern: Command
 * Participant: ConcreteCommand
 * 
 * This class encapsulates a pruning request as a command object.
 * It allows staff members to prune a specific plant by delegating
 * the pruning operation to the plant's pruning strategy.
 * 
 * @see StaffCommand
 * @see Plant
 * @see PruningStrategy
 */
class PruneCommand : public StaffCommand {

public:
	/**
	 * @brief Constructs a PruneCommand.
	 * @param plant Pointer to the plant to be pruned.
	 */
	PruneCommand(Plant* plant);

	/**
	 * @brief Executes the prune command.
	 * 
	 * This method calls the plant's prune() method, which delegates
	 * to its assigned pruning strategy.
	 */
	void execute();
};

#endif
