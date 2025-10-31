#ifndef STAFF_H
#define STAFF_H

#include <string>
#include <vector>
#include <utility>
#include <iostream>
#include <algorithm>
#include "Plant.h"
#include "Receipt.h"

class StaffMediator;
class Customer;
class StaffCommand;

using namespace std;

class Staff {
public:
    Staff(string name);
    virtual ~Staff();
	virtual void send();
	string receive(string message);
	virtual pair<string, Receipt*> handleRequest(const std::string& requestType, Plant* plant, std::vector<Product*>* order, vector<bool>* flags);
    void setCommand(StaffCommand* cmd);
	virtual string getPosition() = 0;
    string getMessage();
    void setMessage(string message);
	string getName();
    void setNext(Staff* nextStaff);
    void registerMediator(StaffMediator* mediator);
    void deregisterMediator(StaffMediator* mediator);
    virtual void update(const string& message);
protected:
    string name;
	Staff* next;
    vector<StaffMediator*> mediators;
    StaffCommand* command;
private:
	string message;
};

#endif