#ifndef INVENTORYMANAGER_H
#define INVENTORYMANAGER_H

#include "Aggregate.h"
#include "Subject.h"
#include "Plant.h"
#include "SeasonIterator.h"
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>


class Staff;
using namespace std;

class InventoryManager : public Aggregate, public Subject {

private:
	vector<Plant*> forSale;
	vector<Staff*> observerList;
	vector<Plant*> inNursery;
	size_t saleThreshold = 2;
	size_t nurseryThreshold = 2;

	void checkAndNotify();

public:

	InventoryManager() = default;
	virtual ~InventoryManager() {
		// Don't delete plants, just clear vectors
		forSale.clear();
		inNursery.clear();
		observerList.clear();
	}

	virtual Iterator<Plant>* createIterator(const std::string& season) override;
	Iterator<Plant>* createSaleIterator(const std::string& season);
	Iterator<Plant>* createNurseryIterator(const std::string& season);

	void addToSale(Plant* plant);
	void addToNursery(Plant* plant);
	void removeFromNursery(Plant* plant);
	void removeFromSale(Plant* plant);

	void notifyStaff(string message) override;

	void registerObserver(Staff* staff);
	void deregisterObserver(Staff* staff);

	size_t getSaleCount() const;
	size_t getNurseryCount() const;
	bool isInSale(Plant* plant) const;
	bool isInNursery(Plant* plant) const;

	const vector<Plant*>& getForSalePlants() const { return forSale; }
	const vector<Plant*>& getNurseryPlants() const { return inNursery; }

	void setSaleThreshold(size_t t) { saleThreshold = t; }
	void setNurseryThreshold(size_t t) { nurseryThreshold = t; }

};

#endif
