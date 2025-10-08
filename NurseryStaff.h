#ifndef NURSERYSTAFF_H
#define NURSERYSTAFF_H

#include "Staff.h"
#include <string>
using namespace std;

class NurseryStaff : public Staff {
public:
	void send(string message, Staff* from);
	void receive(string message);
	void handleRequest();
};

#endif
