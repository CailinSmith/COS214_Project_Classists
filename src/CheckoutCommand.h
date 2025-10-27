#ifndef CHECKOUTCOMMAND_H
#define CHECKOUTCOMMAND_H

#include "CustomerCommand.h"

class CheckoutCommand : public CustomerCommand{
    public:
        CheckoutCommand(Staff* s, std::vector<Product*>* o, vector<bool>* flags);
        virtual pair<string, Receipt*> execute() override;
};

#endif