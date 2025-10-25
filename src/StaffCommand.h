/**
 * @file StaffCommand.h
 * @author Cailin Smith
 * @date 2025-10-09
 */

#ifndef STAFFCOMMAND_H
#define STAFFCOMMAND_H

#include "Plant.h"
#include "InventoryManager.h"
#include "Nursery.h"

class StaffCommand {
protected:
    Plant* plant;
    InventoryManager* inventoryManager;
    Nursery* nursery;

public:
	StaffCommand(Plant* p = nullptr, InventoryManager* im = nullptr, Nursery* n = nullptr)
        : plant(p), inventoryManager(im), nursery(n) {}
	virtual void execute();

};

#endif
