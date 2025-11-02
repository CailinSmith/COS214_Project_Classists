#ifndef CHECKOUTCOMMAND_H
#define CHECKOUTCOMMAND_H

#include "CustomerCommand.h"

/**
 * @class CheckoutCommand
 * @author Abhay Rooplall
 * @brief
 * Design Pattern: Command
 * Participant: Concrete Command
 * 
 * This class represents a concrete command for processing customer checkout.
 * It encapsulates the checkout request with the customer's order and processes
 * the transaction through the appropriate staff member.
 * 
 * @see CustomerCommand
 * @see Receipt
 */



class CheckoutCommand : public CustomerCommand{
    public:
        /**
         * @brief Constructor for CheckoutCommand
         * @param s Pointer to the staff member handling the checkout
         * @param o Pointer to the order vector containing products
         * @param flags Pointer to flags indicating refund eligibility
         */
        CheckoutCommand(Staff* s, std::vector<Product*>* o, vector<bool>* flags);
        /**
         * @brief Executes the checkout command
         * @return Pair containing checkout confirmation message and receipt pointer
         */
        virtual pair<string, Receipt*> execute() override;
};

#endif