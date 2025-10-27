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

pair<string, Receipt*> Manager::handleRequest(const string& requestType, Plant* plant, vector<Product*>* order, vector<bool>* flags) {
    (void)plant; // Unused parameter
    pair<string, Receipt*> result;
    result.second = nullptr;

    if (requestType == "Refund" && order && flags && order->size() == flags->size()) {
        float total = 0.0f;
        std::stringstream ss;
        std::vector<size_t> toRemove;

        for (size_t i = 0; i < order->size(); ++i) {
            if ((*flags)[i] && (*order)[i]) {
                Product* p = (*order)[i];
                total += p->calculateCost(Nursery::getInstance()->getSeason());
                ss << p->getName() << " ";
                toRemove.push_back(i);
            }
        }
        ss << total;
        result.first = ss.str();

        for (auto it = toRemove.rbegin(); it != toRemove.rend(); ++it) {
            delete (*order)[*it];
            order->erase(order->begin() + *it);
        }
        return result;
    }
    return result;
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