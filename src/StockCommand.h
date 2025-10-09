#ifndef STOCKCOMMAND_H
#define STOCKCOMMAND_H

#include "StaffCommand.h"

class StockCommand : public StaffCommand {

public:
	StockCommand();

	void execute();
};

#endif
