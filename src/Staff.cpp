#include "Staff.h"
#include "StaffMediator.h"

Staff::Staff(string name) : name(name), next(NULL) {}

Staff::~Staff(){}

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
