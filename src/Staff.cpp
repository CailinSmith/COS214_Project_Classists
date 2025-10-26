#include "Staff.h"
#include "StaffMediator.h"

Staff::Staff(string name) : name(name), next(NULL) {}

Staff::~Staff(){}

string Staff::handleRequest(Customer* customer, const std::string& requestType, Plant* plant, std::vector<Product*>* order){
    if(next)
        next->handleRequest(customer, requestType, plant, order);
    else
        std::cout << "No staff member can handle this request: " << requestType << "\n";
}

void Staff::send(){
    for (auto mediator : mediators) 
        mediator->notify(this);
}

void Staff::receive(string message) {
    cout << getName() << " received message: " << message << endl;
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
