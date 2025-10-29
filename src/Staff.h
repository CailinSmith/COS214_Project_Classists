#ifndef STAFF_H
#define STAFF_H

#include <string>
#include <vector>
#include <utility>
#include <iostream>
#include <algorithm>
#include <chrono>
#include <mutex>
#include "Plant.h"
#include "Receipt.h"

class StaffMediator;
class Customer;

using namespace std;

class Staff {
public:
    Staff(string name);
    virtual ~Staff();
	virtual void send();
	void receive(string message);
    std::string getChatHistoryString() const;
    void clearChatHistory();
	virtual pair<string, Receipt*> handleRequest(const std::string& requestType, Plant* plant, std::vector<Product*>* order, vector<bool>* flags);
	virtual string getPosition() = 0;
    string getMessage();
    void setMessage(string message);
	string getName();
    void setNext(Staff* nextStaff);
    void registerMediator(StaffMediator* mediator);
    void deregisterMediator(StaffMediator* mediator);
protected:
    string name;
	Staff* next;
    vector<StaffMediator*> mediators;
    //protected chat history storage (timestamp + message)
    mutable std::mutex chatMutex;
    std::vector<std::pair<std::chrono::system_clock::time_point, std::string>> chatHistory;
private:
	string message;
};

#endif