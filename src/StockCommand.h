/**
 * @file StockCommand.h
 * @author Cailin Smith
 * @date 2025-10-09
 */

#ifndef STOCKCOMMAND_H
#define STOCKCOMMAND_H

#include "StaffCommand.h"

class StockCommand : public StaffCommand {

public:
	StockCommand(Nursery* n);
	void execute();
};

#endif
