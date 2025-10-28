#ifndef SALESSTAFF_H
#define SALESSTAFF_H

#include "Staff.h"
#include "Receipt.h"

#include <string>

using namespace std;

class SalesStaff : public Staff {
public:
	SalesStaff(string name);
	virtual pair<string, Receipt*> handleRequest(const string& requestType, Plant* plant, vector<Product*>* order, vector<bool>* flags);
	virtual string getPosition() override;
};

#endif
