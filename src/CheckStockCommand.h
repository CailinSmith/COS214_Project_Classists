#ifndef CHECKSTOCKCOMMAND_H
#define CHECKSTOCKCOMMAND_H

#include "CustomerCommand.h"

class CheckStockCommand : public CustomerCommand{
    public:
        CheckStockCommand(Staff* s, Plant* p);
        virtual string execute(Customer* customer) override;
};

#endif