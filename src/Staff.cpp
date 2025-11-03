#include "Staff.h"
#include "StaffMediator.h"
#include "StaffCommand.h"
#include <chrono>
#include <iomanip>
#include <sstream>
#include <mutex>

Staff::Staff(string name) : name(name), next(NULL), command(nullptr) {}

Staff::~Staff() {
    if (command) {
        delete command;
        command = nullptr;
    }
}

pair<string, Receipt*> Staff::handleRequest(const std::string& requestType, Plant* plant, std::vector<Product*>* order, vector<bool>* flags){
    if(next)
        return next->handleRequest(requestType, plant, order, flags);
    else {
        std::cout << "No staff member can handle this request: " << requestType << "\n";
        pair<string, Receipt*> res;
        res.first = std::string("No staff member can handle this request: ") + requestType;
        res.second = nullptr;
        return res;
    }
}

void Staff::setCommand(StaffCommand* cmd) {
    if (cmd)
        delete command; 
    command = cmd;
}

void Staff::send(){
    for (auto mediator : mediators) 
        mediator->notify(this);
}

void Staff::receive(string message) {
    std::lock_guard<std::mutex> lk(chatMutex);
    chatHistory.emplace_back(std::chrono::system_clock::now(), message);
}

string Staff::getMessage() {
    return message;
}

void Staff::setMessage(string message) {
    this->message = message;
}

void Staff::setNext(Staff* nextStaff){
    next = nextStaff;
}

string Staff::getName() {
	return name;
}

void Staff::registerMediator(StaffMediator* mediator) {
    if (mediator) 
        mediators.push_back(mediator);
}

void Staff::deregisterMediator(StaffMediator* mediator) {
    mediators.erase(remove(mediators.begin(), mediators.end(), mediator), mediators.end());
}

void Staff::update(const string& message) {
    (void)message;
}

std::string Staff::getChatHistoryString() const {
    std::ostringstream out;
    std::lock_guard<std::mutex> lk(chatMutex);
    for (const auto &entry : chatHistory) {
        auto tp = entry.first;
        auto msg = entry.second;
        std::time_t t = std::chrono::system_clock::to_time_t(tp);
        std::tm tm = *std::localtime(&t);
        out << "\033[34m" << std::put_time(&tm, "%Y-%m-%d %H:%M:%S") << "\033[0m" << " - " << msg << "\n";
    }
    return out.str();
}

void Staff::clearChatHistory() {
    std::lock_guard<std::mutex> lk(chatMutex);
    chatHistory.clear();
}
