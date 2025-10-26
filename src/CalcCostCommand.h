/**
 * @file CalcCostCommand.h
 * @author Cailin Smith
 * @date 2025-10-22
 */

#ifndef CALCCOSTCOMMAND_H
#define CALCCOSTCOMMAND_H

#include "StaffCommand.h"
#include "Plant.h"
#include "Nursery.h"

class CalcCostCommand : public StaffCommand {
private:
    float cost;

public:
    CalcCostCommand(Plant* p, Nursery* n);
    virtual ~CalcCostCommand();

    void execute();
    float getCost();
};

#endif