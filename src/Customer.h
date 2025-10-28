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

class Customer {

private:
	float total;
	string name;
	vector<Product*> order;
	CustomerCommand* command;
	vector<Receipt*> receipts;
public:
	Customer(string n);
	~Customer();
	pair<string, Receipt*> sendCommand(CustomerCommand* cmd);
	void addToCart(Product* p);
	void clearOrder();
	float totalCost();
	void addReceipt(Receipt* r);
	string getName() const;
	vector<Product*>& getOrder();
	vector<Receipt*>& getReceipts();
};

#endif