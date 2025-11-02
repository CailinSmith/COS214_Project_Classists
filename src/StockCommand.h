#ifndef STOCKCOMMAND_H
#define STOCKCOMMAND_H

#include "StaffCommand.h"

/**
 * @class StockCommand
 * @author Cailin Smith
 * @brief Command for stocking/restocking the nursery.
 * Design Pattern: Command
 * Participant: ConcreteCommand
 * 
 * This class encapsulates a stocking request as a command object.
 * It allows staff to restock the nursery with new plants or replenish
 * existing inventory.
 * 
 * @see StaffCommand
 */
class StockCommand : public StaffCommand {

public:
	/**
	 * @brief Constructs a StockCommand.
	 */
	StockCommand();
	
	/**
	 * @brief Executes the stock command.
	 * 
	 * Performs the stocking operation on the nursery.
	 */
	void execute();
};

#endif
