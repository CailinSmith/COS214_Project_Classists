#ifndef MANAGER_H
#define MANAGER_H

#include "Staff.h"
#include <string>
using namespace std;

class Manager : public Staff {
public:
	void send(string message, Staff* from);
	void receive(string message);
	void handleRequest();
};

#endif
