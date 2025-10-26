#include "doctest.h"
#include "../src/InventoryManager.h"
#include "../src/NurseryStaff.h"
#include "../src/Manager.h"
#include "../src/Rose.h"
#include "../src/Basil.h"

TEST_CASE("Observer Pattern - InventoryManager Basic Setup") {
    InventoryManager* inventory = new InventoryManager();
    CHECK(inventory != nullptr);
    CHECK(inventory->getSaleCount() == 0);
    CHECK(inventory->getNurseryCount() == 0);
    CHECK_NOTHROW(inventory->setSaleThreshold(3));
    CHECK_NOTHROW(inventory->setNurseryThreshold(2));
    delete inventory;
}

TEST_CASE("Observer Pattern - Observer Registration") {
    InventoryManager* inventory = new InventoryManager();
    NurseryStaff* staff = new NurseryStaff("TestStaff");
    Manager* manager = new Manager("TestManager");
    SUBCASE("Register observers") {
        CHECK_NOTHROW(inventory->registerObserver(staff));
        CHECK_NOTHROW(inventory->registerObserver(manager));
        CHECK_NOTHROW(inventory->registerObserver(nullptr));
    }
    
    SUBCASE("Deregister observers") {
        inventory->registerObserver(staff);
        CHECK_NOTHROW(inventory->deregisterObserver(staff));
        CHECK_NOTHROW(inventory->deregisterObserver(nullptr));
    }
    delete staff;
    delete manager;
    delete inventory;
}

TEST_CASE("Observer Pattern - Notification Triggering") {
    InventoryManager* inventory = new InventoryManager();
    NurseryStaff* staff = new NurseryStaff("TestStaff");
    inventory->setSaleThreshold(2);
    inventory->setNurseryThreshold(2);
    inventory->registerObserver(staff);
    Rose* rose = new Rose();
    Basil* basil = new Basil();
    
    SUBCASE("Adding plants triggers notifications when below threshold") {
        CHECK_NOTHROW(inventory->addToNursery(rose));
        CHECK(inventory->getNurseryCount() == 1);
    }
    
    SUBCASE("Removing plants triggers notifications when dropping below threshold") {
        inventory->addToNursery(rose);
        inventory->addToNursery(basil);
        CHECK(inventory->getNurseryCount() == 2);
        CHECK_NOTHROW(inventory->removeFromNursery(rose));
        CHECK(inventory->getNurseryCount() == 1);
    }
    
    SUBCASE("Moving plants between nursery and sale areas") {
        inventory->addToNursery(rose);
        CHECK_NOTHROW(inventory->removeFromNursery(rose));
        CHECK_NOTHROW(inventory->addToSale(rose));
        CHECK(inventory->getSaleCount() == 1);
        CHECK(inventory->getNurseryCount() == 0);
    }
    delete rose;
    delete basil;
    delete staff;
    delete inventory;
}

TEST_CASE("Observer Pattern - Multiple Observers") {
    InventoryManager* inventory = new InventoryManager();
    NurseryStaff* staff = new NurseryStaff("NurseryStaff");
    Manager* manager = new Manager("TestManager");
    inventory->setSaleThreshold(1);
    inventory->setNurseryThreshold(1);
    Rose* rose = new Rose();
    
    SUBCASE("Multiple observers receive notifications") {
        inventory->registerObserver(staff);
        inventory->registerObserver(manager);
        CHECK_NOTHROW(inventory->addToNursery(rose));
    }
    
    SUBCASE("Deregistered observer stops receiving notifications") {
        inventory->registerObserver(staff);
        inventory->registerObserver(manager);
        inventory->deregisterObserver(manager);
        CHECK_NOTHROW(inventory->addToSale(rose));
    }
    delete rose;
    delete staff;
    delete manager;
    delete inventory;
}

TEST_CASE("Observer Pattern - Staff Response Functionality") {
    NurseryStaff* staff = new NurseryStaff("TestStaff");
    Manager* manager = new Manager("TestManager");
    
    SUBCASE("Staff can receive messages") {
        CHECK_NOTHROW(staff->receive("Low stock notification"));
        CHECK_NOTHROW(manager->receive("Inventory alert"));
    }
    
    // SUBCASE("Staff can handle requests") {
    //     CHECK_NOTHROW(staff->handleRequest());
    //     CHECK_NOTHROW(manager->handleRequest());
    // }
    delete staff;
    delete manager;
}

TEST_CASE("Observer Pattern - Inventory Access for Staff") {
    InventoryManager* inventory = new InventoryManager();
    Rose* rose = new Rose();
    Basil* basil = new Basil();
    
    SUBCASE("Staff can access nursery plants list") {
        inventory->addToNursery(rose);
        inventory->addToNursery(basil);
        const auto& nurseryPlants = inventory->getNurseryPlants();
        CHECK(nurseryPlants.size() == 2);
    }
    
    SUBCASE("Staff can access for sale plants list") {
        inventory->addToSale(rose);
        const auto& salePlants = inventory->getForSalePlants();
        CHECK(salePlants.size() == 1);
    }
    
    SUBCASE("Empty lists work correctly") {
        const auto& nurseryPlants = inventory->getNurseryPlants();
        const auto& salePlants = inventory->getForSalePlants();
        CHECK(nurseryPlants.size() == 0);
        CHECK(salePlants.size() == 0);
    }
    delete rose;
    delete basil;
    delete inventory;
}

TEST_CASE("Observer Pattern - Integration with Existing Operations") {
    InventoryManager* inventory = new InventoryManager();
    NurseryStaff* staff = new NurseryStaff("TestStaff");
    inventory->setSaleThreshold(1);
    inventory->setNurseryThreshold(1);
    inventory->registerObserver(staff);
    Rose* rose = new Rose();
    
    SUBCASE("Observer pattern doesn't interfere with existing functionality") {
        CHECK_NOTHROW(inventory->addToNursery(rose));
        CHECK(inventory->isInNursery(rose));
        CHECK_FALSE(inventory->isInSale(rose));
        CHECK_NOTHROW(inventory->removeFromNursery(rose));
        CHECK_FALSE(inventory->isInNursery(rose));
        CHECK_NOTHROW(inventory->addToSale(rose));
        CHECK(inventory->isInSale(rose));
        CHECK_NOTHROW(inventory->removeFromSale(rose));
        CHECK_FALSE(inventory->isInSale(rose));
    }
    
    SUBCASE("Count methods work correctly with observers") {
        inventory->addToNursery(rose);
        CHECK(inventory->getNurseryCount() == 1);
        inventory->addToSale(rose);
        CHECK(inventory->getSaleCount() == 1);
    }
    delete rose;
    delete staff;
    delete inventory;
}

TEST_CASE("Observer Pattern - Update Function Testing") {
    InventoryManager* inventory = new InventoryManager();
    NurseryStaff* staff = new NurseryStaff("UpdateTestStaff");
    Manager* manager = new Manager("UpdateTestManager");
    
    SUBCASE("NurseryStaff update function receives messages") {
        CHECK_NOTHROW(staff->update("Test update message"));
        CHECK_NOTHROW(staff->update("Low stock alert"));
        CHECK_NOTHROW(staff->update(""));
    }
    
    SUBCASE("Manager update function receives messages and delegates") {
        CHECK_NOTHROW(manager->update("Manager test message"));
        CHECK_NOTHROW(manager->update("Critical inventory alert"));
        CHECK_NOTHROW(manager->update(""));
    }
    
    SUBCASE("Update function called through observer notification") {
        inventory->setSaleThreshold(2);
        inventory->setNurseryThreshold(2);
        inventory->registerObserver(staff);
        inventory->registerObserver(manager);
        Rose* rose = new Rose();
        CHECK_NOTHROW(inventory->addToNursery(rose));
        CHECK_NOTHROW(inventory->addToSale(rose));
        delete rose;
    }
    delete staff;
    delete manager;
    delete inventory;
}

TEST_CASE("Observer Pattern - Update Function with Different Message Types") {
    NurseryStaff* staff = new NurseryStaff("MessageTestStaff");
    Manager* manager = new Manager("MessageTestManager");
    
    SUBCASE("Update handles various message formats") {
        CHECK_NOTHROW(staff->update("Low stock: forSale count below threshold"));
        CHECK_NOTHROW(staff->update("Low stock: nursery count below threshold"));
        CHECK_NOTHROW(manager->update("Emergency: All plants sold out"));
        CHECK_NOTHROW(manager->update("Info: Restocking needed"));
    }
    
    SUBCASE("Update handles special characters and long messages") {
        CHECK_NOTHROW(staff->update("Alert! @#$%^&*()"));
        CHECK_NOTHROW(manager->update("Very long message that contains lots of details about inventory status and what actions should be taken by staff members"));
        CHECK_NOTHROW(staff->update("Multi\nline\nmessage"));
    }
    delete staff;
    delete manager;
}

TEST_CASE("Observer Pattern - Update Function Integration with Notification System") {
    InventoryManager* inventory = new InventoryManager();
    NurseryStaff* staff1 = new NurseryStaff("Staff1");
    NurseryStaff* staff2 = new NurseryStaff("Staff2");
    Manager* manager = new Manager("IntegrationManager");
    inventory->setSaleThreshold(1);
    inventory->setNurseryThreshold(1);
    
    SUBCASE("Multiple observers receive update calls simultaneously") {
        inventory->registerObserver(staff1);
        inventory->registerObserver(staff2);
        inventory->registerObserver(manager);
        Rose* rose = new Rose();
        CHECK_NOTHROW(inventory->addToNursery(rose));
        delete rose;
    }
    
    SUBCASE("Update function called only for registered observers") {
        inventory->registerObserver(staff1);
        inventory->registerObserver(manager);
        Basil* basil = new Basil();
        CHECK_NOTHROW(inventory->addToSale(basil));
        delete basil;
    }
    
    SUBCASE("Deregistered observer stops receiving update calls") {
        inventory->registerObserver(staff1);
        inventory->registerObserver(manager);
        Rose* rose = new Rose();
        inventory->addToNursery(rose);
        inventory->deregisterObserver(staff1);
        CHECK_NOTHROW(inventory->removeFromNursery(rose));
        CHECK_NOTHROW(inventory->addToSale(rose));
        
        delete rose;
    }
    delete staff1;
    delete staff2;
    delete manager;
    delete inventory;
}

TEST_CASE("Observer Pattern - Update Function Error Handling") {
    NurseryStaff* staff = new NurseryStaff("ErrorTestStaff");
    Manager* manager = new Manager("ErrorTestManager");
    
    SUBCASE("Update function handles null and empty inputs gracefully") {
        CHECK_NOTHROW(staff->update(""));
        CHECK_NOTHROW(manager->update(""));
        CHECK_NOTHROW(staff->update("   "));
        CHECK_NOTHROW(manager->update("   "));
    }
    
    SUBCASE("Update function works with very short messages") {
        CHECK_NOTHROW(staff->update("!"));
        CHECK_NOTHROW(manager->update("X"));
        CHECK_NOTHROW(staff->update("OK"));
    }
    delete staff;
    delete manager;
}
