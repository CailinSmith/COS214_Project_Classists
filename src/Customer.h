#ifndef CUSTOMER_H
#define CUSTOMER_H

#include "Product.h"
#include <vector>
using namespace std;

class Customer {

private:
	vector<Product*> order;
	float total;
};

#endif
