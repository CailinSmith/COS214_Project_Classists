#include "CheckoutCommand.h"

CheckoutCommand::CheckoutCommand(Staff* s, std::vector<Product*>* o, vector<bool>* flags) : CustomerCommand(s, nullptr, o, nullptr){}

pair<string, Receipt*> CheckoutCommand::execute(){
    if(staff)
        return staff->handleRequest("Checkout", nullptr, order, nullptr);
    pair<string, Receipt*> result;
    result.first = "No staff assigned\n";
    result.second = nullptr;
    return result;
}
