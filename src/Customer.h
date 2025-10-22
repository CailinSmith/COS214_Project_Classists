#ifndef CUSTOMER_H
#define CUSTOMER_H

#include "Plant.h"
#include "Staff.h"
#include "Product.h"
#include <vector>
#include <iostream>
using namespace std;

class Customer {

private:
	vector<Product*> order;
	float total;
public:
	void send(Staff* staff, const std::string& command);
};

#endif