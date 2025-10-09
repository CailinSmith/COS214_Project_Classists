#ifndef WATERCOMMAND_H
#define WATERCOMMAND_H

#include "StaffCommand.h"

class Plant;

class WaterCommand : public StaffCommand {
public:
	WaterCommand(Plant* plant);
	void execute();
};

#endif
