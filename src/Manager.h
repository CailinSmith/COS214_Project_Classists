#ifndef MANAGER_H
#define MANAGER_H

#include "Staff.h"
#include "StaffMediator.h"
#include "Nursery.h"

#include <string>
#include <sstream>

using namespace std;

class Manager : public Staff {
public:
    Manager(string name);
    virtual void send() override;
    virtual pair<string, Receipt*> handleRequest(const string& requestType, Plant* plant, vector<Product*>* order, vector<bool>* flags) override;
	virtual string getPosition() override;
    void setReceiver(StaffMediator* mediator);
    virtual void update(const string& message);
private:
    StaffMediator* receiver;
};

#endif