#ifndef ASKINFOCOMMAND_H
#define ASKINFOCOMMAND_H

#include "CustomerCommand.h"
#include "Plant.h"

class AskInfoCommand : public CustomerCommand{
    private:
        Plant* plant;
    public:
        AskInfoCommand(Staff* s, Plant* p);
        virtual string execute(Customer* customer) override;
};

#endif