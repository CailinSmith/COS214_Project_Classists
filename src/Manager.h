#ifndef MANAGER_H
#define MANAGER_H

#include "Staff.h"
#include "StaffMediator.h"
#include "Nursery.h"

#include <string>
#include <sstream>

using namespace std;

/**
 * @class Manager
 * @author Abhay Rooplall
 * @author Edwin Kusel
 * @author Cailin Smith
 * @brief
 * Design Pattern: Chain of Responsibility, Mediator, Observer, Command
 * Participant: Concrete Handler, Concrete Colleague, Concrete Observer
 * 
 * This class represents a manager who handles complex requests and coordinates
 * communication between staff members through the mediator pattern. The manager
 * also observes inventory changes and can escalate requests within the chain.
 * 
 * @see Staff
 * @see StaffMediator
 */

class Manager : public Staff {
public:
    /**
     * @brief Constructor for Manager
     * @param name The name of the manager
     */
    Manager(string name);
    /**
     * @brief Sends a message through the mediator
     */
    virtual void send() override;
    /**
     * @brief Handles customer requests at the manager level
     * @param requestType The type of request to handle
     * @param plant Pointer to the plant involved in the request
     * @param order Pointer to the order vector
     * @param flags Pointer to flags for the order
     * @return Pair containing response message and receipt pointer
     */
    virtual pair<string, Receipt*> handleRequest(const string& requestType, Plant* plant, vector<Product*>* order, vector<bool>* flags) override;
	/**
     * @brief Gets the position/role of this staff member
     * @return String representing the position "Manager"
     */
    virtual string getPosition() override;
    /**
     * @brief Sets the mediator for staff communication
     * @param mediator Pointer to the StaffMediator
     */
    void setReceiver(StaffMediator* mediator);
    /**
     * @brief Updates the manager with notifications from subjects
     * @param message The notification message received
     */
    virtual void update(const string& message);
private:
    /**
     * @brief Mediator for staff communication
    */
    StaffMediator* receiver;
};

#endif