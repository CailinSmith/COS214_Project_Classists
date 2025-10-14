#ifndef MAKESELLABLECOMMAND_H
#define MAKESELLABLECOMMAND_H

#include "StaffCommand.h"
#include "Plant.h"

class MakeSellableCommand : public StaffCommand {

public:
	MakeSellableCommand(Plant* plant, InventoryManager* im);

	void execute();
};

#endif
