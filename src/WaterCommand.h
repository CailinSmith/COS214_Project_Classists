#ifndef WATERCOMMAND_H
#define WATERCOMMAND_H

#include "StaffCommand.h"
#include "Plant.h"

class WaterCommand : public StaffCommand {
public:
	WaterCommand(Plant* plant);
	void execute();
};

#endif
