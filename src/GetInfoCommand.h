#ifndef GETINFOCOMMAND_H
#define GETINFOCOMMAND_H

#include "StaffCommand.h"
#include "Plant.h"
#include <string>

/**
 * @class GetInfoCommand
 * @author Cailin Smith
 * @brief Command for retrieving plant information.
 * Design Pattern: Command
 * Participant: ConcreteCommand
 * 
 * This class encapsulates the action of retrieving detailed information about a plant,
 * including its characteristics, care requirements, and current state. The information
 * can be accessed after execution via the getInfo() method.
 * 
 * @see StaffCommand
 * @see Plant
 */
class GetInfoCommand : public StaffCommand {
private:
    /**
     * @brief Stores the retrieved plant information
     */
    std::string info;

public:
    /**
     * @brief Constructs a GetInfoCommand for a specific plant.
     * @param p Pointer to the Plant whose information is to be retrieved.
     */
    GetInfoCommand(Plant* p);
    
    /**
     * @brief Destructor for the GetInfoCommand.
     */
    virtual ~GetInfoCommand();
    
    /**
     * @brief Executes the get info command.
     * 
     * Retrieves and stores detailed information about the plant.
     */
    void execute() override;
    
    /**
     * @brief Gets the retrieved plant information.
     * @return std::string The detailed plant information string.
     */
    std::string getInfo();
};

#endif