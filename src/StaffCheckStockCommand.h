#ifndef STAFFCHECKSTOCKCOMMAND_H
#define STAFFCHECKSTOCKCOMMAND_H

#include "StaffCommand.h"
#include "Plant.h"
#include "InventoryManager.h"

/**
 * @class StaffCheckStockCommand
 * @author Cailin Smith
 * @brief Command for checking plant stock levels.
 * Design Pattern: Command
 * Participant: ConcreteCommand
 * 
 * This class encapsulates a stock check request as a command object.
 * It allows staff to query the inventory for the quantity of a specific
 * plant type currently in stock.
 * 
 * @see StaffCommand
 * @see Plant
 * @see InventoryManager
 */
class StaffCheckStockCommand : public StaffCommand {
private:
	/**
	 * @brief The stock level retrieved from inventory.
	 */
    int stock;

public:
	/**
	 * @brief Constructs a StaffCheckStockCommand.
	 * @param p Pointer to the plant to check stock for.
	 * @param im Pointer to the inventory manager.
	 */
    StaffCheckStockCommand(Plant* p, InventoryManager* im);
    
    /**
     * @brief Destructor for the StaffCheckStockCommand.
     */
    virtual ~StaffCheckStockCommand();
    
    /**
     * @brief Executes the check stock command.
     * 
     * Queries the inventory manager for the stock level of the plant.
     */
    void execute() override;
    
    /**
     * @brief Gets the stock level.
     * @return int The quantity of the plant in stock.
     */
    int getStock();
};

#endif