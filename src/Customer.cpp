#include "Customer.h"
#include "CustomerCommand.h"

Customer::Customer(string n) : total(0.0), command(NULL){
    name = n;
}

Customer::~Customer(){
    // Clean up receipts
    for (Receipt* r : receipts) {
        delete r;
    }
    receipts.clear();
    
    // Clean up any remaining products in order
    clearOrder();
}

void Customer::addReceipt(Receipt* r){
    receipts.push_back(r);
}

pair<string, Receipt*> Customer::sendCommand(CustomerCommand* cmd){
    if(cmd){
        command = cmd;
        auto res = command->execute();
        if (res.second != nullptr) {
            addReceipt(res.second);
            // addReceipt copied the receipt into customer's storage. delete
            // the temporary receipt returned by the command to avoid leaking it.
            // delete res.second;
            // res.second = nullptr;
            order.clear();  // Clear but don't delete products
        }
        return res;
    }
    pair<string, Receipt*> result;
    result.first = "Invalid command";
    result.second = nullptr;
    return result;
}

void Customer::clearOrder(){
    // Don't delete products here as they might be used elsewhere
    order.clear();
}

vector<Product*>& Customer::getOrder(){
    return order;
}

void Customer::addToCart(Product* p){
    order.push_back(p);
}

string Customer::getName() const{
    return name;
}

float Customer::totalCost(){
    float cost = 0.0;
    for(auto plant : order){
        cost += plant->calculateCost(Nursery::getInstance()->getSeason());
    }
    this->total = cost;
    return cost;
}

vector<Receipt*>& Customer::getReceipts(){
    return receipts;
}

