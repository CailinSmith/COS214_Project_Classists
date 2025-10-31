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
#include "Fertaliser.h"
#include "SalesArea.h"
#include "NurseryArea.h"

#include "Staff.h"

class NurseryFacade {
public:
    NurseryFacade(InventoryManager* mgr = nullptr);
    ~NurseryFacade();

    //launches background threads and runs the blocking
    void start(); //blocking main menu
    //stop() signals threads to terminate and joins them.
    void stop();
    void setTickInterval(std::chrono::milliseconds ms) { tickInterval_ = ms; }
    void listSaleCategories();
    void listPlantsInCategory(const std::string &category);
    size_t getStockCountByName(const std::string &name);

private:
    //interactive menu loops (blocking while entered)
    void runMainMenu();
    void runCustomerMenu();
    void runStaffMenu();

    //background worker threads
    void tickLoop();                //periodic plant updates
    void automatedCustomerLoop();   //simulated customers
    void automatedStaffLoop();      //simulated staff
    void runSettings();             //interactive settings menu

    //menu helpers (small convenience wrappers)
    void listSalePlants();
    void viewPlantInfo(size_t index);
    Plant* pickSalePlant(size_t index);
    void performCheckout();
    void decorateProductMenu(size_t orderIndex);

    /*
    core subsystems used by the facade. The facade owns these by default
    and will delete them in its destructor unless the ownership policy is
    changed outside this file.
    */
    InventoryManager* manager_ = nullptr;
    Nursery* nursery_ = nullptr;
    //Shared mediators for staff areas (persist across staff sessions)
    SalesArea* salesArea_ = nullptr;
    NurseryArea* nurseryArea_ = nullptr;
    //Pre-created staff instances (persist for facade lifetime)
    Staff* managerStaff_ = nullptr;
    Staff* salesStaff_ = nullptr;
    Staff* nurseryStaff_ = nullptr;

    //concurrency primitives
    std::atomic<bool> running_{false};
    std::mutex mtx_; //coarse-grained lock for demo safety
    std::condition_variable cv_;
    std::vector<std::thread> threads_;
    std::chrono::milliseconds tickInterval_{1000};

    //Simple per-session state kept by the demo
    std::vector<Product*> currentOrder_;   //pointers into manager or decorated wrappers
    std::vector<Receipt*> pastReceipts_;   //owned receipts (demo lifetime)
    std::vector<Product*> soldProducts_;   //facade takes ownership when items sold
};

#endif
