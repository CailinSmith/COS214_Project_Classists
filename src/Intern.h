#ifndef INTERN_H
#define INTERN_H

#include "Staff.h"

#include <string>
#include <iostream>

using namespace std;

class Intern : public Staff {
public:
	Intern(string name);
	virtual void handleRequest() override;
	virtual string getPosition() override;
	
};

#endif
