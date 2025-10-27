#include "RefundCommand.h"

RefundCommand::RefundCommand(Staff* s, std::vector<Product*>* o, vector<bool>* f) : CustomerCommand(s, nullptr, o, f){}

pair<string, Receipt*> RefundCommand::execute(){
    if(staff){}
        return staff->handleRequest("Refund", nullptr, order, flags);
    pair<string, Receipt*> result;
    result.first = "No staff assigned\n";
    result.second = nullptr;
    return result;
}
