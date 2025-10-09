#ifndef PRUNECOMMAND_H
#define PRUNECOMMAND_H

#include "StaffCommand.h"
#include "Plant.h"

class PruneCommand : public StaffCommand {

public:
	PruneCommand(Plant* plant);

	void execute();
};

#endif
