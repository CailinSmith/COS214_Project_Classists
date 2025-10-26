#ifndef CUSTOMERCOMMAND_H
#define CUSTOMERCOMMAND_H

#include "Staff.h"

class CustomerCommand{
    protected:
        Staff* staff;
        Plant* plant;
        vector<Product*>* order;
    public:
        CustomerCommand(Staff* s, Plant* p, vector<Product*>* o) : staff(s), plant(p), order(o){}
        virtual ~CustomerCommand(){}
        virtual string execute(Customer* customer) = 0;
};

#endif
