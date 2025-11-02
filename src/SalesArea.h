#ifndef SALESAREA_H
#define SALESAREA_H

#include "StaffMediator.h"
#include "Staff.h"

#include <string>

using namespace std;

/**
 * @class SalesArea
 * @author Edwin Kusel
 * 
 * @brief
 * Design pattern: Mediator
 * Participant: ConcreteMediator
 * 
 * This class is a concrete mediator for the sales area.
 * 
 * @see StaffMediator
 */
class SalesArea : public StaffMediator {
public:
    /**
     * @brief Notifies colleagues in the sales area.
     * @param originator The staff member sending the notification.
     */
    virtual void notify(Staff* originator) override;
    /**
     * @brief Registers a colleague in the sales area.
     * @param colleague The staff member to register.
     */
    virtual void registerColleague(Staff* colleague) override;
    /**
     * @brief Unregisters a colleague from the sales area.
     * @param colleague The staff member to unregister.
     */
    virtual void unregisterColleague(Staff* colleague) override;
};

#endif