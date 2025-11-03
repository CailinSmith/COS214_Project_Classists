#ifndef CALCCOSTCOMMAND_H
#define CALCCOSTCOMMAND_H

#include "StaffCommand.h"
#include "Plant.h"
#include "Nursery.h"

/**
 * @class CalcCostCommand
 * @author Cailin Smith
 * @brief Command for calculating the cost of a plant.
 * Design Pattern: Command
 * Participant: ConcreteCommand
 * 
 * This class encapsulates the action of calculating the total cost of a plant product,
 * taking into account the current season and any applied decorators. It stores the
 * calculated cost which can be retrieved after execution.
 * 
 * @see StaffCommand
 * @see Plant
 * @see Nursery
 */
class CalcCostCommand : public StaffCommand {
private:
    /**
     * @brief The calculated cost of the plant
     */
    float cost;

public:
    /**
     * @brief Constructs a CalcCostCommand for a specific plant.
     * @param p Pointer to the Plant whose cost is to be calculated.
     * @param n Pointer to the Nursery context for seasonal information.
     */
    CalcCostCommand(Plant* p, Nursery* n);
    
    /**
     * @brief Destructor for the CalcCostCommand.
     */
    virtual ~CalcCostCommand();

    /**
     * @brief Executes the cost calculation command.
     * 
     * Calculates the total cost of the plant based on current season and
     * stores the result in the cost member variable.
     */
    void execute();
    
    /**
     * @brief Gets the calculated cost after execution.
     * @return float The calculated cost of the plant.
     */
    float getCost();
};

#endif