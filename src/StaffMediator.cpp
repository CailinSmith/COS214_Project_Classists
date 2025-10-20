#include "StaffMediator.h"

void StaffMediator::notify(Staff* originator) {
    for (auto colleague : colleagues) 
        if (colleague != originator) 
            colleague->receive(originator->getName() + ": " + originator->getMessage());
}