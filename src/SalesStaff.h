#ifndef SALESSTAFF_H
#define SALESSTAFF_H

#include "Staff.h"
#include "Receipt.h"

#include <string>

using namespace std;

/**
 * @class SalesStaff
 * @author Abhay Rooplall
 * @author Edwin Kusel
 * @brief
 * Design Pattern: Chain of Responsibility
 * Participant: Concrete Handler
 * 
 * This class represents sales staff members who handle customer checkout and
 * refund requests. It implements the Staff interface as part of the Chain of
 * Responsibility pattern, processing sales-related requests.
 * 
 * @see Staff
 * @see Receipt
 */
class SalesStaff : public Staff {
public:
	/**
	 * @brief Constructor for SalesStaff
	 * @param name The name of the sales staff member
	 */
	SalesStaff(string name);
	/**
	 * @brief Handles customer requests related to sales operations
	 * @param requestType The type of request to handle
	 * @param plant Pointer to the plant involved in the request
	 * @param order Pointer to the order vector
	 * @param flags Pointer to flags for the order
	 * @return Pair containing response message and receipt pointer
	 */
	virtual pair<string, Receipt*> handleRequest(const string& requestType, Plant* plant, vector<Product*>* order, vector<bool>* flags);
	/**
	 * @brief Gets the position/role of this staff member
	 * @return String representing the position "Sales Staff"
	 */
	virtual string getPosition() override;
};

#endif
