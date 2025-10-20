#ifndef SALESSTAFF_H
#define SALESSTAFF_H

#include "Staff.h"
#include "SalesArea.h"

#include <string>

using namespace std;

class SalesStaff : public Staff {
public:
	SalesStaff(string name);
	virtual void handleRequest() override;
	virtual string getPosition() override;
};

#endif
