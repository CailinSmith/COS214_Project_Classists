/**
 * @file RemoveCommand.h
 * @author Cailin Smith
 * @date 2025-10-09
 */

#ifndef REMOVECOMMAND_H
#define REMOVECOMMAND_H

#include "StaffCommand.h"
#include "Plant.h"

class RemoveCommand : public StaffCommand {

public:
	RemoveCommand(Plant* plant, InventoryManager* im);

	void execute();
};

#endif
