#ifndef MANAGER_H
#define MANAGER_H

#include "Staff.h"
#include "SalesArea.h"
#include "NurseryArea.h"

#include <string>

using namespace std;

class Manager : public Staff {
public:
    Manager(string name);
	virtual void handleRequest() override;
	virtual string getPosition() override;
};

#endif