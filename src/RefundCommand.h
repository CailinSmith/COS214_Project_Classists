#ifndef REFUNDCOMMAND_H
#define REFUNDCOMMAND_H

#include "CustomerCommand.h"

class RefundCommand : public CustomerCommand {
public:
    RefundCommand(Staff* s, std::vector<Product*>* o, vector<bool>* flags);
    virtual pair<string, Receipt*> execute() override;
};

#endif