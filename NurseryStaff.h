#ifndef NURSERYSTAFF_H
#define NURSERYSTAFF_H

#include "Staff.h"
#include <string>
using namespace std;

class NurseryStaff : public Staff {
public:
	NurseryStaff(const string& str);
	virtual ~NurseryStaff();
	virtual void send(string message, Staff* from);
	virtual void receive(string message);
	virtual void handleRequest();
};

#endif
