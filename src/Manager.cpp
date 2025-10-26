#include "Manager.h"
#include "Customer.h"

Manager::Manager(string name) : Staff(name), receiver(nullptr) {}

void Manager::send() {
    for (auto mediator : mediators) 
        if (!receiver) 
            mediator->notify(this);
        else if (mediator == receiver)
            mediator->notify(this);
}

string Manager::handleRequest(Customer* customer, const std::string& requestType, Plant* plant, std::vector<Product*>* order) {
	// TODO - implement Manager::handleRequest
    cout << getName() << " (" << getPosition() << ") received a notification from inventory" << endl;
    send();
    if(next){
        cout << "Manager passed on request:\n";
        return next->handleRequest(customer, requestType, plant, order);
    }
    return "Manager cannot handle'" + requestType + "'\n";
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