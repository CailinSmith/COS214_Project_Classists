#ifndef STAFF_H
#define STAFF_H

#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

class StaffMediator;

using namespace std;

class Staff {
public:
    Staff(string name);
    virtual ~Staff() = default;
	virtual void send();
	void receive(string message);
	virtual void handleRequest() = 0;
	virtual string getPosition() = 0;
    string getMessage();
    void setMessage(string message);
	string getName();
    void registerMediator(StaffMediator* mediator);
    void deregisterMediator(StaffMediator* mediator);
protected:
    vector<StaffMediator*> mediators;
private:
	string name, message;
	Staff* next;
};

#endif