#include "Manager.h"
#include "Customer.h"
#include "Receipt.h"

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

        std::vector<Product*> remaining;
        // use current nursery season so decorators and seasonal costs are applied
        Nursery* nursery = Nursery::getInstance();
        std::string season = "";
        if (nursery) season = nursery->getSeason();

        for (size_t i = 0; i < order->size(); ++i) {
            Product* p = (*order)[i];
            if (p == nullptr) continue;
            if ((*flags)[i]) {
                total += p->calculateCost(season);
                ss << p->getName() << " ";
            } else {
                remaining.push_back(p);
            }
        }
        ss << total;
        result.first = ss.str();

        result.second = new Receipt(remaining);

        //return refunded items back to the nursery inventory (not for sale).
        if (nursery) {
            InventoryManager* im = nursery->getInventoryManager();
            if (im) {
                for (size_t i = 0; i < order->size(); ++i) {
                    if ((*flags)[i]) {
                        Product* p = (*order)[i];
                        if (!p) continue;
                        Plant* plantPtr = p->getBasePlant();
                        if (plantPtr && !im->isInNursery(plantPtr)) {
                            im->addToNursery(plantPtr);
                        }
                    }
                }
            }
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
    receive(message);
}