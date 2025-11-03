#ifndef PLANTCOMMAND_H
#define PLANTCOMMAND_H

#include "StaffCommand.h"

/**
 * @class PlantCommand
 * @author Cailin Smith
 * @brief Command for planting a new plant in the nursery.
 * Design Pattern: Command
 * Participant: ConcreteCommand
 * 
 * This class encapsulates the action of adding a new plant to the nursery's inventory.
 * It handles the planting process and coordinates with the inventory manager to track
 * the newly planted specimen.
 * 
 * @see StaffCommand
 * @see Plant
 * @see InventoryManager
 */
class PlantCommand : public StaffCommand {
public:
	/**
	 * @brief Constructs a PlantCommand for adding a plant to inventory.
	 * @param p Pointer to the Plant to be added to the nursery.
	 * @param im Pointer to the InventoryManager that will track this plant.
	 */
	PlantCommand(Plant* p, InventoryManager* im);
	
	/**
	 * @brief Executes the plant command.
	 * 
	 * Adds the plant to the nursery's growing inventory.
	 */
	void execute();
};

#endif
