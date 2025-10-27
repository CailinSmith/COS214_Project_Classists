#ifndef ASKINFOCOMMAND_H
#define ASKINFOCOMMAND_H

#include "CustomerCommand.h"
#include "Plant.h"

class AskInfoCommand : public CustomerCommand {
    public:
        AskInfoCommand(Staff* s, Plant* p);
        virtual pair<string, Receipt*> execute() override;
};

#endif