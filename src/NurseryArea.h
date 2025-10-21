#ifndef NURSERYAREA_H
#define NURSERYAREA_H

#include "StaffMediator.h"
#include "Staff.h"

#include <string>

using namespace std;

class NurseryArea : public StaffMediator {
public:
    virtual void notify(Staff* originator) override;
    virtual void registerColleague(Staff* colleague) override;
};

#endif