#include "SalesArea.h"

void SalesArea::notify(Staff* originator) {
    for (auto colleague : colleagues) 
        if (colleague != originator) 
            colleague->receive("Sales Area: " + originator->getName() + ": " + originator->getMessage());
}

void SalesArea::registerColleague(Staff* colleague) {
    if (colleague && (colleague->getPosition() == "Sales staff" || colleague->getPosition() == "Manager")) {
        colleagues.push_back(colleague);
        colleague->registerMediator(this);
    }
}

void SalesArea::unregisterColleague(Staff* colleague) {
    colleagues.erase(std::remove(colleagues.begin(), colleagues.end(), colleague), colleagues.end());
    if (colleague) colleague->deregisterMediator(this);
}