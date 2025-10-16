#ifndef MANAGER_H
#define MANAGER_H

#include "Staff.h"
#include <string>
using namespace std;

class Manager : public Staff {
public:
	Manager(const string& str);
	virtual ~Manager();
	virtual void send(string message, Staff* from);
	virtual void receive(string message);
	virtual void handleRequest();
};

#endif
