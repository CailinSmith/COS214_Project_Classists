#ifndef MANAGER_H
#define MANAGER_H

#include "Staff.h"
#include "StaffMediator.h"

#include <string>

using namespace std;

class Manager : public Staff {
public:
    Manager(string name);
    virtual void send() override;
	virtual void handleRequest() override;
	virtual string getPosition() override;
    void setReceiver(StaffMediator* mediator);
    virtual void update(const string& message);
private:
    StaffMediator* receiver;
};

#endif