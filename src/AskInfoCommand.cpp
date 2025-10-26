#include "AskInfoCommand.h"

AskInfoCommand::AskInfoCommand(Staff* s, Plant* p) : CustomerCommand(s, p, NULL){}

string AskInfoCommand::execute(Customer* customer){
    if(staff)
        return staff->handleRequest(customer, "AskInfo", plant, NULL);
    return "No staff assigned\n";
}
