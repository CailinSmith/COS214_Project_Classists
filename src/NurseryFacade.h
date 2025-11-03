#ifndef NURSERYFACADE_H
#define NURSERYFACADE_H

#include <thread>
#include <mutex>
#include <condition_variable>
#include <atomic>
#include <chrono>
#include <vector>
#include <string>

#include "InventoryManager.h"
#include "Nursery.h"
#include "Plant.h"
#include "Receipt.h"
#include "Decorator.h"
#include "KraftWrapping.h"
#include "ConcretePot.h"
#include "ClayPot.h"
#include "CeramicPot.h"
#include "ExtraFertilizer.h"
#include "SalesArea.h"
#include "NurseryArea.h"

#include "Staff.h"

/**
 * @class NurseryFacade
 * @author Cailin Smith
 * @brief Simplified interface for interacting with the nursery management system.
 * Design Pattern: Facade
 * Participant: Facade
 * 
 * This class provides a unified, high-level interface to the complex subsystems
 * of the nursery management system. It coordinates interactions between the
 * InventoryManager, Nursery, Staff members, and customer operations. The facade
 * manages background threads for automated plant care and customer simulations,
 * and provides interactive menus for both customer and staff interactions.
 * 
 * The facade handles:
 * - Customer browsing, ordering, and checkout operations
 * - Staff plant care, inventory management, and notifications
 * - Background plant health updates and state transitions
 * - Concurrent access to shared resources via mutex protection
 * - Receipt management and refund processing
 * 
 * @see InventoryManager
 * @see Nursery
 * @see Staff
 * @see Receipt
 */
class NurseryFacade {
public:
    /**
     * @brief Constructs a NurseryFacade with an inventory manager.
     * @param mgr Pointer to an existing InventoryManager, or nullptr to create a new one.
     * 
     * Initializes all subsystems including the nursery, staff areas (sales and nursery),
     * and pre-creates staff instances (manager, sales staff, nursery staff). Sets up
     * the mediator pattern connections and chain of responsibility for staff.
     */
    NurseryFacade(InventoryManager* mgr = nullptr);
    
    /**
     * @brief Destructor for the NurseryFacade.
     * 
     * Stops all background threads, cleans up receipts and orders, unregisters
     * staff from areas, and destroys all owned subsystems.
     */
    ~NurseryFacade();

    /**
     * @brief Launches background threads and runs the blocking main menu.
     * 
     * This method spawns worker threads for plant updates and automated staff actions,
     * populates demo inventory if needed, and enters the interactive main menu loop.
     * It blocks until the user exits or stop() is called.
     */
    void start();
    
    /**
     * @brief Signals threads to terminate and joins them.
     * 
     * Atomically sets running flag to false, notifies waiting threads, and joins
     * all background worker threads. Safe to call multiple times.
     */
    void stop();
    
    /**
     * @brief Sets the tick interval for background plant updates.
     * @param tps Ticks per second.
     */
    void setTickInterval(std::chrono::milliseconds tps) { tickInterval_ = tps; }
    
    /**
     * @brief Lists all plant categories available for sale with counts.
     * 
     * Groups sale plants by category and displays how many plants are in each category.
     */
    void listSaleCategories();
    
    /**
     * @brief Lists all plants in a specific category.
     * @param category The category name to filter plants by.
     */
    void listPlantsInCategory(const std::string &category);
    
    /**
     * @brief Lists all plants matching the current season.
     * @param customerView If true, shows only sale plants; if false, shows all plants.
     * 
     * Uses the Iterator pattern to traverse seasonal plants from the inventory manager.
     */
    void listSeasonalPlants(bool customerView = false);
    
    /**
     * @brief Gets the stock count for a specific plant by name.
     * @param name The name of the plant to count.
     * @return size_t The number of plants with that name currently for sale.
     */
    size_t getStockCountByName(const std::string &name);

private:
    /**
     * @brief Runs the main interactive menu (blocking).
     * 
     * Displays the primary menu allowing users to choose between customer mode,
     * staff mode, settings, or exit. Loops until user exits.
     */
    void runMainMenu();
    
    /**
     * @brief Runs the customer interactive menu (blocking).
     * 
     * Provides customer-facing operations: browsing plants, viewing categories,
     * checking seasonal plants, managing orders, checkout, and viewing receipts.
     */
    void runCustomerMenu();
    
    /**
     * @brief Runs the staff interactive menu (blocking).
     * 
     * Provides staff-facing operations: viewing plants, caring for plants,
     * managing inventory, sending notifications, and switching staff roles.
     */
    void runStaffMenu();

    /**
     * @brief Background worker thread for periodic plant updates.
     * 
     * Periodically updates plant health and checks if nursery plants have reached
     * the ReadyForSale state to move them to the sale list.
     */
    void tickLoop();
    
    /**
     * @brief Background worker thread for simulated customer purchases.
     * 
     * Randomly selects plants from sale and simulates customer purchases.
     */
    void automatedCustomerLoop();
    
    /**
     * @brief Background worker thread for simulated staff plant care.
     * 
     * Cycles through nursery plants, performs watering, fertilizing, and pruning,
     * and moves ready plants to sale.
     */
    void automatedStaffLoop();
    
    /**
     * @brief Runs the interactive settings menu (blocking).
     * 
     * Allows configuration of tick interval and manual season changes.
     */
    void runSettings();

    /**
     * @brief Lists all plants currently for sale with interactive options.
     * 
     * Displays sale plants and provides options to view info, check stock,
     * or add plants to the current order.
     */
    void listSalePlants();
    
    /**
     * @brief Views detailed information about a specific plant.
     * @param index The 1-based index of the plant in the sale list.
     */
    void viewPlantInfo(size_t index);
    
    /**
     * @brief Picks a sale plant by index.
     * @param index The 1-based index of the plant in the sale list.
     * @return Plant* Pointer to the selected plant, or nullptr if invalid index.
     */
    Plant* pickSalePlant(size_t index);
    
    /**
     * @brief Performs the checkout process for the current order.
     * 
     * Prompts for decorations on each plant, creates a checkout command,
     * generates a receipt, and clears the current order.
     */
    void performCheckout();
    
    /**
     * @brief Interactive menu to decorate a product in the current order.
     * @param orderIndex The index of the product in currentOrder_ to decorate.
     * 
     * Prompts user to choose decorations (pots, wrapping, fertilizer) and
     * wraps the product with the selected decorator.
     */
    void decorateProductMenu(size_t orderIndex);

    /**
     * @brief Pointer to the inventory manager subsystem.
     * 
     * Manages all plant inventory including nursery and sale plants.
     * Owned and deleted by the facade.
     */
    InventoryManager* manager_ = nullptr;
    
    /**
     * @brief Pointer to the nursery singleton.
     * 
     * Manages seasonal state and plant factories.
     */
    Nursery* nursery_ = nullptr;
    
    /**
     * @brief Pointer to the sales area mediator.
     * 
     * Facilitates communication between staff in the sales area.
     */
    SalesArea* salesArea_ = nullptr;
    
    /**
     * @brief Pointer to the nursery area mediator.
     * 
     * Facilitates communication between staff in the nursery area.
     */
    NurseryArea* nurseryArea_ = nullptr;
    
    /**
     * @brief Pointer to the manager staff instance.
     * 
     * Pre-created staff member with manager privileges.
     */
    Staff* managerStaff_ = nullptr;
    
    /**
     * @brief Pointer to the sales staff instance.
     * 
     * Pre-created staff member for sales operations.
     */
    Staff* salesStaff_ = nullptr;
    
    /**
     * @brief Pointer to the nursery staff instance.
     * 
     * Pre-created staff member for nursery operations.
     */
    Staff* nurseryStaff_ = nullptr;

    /**
     * @brief Atomic flag indicating whether the facade is running.
     * 
     * Used to coordinate thread shutdown across multiple workers.
     */
    std::atomic<bool> running_{false};
    
    /**
     * @brief Mutex for protecting shared state access.
     * 
     * Coarse-grained lock used to ensure thread-safe access to manager and orders.
     */
    std::mutex mtx_;
    
    /**
     * @brief Condition variable for thread synchronization.
     */
    std::condition_variable cv_;
    
    /**
     * @brief Vector of background worker threads.
     * 
     * Holds handles to tickLoop, automatedCustomerLoop, and automatedStaffLoop threads.
     */
    std::vector<std::thread> threads_;
    
    /**
     * @brief Tick interval for background plant updates.
     * 
     * Default is 1000tps between plant state updates.
     */
    std::chrono::milliseconds tickInterval_{1000};

    /**
     * @brief Current customer order (products not yet checked out).
     * 
     * Contains pointers to plants from manager or decorated wrappers.
     */
    std::vector<Product*> currentOrder_;
    
    /**
     * @brief Past receipts from completed checkouts.
     * 
     * Facade owns these receipts and deletes them in destructor.
     */
    std::vector<Receipt*> pastReceipts_;
    
    /**
     * @brief Products that have been sold.
     * 
     * Facade takes ownership when items are sold.
     */
    std::vector<Product*> soldProducts_;
};

#endif
