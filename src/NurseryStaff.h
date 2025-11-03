#ifndef NURSERYSTAFF_H
#define NURSERYSTAFF_H

#include "Staff.h"
#include "GetInfoCommand.h"
#include "Nursery.h"
#include "InventoryManager.h"
#include "StaffCheckStockCommand.h"

#include <string>

using namespace std;

/**
 * @class NurseryStaff
 * @author Abhay Rooplall
 * @author Edwin Kusel
 * @author Cailin Smith
 * @brief
 * Design Pattern: Chain of Responsibility, Observer
 * Participant: Concrete Handler, Concrete Observer
 * 
 * This class represents nursery staff members who handle plant-related requests
 * such as getting plant information and checking stock. It implements the Staff
 * interface as part of the Chain of Responsibility pattern and acts as an observer
 * for inventory updates.
 * 
 * @see Staff
 * @see Nursery
 */


class NurseryStaff : public Staff {
public:
	/**
	 * @brief Constructor for NurseryStaff
	 * @param name The name of the nursery staff member
	 */
	NurseryStaff(string name);
	/**
	 * @brief Handles customer requests related to nursery operations
	 * @param requestType The type of request to handle
	 * @param plant Pointer to the plant involved in the request
	 * @param order Pointer to the order vector
	 * @param flags Pointer to flags for the order
	 * @return Pair containing response message and receipt pointer
	 */
	virtual pair<string, Receipt*> handleRequest(const string& requestType, Plant* plant, vector<Product*>* order, vector<bool>* flags) override;
	/**
	 * @brief Gets the position/role of this staff member
	 * @return String representing the position "Nursery Staff"
	 */
	virtual string getPosition() override;
	/**
	 * @brief Updates the staff member with notifications from subjects
	 * @param message The notification message received
	 */
	virtual void update(const string& message);
};

#endif