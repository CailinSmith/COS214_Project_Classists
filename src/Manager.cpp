#include "Manager.h"

Manager::Manager(string name) : Staff(name), receiver(nullptr) {}

void Manager::send() {
    for (auto mediator : mediators) 
        if (!receiver) 
            mediator->notify(this);
        else if (mediator == receiver)
            mediator->notify(this);
}

void Manager::handleRequest() {
	// TODO - implement Manager::handleRequest
	std::cout << "Manager: " << name << " handled request.\n";
	if(next)
		next->handleRequest();
}

string Manager::getPosition() {
    return "Manager";
}

void Manager::setReceiver(StaffMediator* mediator) {
    receiver = mediator;
}