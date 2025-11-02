#ifndef STAFF_H
#define STAFF_H

#include <string>
#include <vector>
#include <utility>
#include <iostream>
#include <algorithm>
#include <chrono>
#include <mutex>
#include "Plant.h"
#include "Receipt.h"

class StaffMediator;
class Customer;
class StaffCommand;

using namespace std;

/**
 * @class Staff
 * @author Edwin Kusel
 * @author Abhay Rooplall
 * 
 * @brief
 * Design pattern: Mediator, Chain of Responsibility, Command, Observer
 * Participant: Colleague, Handler, Receiver, Observer
 * 
 * This class represents a staff member.
 * 
 * @see StaffMediator
 * @see CustomerCommand
 * @see StaffCommand
 * @see Product
 */
class Staff {
public:
    /**
     * @brief Constructor.
     * @param name The name of the staff member.
     */
    Staff(string name);
    /**
     * @brief Destructor.
     */
    virtual ~Staff();
    /**
     * @brief Sends a message to colleagues via the mediator.
     */
	virtual void send();
    /**
     * @brief Receives a message from a colleague via the mediator.
     * @param message The message received.
     */
	void receive(string message);
    /**
     * @brief Retrieves the chat history as a formatted string.
     * @return A string representation of the chat history.
     */
    std::string getChatHistoryString() const;
    /**
     * @brief Clears the chat history.
     */
    void clearChatHistory();
    /**
     * @brief Handles a request in the chain of responsibility.
     * @param requestType The type of request.
     * @param plant The plant involved in the request.
     * @param order The order vector for products.
     * @param flags Additional flags for processing.
     * @return A pair containing a status message and a receipt pointer.
     */
	virtual pair<string, Receipt*> handleRequest(const std::string& requestType, Plant* plant, std::vector<Product*>* order, vector<bool>* flags);
    /**
     * @brief Sets the command to be executed.
     * @param cmd The command to set.
     */
    void setCommand(StaffCommand* cmd);
    /**
     * @brief returns the position of the staff member
     */
	virtual string getPosition() = 0;
    /**
     * @brief Gets the current message.
     * @return The current message.
     */
    string getMessage();
    /**
     * @brief Sets the current message.
     * @param message The message to set.
     */
    void setMessage(string message);
    /**
     * @brief Gets the name of the staff member.
     * @return The name of the staff member.
     */
	string getName();
    /**
     * @brief Sets the next staff member in the chain of responsibility.
     * @param nextStaff The next staff member.
     */
    void setNext(Staff* nextStaff);
    /**
     * @brief Registers a mediator for this staff member.
     * @param mediator The mediator to register.
     */
    void registerMediator(StaffMediator* mediator);
    /**
     * @brief Deregisters a mediator for this staff member.
     * @param mediator The mediator to deregister.
     */
    void deregisterMediator(StaffMediator* mediator);
    /**
     * @brief Updates the staff member with a new message.
     * @param message The message to update with.
     */
    virtual void update(const string& message);
protected:
    /**
     * @brief The name of the staff member.
     */
    string name;
    /**
     * @brief The next staff member in the chain of responsibility.
     */
	Staff* next;
    /**
     * @brief The mediators this staff member is registered with.
     */
    vector<StaffMediator*> mediators;
    /**
     * @brief The command to be executed by this staff member.
     */
    StaffCommand* command;
    /**
     * @brief Mutex for thread-safe chat history access.
     */
    mutable std::mutex chatMutex;
    /**
     * @brief The chat history of messages.
     */
    std::vector<std::pair<std::chrono::system_clock::time_point, std::string>> chatHistory;
private:
    /**
     * @brief The current message.
     */
	string message;
};

#endif