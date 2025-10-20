#include "Customer.h"

void Customer::send(Staff* staff, const std::string& command){
    if(staff){
        std::cout << "Customer sent request: " << command << "\n";
        //staff->handleRequest(command); then pass command here
    }
    else{
        std::cout << "There is no staff available at the moment.\n";
    }
}
