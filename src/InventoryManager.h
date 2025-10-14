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
	vector<Plant*> inNursery;

public:
	
	virtual ~InventoryManager() {
		// Don't delete plants, just clear vectors
		forSale.clear();
		inNursery.clear();
	}

	void addToSale(Plant* plant);

	void addToNursery(Plant* plant);

	void removeFromNursery(Plant* plant);

	void removeFromSale(Plant* plant);

	void notifyStaff(string message);
	

	size_t getSaleCount() const;
	size_t getNurseryCount() const;
	bool isInSale(Plant* plant) const;
	bool isInNursery(Plant* plant) const;
	
};

#endif
