#ifndef CUSTOMERCOMMAND_H
#define CUSTOMERCOMMAND_H

#include "Staff.h"
#include "Receipt.h"
#include <utility>

/**
 * @class CustomerCommand
 * @author Abhay Rooplall
 * @brief
 * Design Pattern: Command
 * Participant: Command Interface
 * 
 * This abstract class defines the interface for customer commands in the command pattern.
 * It encapsulates customer requests to staff members, allowing for parameterization and
 * queuing of requests. Concrete command classes implement the execute method to perform
 * specific operations.
 * 
 * @see Staff
 * @see Receipt
 */

class CustomerCommand{
    protected:
        /**
         * @brief Pointer to the staff member handling the command
        */
        Staff* staff;
        /**
         * @brief Pointer to the plant involved in the command
        */
        Plant* plant;
        /**
         * @brief Pointer to the order vector
        */
        vector<Product*>* order;
        /**
         * @brief Pointer to flags for the order (marking for refund)
        */
        vector<bool>* flags;
    public:
        /**
         * @brief Constructor for CustomerCommand
         * @param s Pointer to the staff member handling the command
         * @param p Pointer to the plant involved in the command
         * @param o Pointer to the order vector
         * @param f Pointer to flags for the order
         */
        CustomerCommand(Staff* s, Plant* p, vector<Product*>* o, vector<bool>* f) : staff(s), plant(p), order(o), flags(f){}
        /**
         * @brief Virtual destructor
         */
        virtual ~CustomerCommand(){}
        /**
         * @brief Executes the customer command
         * @return Pair containing response message and receipt pointer
         */
        virtual pair<string, Receipt*> execute() = 0;
};

#endif
