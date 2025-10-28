#ifndef NURSERYSTAFF_H
#define NURSERYSTAFF_H

#include "Staff.h"
#include "GetInfoCommand.h"
#include "Nursery.h"
#include "InventoryManager.h"
#include "StaffCheckStockCommand.h"

#include <string>

using namespace std;

class NurseryStaff : public Staff {
public:
	NurseryStaff(string name);
	virtual pair<string, Receipt*> handleRequest(const string& requestType, Plant* plant, vector<Product*>* order, vector<bool>* flags) override;
	virtual string getPosition() override;
	virtual void update(const string& message);
};

#endif