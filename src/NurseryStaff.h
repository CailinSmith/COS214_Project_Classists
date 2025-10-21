#ifndef NURSERYSTAFF_H
#define NURSERYSTAFF_H

#include "Staff.h"

#include <string>

using namespace std;

class NurseryStaff : public Staff {
public:
	NurseryStaff(string name);
	virtual void handleRequest() override;
	virtual string getPosition() override;
};

#endif