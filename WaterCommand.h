#ifndef WATERCOMMAND_H
#define WATERCOMMAND_H

#include "StaffCommand.h"

class Plant; // Forward declaration

class WaterCommand : public StaffCommand {
public:
	WaterCommand(Plant* plant);
	void execute();
};

#endif
