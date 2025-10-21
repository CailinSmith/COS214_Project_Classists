#ifndef SALESSTAFF_H
#define SALESSTAFF_H

#include "Staff.h"
#include <string>
using namespace std;

class SalesStaff : public Staff {

public:
	SalesStaff(const string& str);
	virtual ~SalesStaff();
	virtual void send(string message, Staff* from);
	virtual void receive(string message);
	virtual void handleRequest();
};

#endif
