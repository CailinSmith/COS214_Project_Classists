#ifndef INTERN_H
#define INTERN_H

#include "Staff.h"

#include <string>

using namespace std;

class Intern : public Staff {
public:
    Intern(string name);
	virtual void handleRequest() override;
	virtual string getPosition() override;
};

#endif