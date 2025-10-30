#include "Staff.h"
#include "StaffMediator.h"
#include "StaffCommand.h"

Staff::Staff(string name) : name(name), next(NULL), command(nullptr) {}

Staff::~Staff() {
    if (command) {
        delete command;
        command = nullptr;
    }
}

pair<string, Receipt*> Staff::handleRequest(const std::string& requestType, Plant* plant, std::vector<Product*>* order, vector<bool>* flags){
    if(next)
        return next->handleRequest(requestType, plant, order, flags);
    else {
        std::cout << "No staff member can handle this request: " << requestType << "\n";
        pair<string, Receipt*> res;
        res.first = std::string("No staff member can handle this request: ") + requestType;
        res.second = nullptr;
        return res;
    }
}

void Staff::setCommand(StaffCommand* cmd) {
    if (cmd)
        delete command; 
    command = cmd;
}

void Staff::send(){
    for (auto mediator : mediators) 
        mediator->notify(this);
}

string Staff::receive(string message) {
    return getName() + " received message: " + message + "\n";
}

string Staff::getMessage() {
    return message;
}

void Staff::setMessage(string message) {
    this->message = message;
}

void Staff::setNext(Staff* nextStaff){
    next = nextStaff;
}

string Staff::getName() {
	return name;
}

void Staff::registerMediator(StaffMediator* mediator) {
    if (mediator) 
        mediators.push_back(mediator);
}

void Staff::deregisterMediator(StaffMediator* mediator) {
    mediators.erase(remove(mediators.begin(), mediators.end(), mediator), mediators.end());
}