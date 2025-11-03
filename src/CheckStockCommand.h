#ifndef CHECKSTOCKCOMMAND_H
#define CHECKSTOCKCOMMAND_H

#include "CustomerCommand.h"

/**
 * @class CheckStockCommand
 * @author Abhay Rooplall
 * @brief
 * Design Pattern: Command
 * Participant: Concrete Command
 * 
 * This class represents a concrete command for checking plant stock availability.
 * It encapsulates the request to check if a specific plant is in stock, delegating
 * the actual work to the appropriate staff member.
 * 
 * @see CustomerCommand
 * @see Staff
 */


class CheckStockCommand : public CustomerCommand{
    public:
        /**
         * @brief Constructor for CheckStockCommand
         * @param s Pointer to the staff member handling the command
         * @param p Pointer to the plant to check stock for
         */
        CheckStockCommand(Staff* s, Plant* p);
        /**
         * @brief Executes the stock check command
         * @return Pair containing stock information message and receipt pointer
         */
        virtual pair<string, Receipt*> execute() override;
};

#endif