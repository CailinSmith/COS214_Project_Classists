#ifndef REMOVECOMMAND_H
#define REMOVECOMMAND_H

#include "StaffCommand.h"
#include "Plant.h"

/**
 * @class RemoveCommand
 * @author Cailin Smith
 * @brief Command for removing a plant from inventory.
 * Design Pattern: Command
 * Participant: ConcreteCommand
 * 
 * This class encapsulates a request to remove a plant from the nursery
 * inventory. It allows staff members to remove plants that are damaged,
 * dead, or no longer needed.
 * 
 * @see StaffCommand
 * @see Plant
 * @see InventoryManager
 */
class RemoveCommand : public StaffCommand {

public:
	/**
	 * @brief Constructs a RemoveCommand.
	 * @param plant Pointer to the plant to remove.
	 * @param im Pointer to the inventory manager.
	 */
	RemoveCommand(Plant* plant, InventoryManager* im);

	/**
	 * @brief Executes the remove command.
	 * 
	 * Removes the specified plant from the inventory.
	 */
	void execute();
};

#endif
