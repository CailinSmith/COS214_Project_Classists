#ifndef INTERN_H
#define INTERN_H

#include "Staff.h"
#include <string>
using namespace std;

class Intern : public Staff {
public:
	Intern(const string& str);
	virtual ~Intern();
	virtual void send(string message, Staff* from);
	virtual void receive(string message);
	virtual void handleRequest();
};

#endif
