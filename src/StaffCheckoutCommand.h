/**
 * @file StaffCheckoutCommand.h
 * @author Cailin Smith
 * @date 2025-10-22
 */

#ifndef STAFFCHECKOUTCOMMAND_H
#define STAFFCHECKOUTCOMMAND_H

#include "StaffCommand.h"
#include "Plant.h"
#include "Product.h"
#include "Receipt.h"
#include <vector>

class StaffCheckoutCommand : public StaffCommand {
private:
    std::vector<Product*> plants;
    Receipt* receipt;

public:
    StaffCheckoutCommand(const std::vector<Product*>& p);
    virtual ~StaffCheckoutCommand();
    void execute() override;
    Receipt* getReceipt();
};

#endif