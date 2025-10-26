#ifndef CUSTOMER_H
#define CUSTOMER_H

#include "Staff.h"
#include "Product.h"
#include "Receipt.h"
#include <vector>
#include <iostream>

class CustomerCommand;

using namespace std;

class Customer {

private:
	float total;
	string name;
	vector<Product*> order;
	CustomerCommand* command;
	Receipt* receipt;
public:
	Customer(string n);
	~Customer();
	std::string sendCommand(CustomerCommand* cmd);
	void addToCart(Product* p);
	void clearOrder();
	float totalCost();
	void setReceipt(Receipt r);
	string getName() const;
	vector<Product*>& getOrder();
};

#endif