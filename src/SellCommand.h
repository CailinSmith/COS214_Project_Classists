/**
 * @file SellCommand.h
 * @author Cailin Smith
 * @date 2025-10-09
 */

#ifndef SELLCOMMAND_H
#define SELLCOMMAND_H

#include "StaffCommand.h"
#include "Plant.h"

class SellCommand : StaffCommand {

public:
	SellCommand(Plant* plant, InventoryManager* im);

	void execute();
};

#endif
