#include "NurseryArea.h"

void NurseryArea::notify(Staff* originator) {
    for (auto colleague : colleagues) 
        if (colleague != originator) 
            colleague->receive("NurseryArea: " + originator->getName() + ":" + originator->getMessage());
}

void NurseryArea::registerColleague(Staff* colleague) {
    if (colleague && (colleague->getPosition() == "Nursery staff" || colleague->getPosition() == "Manager" )) {
        colleagues.push_back(colleague);
        colleague->registerMediator(this);
    }
}