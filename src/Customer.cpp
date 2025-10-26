#include "Customer.h"
#include "CustomerCommand.h"

Customer::Customer(string n) : total(0.0), command(NULL), receipt(NULL){
    name = n;
}

Customer::~Customer(){
}

void Customer::setReceipt(Receipt r){
    receipt = &r;
}

std::string Customer::sendCommand(CustomerCommand* cmd){
    if(cmd){
        command = cmd;
        return command->execute(this);
    }
    return "Invalid command\n";
}

void Customer::clearOrder(){
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
        cost += plant->calculateCost("Summer");//just for now until we can have global season logic
    }
    this->total = cost;
    return cost;
}

