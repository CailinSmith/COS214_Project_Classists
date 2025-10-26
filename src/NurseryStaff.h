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
	virtual std::string handleRequest(Customer* customer, const std::string& requestType, Plant* plant, std::vector<Product*>* order) override;
	virtual string getPosition() override;
	virtual void update(const string& message);
};

#endif