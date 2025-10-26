#ifndef CHECKOUTCOMMAND_H
#define CHECKOUTCOMMAND_H

#include "CustomerCommand.h"

class CheckoutCommand : public CustomerCommand{
    public:
        CheckoutCommand(Staff* s, std::vector<Product*>* o);
        virtual string execute(Customer* customer) override;
};

#endif