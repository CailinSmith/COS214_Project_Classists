#ifndef INVENTORY_H
#define INVENTORY_H

#include "Aggregate.h"
#include "Subject.h"
#include "Plant.h"
#include "Staff.h"
#include <vector>

class Inventory : public Aggregate, public Subject {

private:
	vector<Plant*> forSale;
	vector<Staff*> observerList;

public:
	Inventory* getInstance();

	void addToSale(Plant* plant);

	void addToNursery(Plant* plant);

	void removeFromNursery(Plant* plant);

	void removeFromSale(Plant* plant);

	void notifyStaff(string message);
};

#endif
