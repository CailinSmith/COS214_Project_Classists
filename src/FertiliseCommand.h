/**
 * @file FertiliseCommand.h
 * @author Cailin Smith
 * @date 2025-10-09
 */

#ifndef FERTILISECOMMAND_H
#define FERTILISECOMMAND_H

#include "StaffCommand.h"

class FertiliseCommand : public StaffCommand {
	
public:
	FertiliseCommand(Plant* plant);
	void execute();
};

#endif
