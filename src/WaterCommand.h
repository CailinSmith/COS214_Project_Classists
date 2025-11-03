#ifndef WATERCOMMAND_H
#define WATERCOMMAND_H

#include "StaffCommand.h"
#include "Plant.h"

/**
 * @class WaterCommand
 * @author Cailin Smith
 * @brief Command for watering a plant.
 * Design Pattern: Command
 * Participant: ConcreteCommand
 * 
 * This class encapsulates a watering request as a command object.
 * It allows staff members to water a specific plant by delegating
 * the watering operation to the plant's watering strategy.
 * 
 * @see StaffCommand
 * @see Plant
 * @see WateringStrategy
 */
class WaterCommand : public StaffCommand {
public:
	/**
	 * @brief Constructs a WaterCommand.
	 * @param plant Pointer to the plant to be watered.
	 */
	WaterCommand(Plant* plant);
	
	/**
	 * @brief Executes the water command.
	 * 
	 * This method calls the plant's water() method, which delegates
	 * to its assigned watering strategy.
	 */
	void execute();
};

#endif
