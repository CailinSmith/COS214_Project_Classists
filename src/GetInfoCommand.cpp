#include "GetInfoCommand.h"
#include <iostream>

GetInfoCommand::GetInfoCommand(Plant* p) : StaffCommand(){
    plant = p;
}

GetInfoCommand::~GetInfoCommand() {}

void GetInfoCommand::execute() {
    if (plant) {
        info = "Plant Information:\n";
        info += plant->customerSummary();
    } else {
        info = "No plant information available.";
    }    
}

std::string GetInfoCommand::getInfo() {
    return info;
}