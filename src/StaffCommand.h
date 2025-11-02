#ifndef STAFFCOMMAND_H
#define STAFFCOMMAND_H

#include "Plant.h"
#include "InventoryManager.h"
#include "Nursery.h"

/**
 * @class StaffCommand
 * @author Cailin Smith
 * @brief Abstract base class for staff commands.
 * Design Pattern: Command
 * Participant: Command 
 * 
 * This class defines the interface for all staff-related commands in the
 * nursery system. Concrete command subclasses encapsulate specific staff
 * operations (pruning, watering, checkout, etc.) as objects, allowing for
 * flexible command execution and potential undo/redo functionality.
 * 
 * @see PruneCommand
 * @see FertiliseCommand
 * @see PlantCommand
 * @see RemoveCommand
 * @see StaffCheckoutCommand
 * @see StaffCheckStockCommand
 */
class StaffCommand {
protected:
	/**
	 * @brief Pointer to the plant associated with this command.
	 */
    Plant* plant;
    
	/**
	 * @brief Pointer to the inventory manager.
	 */
    InventoryManager* inventoryManager;
    
	/**
	 * @brief Pointer to the nursery singleton.
	 */
    Nursery* nursery;

public:
	/**
	 * @brief Default constructor for StaffCommand.
	 * 
	 * Initializes all pointers to nullptr.
	 */
	StaffCommand() : plant(nullptr), inventoryManager(nullptr), nursery(nullptr) {}
	
	/**
	 * @brief Virtual destructor for the StaffCommand.
	 */
    virtual ~StaffCommand() {}
    
	/**
	 * @brief Executes the staff command.
	 * 
	 * This method is overridden by concrete command classes to perform
	 * their specific operations.
	 */
	virtual void execute();

};

#endif
