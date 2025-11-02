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
#include <map>


class Staff;
using namespace std;

/**
 * @class InventoryManager
 * @author Alex Lange
 * @author Edwin Kusel
 * @author Jordan Naidoo
 * @author Cailin Smith
 * @brief
 * Design Pattern: Iterator, Observer
 * Participant: Concrete Aggregate, Concrete Subject
 * 
 * This class manages the plant inventory for both sale and nursery areas. It implements
 * the Aggregate interface to provide iterators for traversing plants by season, and the
 * Subject interface to notify staff observers when inventory thresholds are reached.
 * 
 * @see Aggregate
 * @see Subject
 * @see Plant
 */
class InventoryManager : public Aggregate, public Subject {

private:
	vector<Plant*> forSale;
	vector<Staff*> observerList;
	vector<Plant*> inNursery;
	map<string, int> priority = {
		{"Flower", 0},
		{"Herb", 1},
		{"Fruit", 2},
		{"Vegetable", 3},
		{"Succulent", 4},
		{"Aquatic", 5},
		{"Indoor", 6},
		{"Medicinal", 7}
	};
	size_t saleThreshold = 5;
	size_t nurseryThreshold = 5;

	/**
	 * @brief Checks inventory levels and notifies observers if thresholds are exceeded
	 */
	void checkAndNotify();

public:

	/**
	 * @brief Default constructor
	 */
	InventoryManager() = default;
	
	/**
	 * @brief Destructor
	 */
	virtual ~InventoryManager();

	/**
	 * @brief Creates an iterator for traversing plants by season
	 * @param season The season string to filter plants by
	 * @return Pointer to a new Iterator object
	 */
	virtual Iterator<Plant>* createIterator(const std::string& season) override;
	
	/**
	 * @brief Creates an iterator for traversing sale plants by season
	 * @param season The season string to filter plants by
	 * @return Pointer to a new Iterator object for sale plants
	 */
	Iterator<Plant>* createSaleIterator(const std::string& season);
	
	/**
	 * @brief Creates an iterator for traversing nursery plants by season
	 * @param season The season string to filter plants by
	 * @return Pointer to a new Iterator object for nursery plants
	 */
	Iterator<Plant>* createNurseryIterator(const std::string& season);

	/**
	 * @brief Adds a plant to the sale inventory
	 * @param plant Pointer to the plant to add
	 */
	void addToSale(Plant* plant);
	
	/**
	 * @brief Adds a plant to the nursery inventory
	 * @param plant Pointer to the plant to add
	 */
	void addToNursery(Plant* plant);
	
	/**
	 * @brief Removes a plant from the nursery inventory
	 * @param plant Pointer to the plant to remove
	 */
	void removeFromNursery(Plant* plant);
	
	/**
	 * @brief Removes a plant from the sale inventory
	 * @param plant Pointer to the plant to remove
	 */
	void removeFromSale(Plant* plant);

	/**
	 * @brief Notifies all registered staff observers with a message
	 * @param message The notification message to send
	 */
	void notifyStaff(string message) override;

	/**
	 * @brief Registers a staff member as an observer
	 * @param staff Pointer to the staff member to register
	 */
	void registerObserver(Staff* staff);
	
	/**
	 * @brief Deregisters a staff member as an observer
	 * @param staff Pointer to the staff member to deregister
	 */
	void deregisterObserver(Staff* staff);

	/**
	 * @brief Gets the count of plants available for sale
	 * @return The number of plants in the sale inventory
	 */
	size_t getSaleCount() const;
	
	/**
	 * @brief Gets the count of plants in the nursery
	 * @return The number of plants in the nursery inventory
	 */
	size_t getNurseryCount() const;
	
	/**
	 * @brief Checks if a plant is in the sale inventory
	 * @param plant Pointer to the plant to check
	 * @return true if the plant is in sale inventory, false otherwise
	 */
	bool isInSale(Plant* plant) const;
	
	/**
	 * @brief Checks if a plant is in the nursery inventory
	 * @param plant Pointer to the plant to check
	 * @return true if the plant is in nursery inventory, false otherwise
	 */
	bool isInNursery(Plant* plant) const;

	/**
	 * @brief Gets the vector of plants available for sale
	 * @return Const reference to the forSale vector
	 */
	const vector<Plant*>& getForSalePlants() const { return forSale; }
	
	/**
	 * @brief Gets the vector of plants in the nursery
	 * @return Const reference to the inNursery vector
	 */
	const vector<Plant*>& getNurseryPlants() const { return inNursery; }

	/**
	 * @brief Populates the inventory with demo plants for testing
	 * @param nurseryCount Number of plants to add to the nursery
	 * @param saleCount Number of plants to add to the sale inventory
	 */
	void populateDemoInventory(size_t nurseryCount, size_t saleCount);

	/**
	 * @brief Sets the threshold for sale inventory notifications
	 * @param t The new threshold value
	 */
	void setSaleThreshold(size_t t) { saleThreshold = t; }
	
	/**
	 * @brief Sets the threshold for nursery inventory notifications
	 * @param t The new threshold value
	 */
	void setNurseryThreshold(size_t t) { nurseryThreshold = t; }

};

#endif
