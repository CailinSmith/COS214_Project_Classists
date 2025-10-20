#include "Manager.h"

Manager::Manager(string name) : Staff(name), receiver(nullptr) {}

void Manager::send() {
    for (auto mediator : mediators) 
        if (mediator == receiver)
            mediator->notify(this);
}

void Manager::handleRequest() {
	// TODO - implement Manager::handleRequest
	throw "Not yet implemented";
}

string Manager::getPosition() {
    return "Manager";
}

void Manager::setReceiver(StaffMediator* mediator) {
    receiver = mediator;
}