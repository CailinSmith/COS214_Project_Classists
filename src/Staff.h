#ifndef STAFF_H
#define STAFF_H

#include <string>
#include <iostream>
using namespace std;
class Staff {
	protected:
		string name;
		Staff* next;

	public:
		Staff(const string& str);
		virtual ~Staff();
		virtual void send(string message, Staff* from) = 0;
		virtual void receive(string message) = 0;
		virtual void handleRequest() = 0;
		string getName();
		void setNext(Staff* nextStaff);
};

#endif
