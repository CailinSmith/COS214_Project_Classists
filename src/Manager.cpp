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
    cout << getName() << " (" << getPosition() << ") received a notification from inventory" << endl;
    // Forward the request to staff connected through mediators not sure, so just check if this is the intended behavior.
    send();
}

string Manager::getPosition() {
    return "Manager";
}

void Manager::setReceiver(StaffMediator* mediator) {
    receiver = mediator;
}

void Manager::update(const string& message) {
    cout << getName() << " (" << getPosition() << ") received observer update: " << message << endl;
    send();
}