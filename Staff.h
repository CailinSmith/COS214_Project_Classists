#ifndef STAFF_H
#define STAFF_H

#include <string>
using namespace std;
class Staff {

private:
	string name;
	Staff* next;

public:
	virtual void send(string message, Staff* from) = 0;

	virtual void receive(string message) = 0;

	virtual void handleRequest() = 0;

	string getName();
};

#endif
