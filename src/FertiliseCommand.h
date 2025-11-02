#ifndef FERTILISECOMMAND_H
#define FERTILISECOMMAND_H

#include "StaffCommand.h"

/**
 * @class FertiliseCommand
 * @author Cailin Smith
 * @brief Command for fertilising a plant.
 * Design Pattern: Command
 * Participant: ConcreteCommand
 * 
 * This class encapsulates the action of fertilising a plant, allowing staff to
 * apply fertiliser to promote plant growth and health. The command can be executed
 * as part of the nursery's plant care routine.
 * 
 * @see StaffCommand
 * @see Plant
 */
class FertiliseCommand : public StaffCommand {
	
public:
	/**
	 * @brief Constructs a FertiliseCommand for a specific plant.
	 * @param plant Pointer to the Plant to be fertilised.
	 */
	FertiliseCommand(Plant* plant);
	
	/**
	 * @brief Executes the fertilise command.
	 * 
	 * Applies fertiliser to the plant to enhance its growth and development.
	 */
	void execute();
};

#endif
