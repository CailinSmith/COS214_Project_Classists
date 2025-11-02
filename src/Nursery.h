#ifndef NURSERY_H
#define NURSERY_H

#include "SeasonState.h"
#include "PlantFactory.h"
#include "InventoryManager.h"
#include "Staff.h"
#include <string>
using namespace std;

// Forward declarations
class Spring;
class SpringFactory;

/**
 * @class Nursery
 * @author Cailin Smith
 * @author Edwin Kusel
 * @brief Central management system for the nursery operations.
 * Design Pattern: Singleton, State
 * Participant: Singleton, Context (State Pattern)
 * 
 * This class serves as the central control system for the nursery, managing the current
 * season state, plant factory, and inventory. It implements the Singleton pattern to ensure
 * only one nursery instance exists, and acts as the Context in the State pattern for
 * managing seasonal changes. The nursery coordinates season transitions, plant production,
 * and inventory management.
 * 
 * Usage:
 * First initialize:
 *   InventoryManager* inventoryManager = new InventoryManager();
 *   Nursery* nursery = Nursery::getInstance(inventoryManager);
 * 
 * To access inventory manager:
 *   InventoryManager* im = nursery->getInventoryManager();
 * 
 * To access the singleton:
 *   Nursery* n = Nursery::getInstance();
 * 
 * @see SeasonState
 * @see PlantFactory
 * @see InventoryManager
 */
class Nursery {

private:
	/**
	 * @brief Singleton instance of the Nursery
	 */
	static Nursery* instance;
	
	/**
	 * @brief Manages plant inventory
	 */
	InventoryManager* inventoryManager;
	
	/**
	 * @brief Current season state
	 */
	SeasonState* currentSeason;
	
	/**
	 * @brief Factory for creating seasonal plants
	 */
	PlantFactory* currentFactory;
	
protected:
	/**
	 * @brief Protected constructor to enforce Singleton pattern.
	 * @param manager Pointer to the InventoryManager for this nursery.
	 */
	Nursery(InventoryManager* manager);
	
	/**
	 * @brief Deleted copy constructor to prevent copying.
	 */
	Nursery(const Nursery&) = delete;
	
	/**
	 * @brief Deleted assignment operator to prevent assignment.
	 */
	Nursery& operator=(const Nursery&) = delete;
	
	/**
	 * @brief Protected destructor.
	 */
	~Nursery();

public:
	/**
	 * @brief Gets or creates the singleton Nursery instance.
	 * @param manager Optional InventoryManager pointer (required for first initialization).
	 * @return Nursery* Pointer to the singleton Nursery instance.
	 */
	static Nursery* getInstance(InventoryManager* manager = nullptr);
	
	/**
	 * @brief Destroys the singleton instance.
	 * 
	 * Safe to call at program/test teardown to clean up the singleton.
	 */
	static void destroyInstance();

	/**
	 * @brief Gets the inventory manager.
	 * @return InventoryManager* Pointer to the nursery's inventory manager.
	 */
	InventoryManager* getInventoryManager();
	
	/**
	 * @brief Clears the pointer to the inventory manager.
	 * 
	 * Used when the manager is destroyed externally to prevent dangling pointer.
	 */
	void clearInventoryManager();
	
	/**
	 * @brief Sets the current season state.
	 * @param season Pointer to the new SeasonState to set.
	 */
	void setSeason(SeasonState* season);

	/**
	 * @brief Gets the current season name.
	 * @return string The name of the current season.
	 */
	string getSeason();

	/**
	 * @brief Sets the plant factory for the current season.
	 * @param factory Pointer to the PlantFactory to use for creating plants.
	 */
	void setFactory(PlantFactory* factory);

	/**
	 * @brief Changes to the next season.
	 * 
	 * Called by client to transition to the next season. Delegates to currentSeason
	 * to handle the state transition.
	 */
	void changeSeason();

	/**
	 * @brief Stocks the nursery with seasonal plants.
	 * 
	 * Uses the current factory to create and add plants to inventory.
	 */
	void stockNursery();
};

#endif