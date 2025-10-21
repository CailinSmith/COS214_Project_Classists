#include "SalesArea.h"

void SalesArea::notify(Staff* originator) {
    for (auto colleague : colleagues) 
        if (colleague != originator) 
            colleague->receive("NurseryArea: " + originator->getName() + ":" + originator->getMessage());
}

void SalesArea::registerColleague(Staff* colleague) {
    if (colleague && (colleague->getPosition() == "Sales staff" || colleague->getPosition() == "Manager")) {
        colleagues.push_back(colleague);
        colleague->registerMediator(this);
    }
}