#ifndef FERTILISECOMMAND_H
#define FERTILISECOMMAND_H

#include "StaffCommand.h"

class FertiliseCommand : public StaffCommand {
	
public:
	FertiliseCommand(Plant* plant);
	void execute();
};

#endif
