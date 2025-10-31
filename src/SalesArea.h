#ifndef SALESAREA_H
#define SALESAREA_H

#include "StaffMediator.h"
#include "Staff.h"

#include <string>

using namespace std;

class SalesArea : public StaffMediator {
public:
    virtual void notify(Staff* originator) override;
    virtual void registerColleague(Staff* colleague) override;
    virtual void unregisterColleague(Staff* colleague) override;
};

#endif