/**
 * @file GetInfoCommand.h
 * @author Cailin Smith
 * @date 2025-10-22
 */

#ifndef GETINFOCOMMAND_H
#define GETINFOCOMMAND_H

#include "StaffCommand.h"
#include "Plant.h"
#include <string>

class GetInfoCommand : public StaffCommand {
private:
    std::string info;

public:
    GetInfoCommand(Plant* p);
    virtual ~GetInfoCommand();
    void execute() override;
    std::string getInfo();
};

#endif