#ifndef STAFFMEDIATOR_H
#define STAFFMEDIATOR_H

#include <string>
using namespace std;
class Staff;

class StaffMediator {

public:
	virtual void notify(string message, Staff* from) = 0;
};

#endif
