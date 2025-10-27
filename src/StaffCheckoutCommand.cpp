#include "StaffCheckoutCommand.h"
#include <iostream>

StaffCheckoutCommand::StaffCheckoutCommand(const std::vector<Product*>& p) 
    : plants(p), receipt(nullptr) {
}

StaffCheckoutCommand::~StaffCheckoutCommand() {
    if(receipt)
        delete receipt;
}

void StaffCheckoutCommand::execute() {
    if (!plants.empty()) {
        Receipt* receipt = new Receipt(plants);
        
        if (receipt != nullptr) {
            plants.clear();            
            this->receipt = receipt;
        } else {
            std::cout << "Error: Could not generate receipt" << std::endl;
        }
    } else {
        std::cout << "No products to checkout" << std::endl;
    }
}

Receipt* StaffCheckoutCommand::getReceipt() {
    // Transfer ownership to the caller. After this call, this command no longer
    // owns the receipt and will not delete it in the destructor.
    Receipt* temp = receipt;
    receipt = nullptr;
    return temp;
}