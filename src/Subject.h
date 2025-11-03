#ifndef SUBJECT_H
#define SUBJECT_H

#include <string>

/**
 * @class Subject
 * @author Edwin Kusel
 * 
 * @brief
 * Design pattern: Observer
 * Participant: Subject
 * 
 * This class represents the Subject in the Observer design pattern.
 * 
 * @see InventoryManager
 */
class Subject {
public:
    /**
     * @brief Notifies all staff observers of a message.
     * @param message The message to send to the observers.
     */
	virtual void notifyStaff(std::string message) = 0;
};

#endif
