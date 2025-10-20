#ifndef STAFFMEDIATOR_H
#define STAFFMEDIATOR_H

#include <string>
#include <vector>
#include "Staff.h"

using namespace std;

class StaffMediator {
public:
    virtual ~StaffMediator() = default;
	virtual void notify(Staff* originator);
    virtual void registerColleague(Staff* colleague) = 0;
protected:
    vector<Staff*> colleagues;
};

#endif