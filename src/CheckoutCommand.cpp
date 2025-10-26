#include "CheckoutCommand.h"

CheckoutCommand::CheckoutCommand(Staff* s, std::vector<Product*>* o) : CustomerCommand(s, NULL, o){}

string CheckoutCommand::execute(Customer* customer){
    if(staff)
        return staff->handleRequest(customer, "Checkout", nullptr, order);
    return "No staff assigned\n";
}
