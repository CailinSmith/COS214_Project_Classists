#ifndef CUSTOMER_H
#define CUSTOMER_H

#include "Staff.h"
#include "Product.h"
#include "Receipt.h"
#include "Nursery.h"
#include <vector>
#include <iostream>


class CustomerCommand;

using namespace std;

/**
 * @class Customer
 * @author Abhay Rooplall
 * @brief
 * Design Pattern: Command
 * Participant: Client/Invoker
 * 
 * This class represents a customer in the plant shop system. It acts as the invoker
 * in the Command pattern, sending commands to staff members to perform various operations
 * such as checking out, checking stock, or requesting refunds. The customer maintains
 * their shopping cart and purchase history.
 * 
 * @see CustomerCommand
 * @see Product
 * @see Receipt
 */


class Customer {

private:
	/**
	 * @brief Total cost of the current order
	 */
	float total;
	/**
	 * @brief Name of the customer
	 */
	string name;
	/**
	 * @brief Current order (shopping cart) of products
	 */
	vector<Product*> order;
	/**
	 * @brief The command to be executed
	 */
	CustomerCommand* command;
	/**
	 * @brief History of receipts for completed purchases
	 */
	vector<Receipt*> receipts;
public:
	/**
	 * @brief Constructor for Customer
	 * @param n The name of the customer
	 */
	Customer(string n);
	/**
	 * @brief Destructor - cleans up allocated resources
	 */
	~Customer();
	/**
	 * @brief Sends a command to be executed by staff
	 * @param cmd Pointer to the CustomerCommand to execute
	 * @return Pair containing response message and receipt pointer
	 */
	pair<string, Receipt*> sendCommand(CustomerCommand* cmd);
	/**
	 * @brief Adds a product to the shopping cart
	 * @param p Pointer to the product to add
	 */
	void addToCart(Product* p);
	/**
	 * @brief Clears all items from the shopping cart
	 */
	void clearOrder();
	/**
	 * @brief Calculates the total cost of items in the cart
	 * @return The total cost as a float
	 */
	float totalCost();
	/**
	 * @brief Adds a receipt to the customer's purchase history
	 * @param r Pointer to the receipt to add
	 */
	void addReceipt(Receipt* r);
	/**
	 * @brief Gets the customer's name
	 * @return The customer's name as a string
	 */
	string getName() const;
	/**
	 * @brief Gets the customer's current order
	 * @return Reference to the order vector
	 */
	vector<Product*>& getOrder();
	/**
	 * @brief Gets the customer's receipt history
	 * @return Reference to the receipts vector
	 */
	vector<Receipt*>& getReceipts();
};

#endif