#ifndef INTERN_H
#define INTERN_H

#include "Staff.h"
#include <string>
using namespace std;

class Intern : public Staff {
public:
	void send(string message, Staff* from);
	void receive(string message);
	void handleRequest();
};

#endif
