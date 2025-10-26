#ifndef SALESSTAFF_H
#define SALESSTAFF_H

#include "Staff.h"
#include "Receipt.h"

#include <string>

using namespace std;

class SalesStaff : public Staff {
public:
	SalesStaff(string name);
	virtual string handleRequest(Customer* customer, const string& requestType, Plant* plant, std::vector<Product*>* order);
	virtual string getPosition() override;
};

#endif
