#include "CheckStockCommand.h"

CheckStockCommand::CheckStockCommand(Staff* s, Plant* p) : CustomerCommand(s, p, NULL){}

string CheckStockCommand::execute(Customer* customer){
    if(staff)
        return staff->handleRequest(customer, "CheckStock", plant, NULL);
    return "No staff assigned\n";
}
