#ifndef SALESSTAFF_H
#define SALESSTAFF_H

#include "Staff.h"
#include <string>
using namespace std;

class SalesStaff : public Staff {

public:
	void send(string message, Staff* from);

	void receive(string message);

	void handleRequest();
};

#endif
