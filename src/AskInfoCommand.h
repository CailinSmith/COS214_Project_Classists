#ifndef ASKINFOCOMMAND_H
#define ASKINFOCOMMAND_H

#include "CustomerCommand.h"
#include "Plant.h"

/**
 * @class AskInfoCommand
 * @author Abhay Rooplall
 * @brief
 * Design Pattern: Command
 * Participant: Concrete Command
 * 
 * Encapsulates a customer's request for plant information into a command object.
 * When executed, routes the information request to appropriate nursery staff who
 * can provide details about plant care, characteristics and maintenance.
 * 
 * @see CustomerCommand
 * @see Plant
 * @see Staff
 */
class AskInfoCommand : public CustomerCommand {
    public:
        /**
         * @brief Constructs the AskInfoCommand with the given staff and plant.
         * @param s Pointer to the Staff member who will handle the request.
         * @param p Pointer to the Plant for which information is requested.
        */
        AskInfoCommand(Staff* s, Plant* p);
        /**
         * @brief Executes the command by routing the information request to the staff.
         * @return A pair containing the information string and a null Receipt pointer since a receipt is not issued.
        */
        virtual pair<string, Receipt*> execute() override;
};

#endif