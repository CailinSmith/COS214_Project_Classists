#ifndef REMOVESALECOMMAND_H
#define REMOVESALECOMMAND_H

#include "StaffCommand.h"
#include "Plant.h"

/**
 * @class RemoveSaleCommand
 * @author Cailin Smith
 * @brief Command for removing a plant from sale inventory.
 * Design Pattern: Command
 * Participant: ConcreteCommand
 * 
 * This class encapsulates a request to remove a plant from the sellable
 * inventory. It allows staff to take plants off sale that are no longer
 * suitable for purchase or need to be returned to regular inventory.
 * 
 * @see StaffCommand
 * @see Plant
 * @see InventoryManager
 */
class RemoveSaleCommand : public StaffCommand {

public:
	/**
	 * @brief Constructs a RemoveSaleCommand.
	 * @param plant Pointer to the plant to remove from sale.
	 * @param im Pointer to the inventory manager.
	 */
	RemoveSaleCommand(Plant* plant, InventoryManager* im);

	/**
	 * @brief Executes the remove sale command.
	 * 
	 * Removes the specified plant from the sellable inventory.
	 */
	void execute();
};

#endif
