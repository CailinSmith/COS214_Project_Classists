#ifndef REMOVECOMMAND_H
#define REMOVECOMMAND_H

#include "StaffCommand.h"
#include "Plant.h"

class RemoveCommand : public StaffCommand {

public:
	RemoveCommand(Plant* plant);

	void execute();
};

#endif
