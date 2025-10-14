#ifndef INVENTORYMANAGER_H
#define INVENTORYMANAGER_H

#include "Aggregate.h"
#include "Subject.h"
#include "Plant.h"
#include "Staff.h"
#include <vector>
#include <string>
#include <iostream>

class InventoryManager : public Aggregate, public Subject {

private:
	vector<Plant*> forSale;
	vector<Staff*> observerList;

public:
	// InventoryManager* getInstance();

	void addToSale(Plant* plant);

	void addToNursery(Plant* plant);

	void removeFromNursery(Plant* plant);

	void removeFromSale(Plant* plant);

	void notifyStaff(string message);
};

#endif
