#ifndef STAFFMEDIATOR_H
#define STAFFMEDIATOR_H

#include <string>
#include <vector>
#include "Staff.h"

using namespace std;

/**
 * @class StaffMediator
 * @author Edwin Kusel
 * 
 * @brief
 * Design pattern: Mediator
 * Participant: Mediator
 * 
 * This class is the mediator interface for communication between Staff objects.
 * 
 * @see Staff
 */
class StaffMediator {
public:
    /**
     * @brief Destructor.
     */
    virtual ~StaffMediator() = default;
    /**
     * @brief Notifies colleagues of a message from an originator.
     * @param originator The staff member sending the message.
     */
    virtual void notify(Staff* originator) = 0;
    /**
     * @brief Registers a colleague with the mediator.
     * @param colleague The staff member to register.
     */
    virtual void registerColleague(Staff* colleague) = 0;
    /**
     * @brief Unregisters a colleague from the mediator.
     * @param colleague The staff member to unregister.
     */
    virtual void unregisterColleague(Staff* colleague) = 0;
protected:
    /**
     * @brief A list of colleagues registered with the mediator.
     */
    vector<Staff*> colleagues;
};

#endif