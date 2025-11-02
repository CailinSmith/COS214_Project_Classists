#ifndef REFUNDCOMMAND_H
#define REFUNDCOMMAND_H

#include "CustomerCommand.h"

/**
 * @class RefundCommand
 * @author Abhay Rooplall
 * @brief
 * Design Pattern: Command
 * Participant: Concrete Command
 * 
 * This class represents a concrete command for processing customer refund requests.
 * It encapsulates the refund request with the customer's order and processes
 * the refund through the appropriate staff member.
 * 
 * @see CustomerCommand
 * @see Receipt
*/
class RefundCommand : public CustomerCommand {
public:
    /**
     * @brief Constructor for CheckoutCommand
     * @param s Pointer to the staff member handling the checkout
     * @param o Pointer to the order vector containing products
     * @param flags Pointer to flags indicating refund eligibility
     */
    RefundCommand(Staff* s, std::vector<Product*>* o, vector<bool>* flags);
    /**
     * @brief Executes the refund command
     * @return Pair containing refund confirmation message and receipt pointer
     */
    virtual pair<string, Receipt*> execute() override;
};

#endif