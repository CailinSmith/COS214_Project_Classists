#include "doctest.h"
#include "../src/InventoryManager.h"
#include "../src/Plant.h"
#include "../src/Rose.h"
#include "../src/Sunflower.h"
#include "../src/Tomato.h"

TEST_CASE("InventoryManager - Constructor and Initial State") {
    InventoryManager* manager = new InventoryManager();
    
    CHECK(manager != nullptr);
    CHECK(manager->getSaleCount() == 0);
    CHECK(manager->getNurseryCount() == 0);
    
    delete manager;
}

TEST_CASE("InventoryManager - Add Plants to Nursery") {
    InventoryManager* manager = new InventoryManager();
    
    Plant* rose = new Rose();
    Plant* sunflower = new Sunflower();
    
    SUBCASE("Add valid plants to nursery") {
        CHECK_NOTHROW(manager->addToNursery(rose));
        CHECK(manager->getNurseryCount() == 1);
        CHECK(manager->isInNursery(rose));
        CHECK_FALSE(manager->isInSale(rose));
        
        CHECK_NOTHROW(manager->addToNursery(sunflower));
        CHECK(manager->getNurseryCount() == 2);
        CHECK(manager->isInNursery(sunflower));
    }
    
    SUBCASE("Add null plant to nursery") {
        CHECK_NOTHROW(manager->addToNursery(nullptr));
        CHECK(manager->getNurseryCount() == 0);
    }
    
    SUBCASE("Add same plant multiple times") {
        manager->addToNursery(rose);
        manager->addToNursery(rose);
        CHECK(manager->getNurseryCount() == 2);
    }
    
    delete rose;
    delete sunflower;
    delete manager;
}

TEST_CASE("InventoryManager - Add Plants to Sale") {
    InventoryManager* manager = new InventoryManager();
    
    Plant* tomato = new Tomato();
    Plant* rose = new Rose();
    
    SUBCASE("Add valid plants to sale") {
        CHECK_NOTHROW(manager->addToSale(tomato));
        CHECK(manager->getSaleCount() == 1);
        CHECK(manager->isInSale(tomato));
        CHECK_FALSE(manager->isInNursery(tomato));
        
        CHECK_NOTHROW(manager->addToSale(rose));
        CHECK(manager->getSaleCount() == 2);
        CHECK(manager->isInSale(rose));
    }
    
    SUBCASE("Add null plant to sale") {
        CHECK_NOTHROW(manager->addToSale(nullptr));
        CHECK(manager->getSaleCount() == 0);
    }
    
    SUBCASE("Add same plant multiple times") {
        manager->addToSale(tomato);
        manager->addToSale(tomato);
        CHECK(manager->getSaleCount() == 2);
    }
    
    delete tomato;
    delete rose;
    delete manager;
}

TEST_CASE("InventoryManager - Remove Plants from Nursery") {
    InventoryManager* manager = new InventoryManager();
    
    Plant* rose = new Rose();
    Plant* sunflower = new Sunflower();
    Plant* tomato = new Tomato();
    
    manager->addToNursery(rose);
    manager->addToNursery(sunflower);
    manager->addToNursery(tomato);
    
    SUBCASE("Remove existing plant from nursery") {
        CHECK(manager->getNurseryCount() == 3);
        CHECK_NOTHROW(manager->removeFromNursery(sunflower));
        CHECK(manager->getNurseryCount() == 2);
        CHECK_FALSE(manager->isInNursery(sunflower));
        CHECK(manager->isInNursery(rose));
        CHECK(manager->isInNursery(tomato));
    }
    
    SUBCASE("Remove non-existing plant from nursery") {
        Plant* notInNursery = new Rose();
        CHECK_NOTHROW(manager->removeFromNursery(notInNursery));
        CHECK(manager->getNurseryCount() == 3);
        delete notInNursery;
    }
    
    SUBCASE("Remove null plant from nursery") {
        CHECK_NOTHROW(manager->removeFromNursery(nullptr));
        CHECK(manager->getNurseryCount() == 3);
    }
    
    SUBCASE("Remove all plants from nursery") {
        manager->removeFromNursery(rose);
        manager->removeFromNursery(sunflower);
        manager->removeFromNursery(tomato);
        CHECK(manager->getNurseryCount() == 0);
    }
    
    delete rose;
    delete sunflower;
    delete tomato;
    delete manager;
}

TEST_CASE("InventoryManager - Remove Plants from Sale") {
    InventoryManager* manager = new InventoryManager();
    
    Plant* rose = new Rose();
    Plant* sunflower = new Sunflower();
    Plant* tomato = new Tomato();
    
    manager->addToSale(rose);
    manager->addToSale(sunflower);
    manager->addToSale(tomato);
    
    SUBCASE("Remove existing plant from sale") {
        CHECK(manager->getSaleCount() == 3);
        CHECK_NOTHROW(manager->removeFromSale(sunflower));
        CHECK(manager->getSaleCount() == 2);
        CHECK_FALSE(manager->isInSale(sunflower));
        CHECK(manager->isInSale(rose));
        CHECK(manager->isInSale(tomato));
    }
    
    SUBCASE("Remove non-existing plant from sale") {
        Plant* notInSale = new Rose();
        CHECK_NOTHROW(manager->removeFromSale(notInSale));
        CHECK(manager->getSaleCount() == 3);
        delete notInSale;
    }
    
    SUBCASE("Remove null plant from sale") {
        CHECK_NOTHROW(manager->removeFromSale(nullptr));
        CHECK(manager->getSaleCount() == 3);
    }
    
    SUBCASE("Remove all plants from sale") {
        manager->removeFromSale(rose);
        manager->removeFromSale(sunflower);
        manager->removeFromSale(tomato);
        CHECK(manager->getSaleCount() == 0);
    }
    
    delete rose;
    delete sunflower;
    delete tomato;
    delete manager;
}

TEST_CASE("InventoryManager - Notification System") {
    InventoryManager* manager = new InventoryManager();
    
    SUBCASE("Notify staff with message") {
        CHECK_NOTHROW(manager->notifyStaff("Test message"));
        CHECK_NOTHROW(manager->notifyStaff(""));
        CHECK_NOTHROW(manager->notifyStaff("Plant added to inventory"));
    }
    
    delete manager;
}