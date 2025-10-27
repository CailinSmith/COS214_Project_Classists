#include "CheckStockCommand.h"

CheckStockCommand::CheckStockCommand(Staff* s, Plant* p) : CustomerCommand(s, p, nullptr, nullptr){}

pair<string, Receipt*> CheckStockCommand::execute(){
    if(staff){
        return staff->handleRequest("CheckStock", plant, nullptr, nullptr);
    }
    pair<string, Receipt*> result;
    result.first = "No staff assigned\n";
    result.second = nullptr;
    return result;
}
