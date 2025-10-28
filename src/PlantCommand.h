/**
 * @file PlantCommand.h
 * @author Cailin Smith
 * @date 2025-10-09
 */

#ifndef PLANTCOMMAND_H
#define PLANTCOMMAND_H

#include "StaffCommand.h"

class PlantCommand : public StaffCommand {
public:
	PlantCommand(Plant* p, InventoryManager* im);
	void execute();
};

#endif
