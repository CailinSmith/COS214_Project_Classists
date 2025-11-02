#ifndef MAKESELLABLECOMMAND_H
#define MAKESELLABLECOMMAND_H

#include "StaffCommand.h"
#include "Plant.h"

/**
 * @class MakeSellableCommand
 * @author Cailin Smith
 * @brief Command for making a plant ready for sale.
 * Design Pattern: Command
 * Participant: ConcreteCommand
 * 
 * This class encapsulates the action of preparing a plant for sale by transitioning
 * it to a sellable state and adding it to the inventory manager's sales inventory.
 * 
 * @see StaffCommand
 * @see Plant
 * @see InventoryManager
 */
class MakeSellableCommand : public StaffCommand {

public:
	/**
	 * @brief Constructs a MakeSellableCommand for a specific plant.
	 * @param plant Pointer to the Plant to be made sellable.
	 * @param im Pointer to the InventoryManager that will manage the sellable plant.
	 */
	MakeSellableCommand(Plant* plant, InventoryManager* im);

	/**
	 * @brief Executes the make sellable command.
	 * 
	 * Transitions the plant to a ready-for-sale state and adds it to the sales inventory.
	 */
	void execute();
};

#endif
