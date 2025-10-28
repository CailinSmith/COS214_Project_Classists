/**
 * @file RemoveSaleCommand.h
 * @author Cailin Smith
 * @date 2025-10-09
 */

#ifndef REMOVESALECOMMAND_H
#define REMOVESALECOMMAND_H

#include "StaffCommand.h"
#include "Plant.h"

class RemoveSaleCommand : public StaffCommand {

public:
	RemoveSaleCommand(Plant* plant, InventoryManager* im);

	void execute();
};

#endif
