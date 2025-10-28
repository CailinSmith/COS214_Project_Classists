/**
 * @file PruneCommand.h
 * @author Cailin Smith
 * @date 2025-10-09
 */

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
