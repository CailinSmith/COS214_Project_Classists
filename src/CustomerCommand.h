#ifndef CUSTOMERCOMMAND_H
#define CUSTOMERCOMMAND_H

#include "Staff.h"
#include "Receipt.h"
#include <utility>

class CustomerCommand{
    protected:
        Staff* staff;
        Plant* plant;
        vector<Product*>* order;
        vector<bool>* flags;
    public:
        CustomerCommand(Staff* s, Plant* p, vector<Product*>* o, vector<bool>* f) : staff(s), plant(p), order(o), flags(f){}
        virtual ~CustomerCommand(){}
        virtual pair<string, Receipt*> execute() = 0;
};

#endif
