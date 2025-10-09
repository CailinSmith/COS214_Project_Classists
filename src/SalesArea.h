#ifndef SALESAREA_H
#define SALESAREA_H

#include "StaffMediator.h"
#include "Staff.h"
#include <string>
using namespace std;

class SalesArea : public StaffMediator {

public:
	virtual void notify(string message, Staff* from) = 0;
};

#endif
