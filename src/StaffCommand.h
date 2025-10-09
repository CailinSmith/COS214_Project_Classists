#ifndef STAFFCOMMAND_H
#define STAFFCOMMAND_H

#include "Plant.h"

class StaffCommand {

public:
	void execute();

protected:
	Plant* plant;
};

#endif
