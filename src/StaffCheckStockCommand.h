/**
 * @file StaffCommand.h
 * @author Cailin Smith
 * @date 2025-10-22
 */

#ifndef STAFFCHECKSTOCKCOMMAND_H
#define STAFFCHECKSTOCKCOMMAND_H

#include "StaffCommand.h"
#include "Plant.h"
#include "InventoryManager.h"

class StaffCheckStockCommand : public StaffCommand {
private:
    int stock;

public:
    StaffCheckStockCommand(Plant* p, InventoryManager* im);
    virtual ~StaffCheckStockCommand();
    void execute() override;
    int getStock();
};

#endif