#ifndef CUSTOMER_H
#define CUSTOMER_H

#include "Plant.h"
#include <vector>
using namespace std;

class Customer {

private:
	vector<Plant*> order;
	float total;
};

#endif
