#include "doctest.h"
#include "../src/InventoryManager.h"
#include "../src/Plant.h"
#include "../src/Rose.h"
#include "../src/Sunflower.h"
#include "../src/Tomato.h"
#include "../src/Basil.h"
#include "../src/Lavender.h"
#include "../src/Thyme.h"
#include "../src/RubberTree.h"
#include "../src/Ginger.h"
#include "../src/Chamomile.h"
#include "../src/AppleTree.h"
#include "../src/OrangeTree.h"
#include "../src/Lettuce.h"
#include "../src/Pumpkin.h"
#include "../src/Cattails.h"
#include "../src/SnakePlant.h"
#include "../src/Chrysanthemum.h"
#include "../src/Pansy.h"

TEST_CASE("InventoryManager - Constructor and Initial State") {
    InventoryManager* manager = new InventoryManager();
    
    CHECK(manager != nullptr);
    CHECK(manager->getSaleCount() == 0);
    CHECK(manager->getNurseryCount() == 0);
    
    delete manager;
}

TEST_CASE("InventoryManager - Add Plants to Nursery") {
    InventoryManager* manager = new InventoryManager();
    
    SUBCASE("Add valid plants to nursery") {
        Plant* rose = new Rose();
        Plant* sunflower = new Sunflower();
        
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
        Plant* rose = new Rose();
        manager->addToNursery(rose);
        size_t countAfterFirst = manager->getNurseryCount();
        manager->addToNursery(rose);
        CHECK(manager->getNurseryCount() == countAfterFirst + 1);
        
        // WARNING: Adding same plant twice will cause double-delete in destructor
        // So we remove one instance before manager is deleted
        manager->removeFromNursery(rose);
    }
    
    delete manager;
}

TEST_CASE("InventoryManager - Add Plants to Sale") {
    InventoryManager* manager = new InventoryManager();
    
    SUBCASE("Add valid plants to sale") {
        Plant* tomato = new Tomato();
        Plant* rose = new Rose();
        
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
        Plant* tomato = new Tomato();
        manager->addToSale(tomato);
        size_t countAfterFirst = manager->getSaleCount();
        manager->addToSale(tomato);
        CHECK(manager->getSaleCount() == countAfterFirst + 1);
        
        manager->removeFromSale(tomato);
    }
    
    delete manager;
}

TEST_CASE("InventoryManager - Remove Plants from Nursery") {
    InventoryManager* manager = new InventoryManager();
    
    SUBCASE("Remove existing plant from nursery") {
        Plant* rose = new Rose();
        Plant* sunflower = new Sunflower();
        Plant* tomato = new Tomato();
        
        manager->addToNursery(rose);
        manager->addToNursery(sunflower);
        manager->addToNursery(tomato);
        
        CHECK(manager->getNurseryCount() == 3);
        CHECK_NOTHROW(manager->removeFromNursery(sunflower));
        CHECK(manager->getNurseryCount() == 2);
        CHECK_FALSE(manager->isInNursery(sunflower));
        CHECK(manager->isInNursery(rose));
        CHECK(manager->isInNursery(tomato));
        delete sunflower;
    }
    
    SUBCASE("Remove non-existing plant from nursery") {
        Plant* rose = new Rose();
        manager->addToNursery(rose);
        
        Plant* notInNursery = new Rose();
        CHECK_NOTHROW(manager->removeFromNursery(notInNursery));
        CHECK(manager->getNurseryCount() == 1);
        delete notInNursery;
    }
    
    SUBCASE("Remove null plant from nursery") {
        Plant* rose = new Rose();
        manager->addToNursery(rose);
        
        CHECK_NOTHROW(manager->removeFromNursery(nullptr));
        CHECK(manager->getNurseryCount() == 1);
    }
    
    SUBCASE("Remove all plants from nursery") {
        Plant* rose = new Rose();
        Plant* sunflower = new Sunflower();
        Plant* tomato = new Tomato();
        
        manager->addToNursery(rose);
        manager->addToNursery(sunflower);
        manager->addToNursery(tomato);
        
        manager->removeFromNursery(rose);
        manager->removeFromNursery(sunflower);
        manager->removeFromNursery(tomato);
        CHECK(manager->getNurseryCount() == 0);
        
        delete rose;
        delete sunflower;
        delete tomato;
    }
    
    delete manager;
}

TEST_CASE("InventoryManager - Remove Plants from Sale") {
    InventoryManager* manager = new InventoryManager();
    
    SUBCASE("Remove existing plant from sale") {
        Plant* rose = new Rose();
        Plant* sunflower = new Sunflower();
        Plant* tomato = new Tomato();
        
        manager->addToSale(rose);
        manager->addToSale(sunflower);
        manager->addToSale(tomato);
        
        CHECK(manager->getSaleCount() == 3);
        CHECK_NOTHROW(manager->removeFromSale(sunflower));
        CHECK(manager->getSaleCount() == 2);
        CHECK_FALSE(manager->isInSale(sunflower));
        CHECK(manager->isInSale(rose));
        CHECK(manager->isInSale(tomato));
        
        delete sunflower;
    }
    
    SUBCASE("Remove non-existing plant from sale") {
        Plant* rose = new Rose();
        manager->addToSale(rose);
        
        Plant* notInSale = new Rose();
        CHECK_NOTHROW(manager->removeFromSale(notInSale));
        CHECK(manager->getSaleCount() == 1);
        delete notInSale;
    }
    
    SUBCASE("Remove null plant from sale") {
        Plant* rose = new Rose();
        manager->addToSale(rose);
        
        CHECK_NOTHROW(manager->removeFromSale(nullptr));
        CHECK(manager->getSaleCount() == 1);
    }
    
    SUBCASE("Remove all plants from sale") {
        Plant* rose = new Rose();
        Plant* sunflower = new Sunflower();
        Plant* tomato = new Tomato();
        
        manager->addToSale(rose);
        manager->addToSale(sunflower);
        manager->addToSale(tomato);
        
        manager->removeFromSale(rose);
        manager->removeFromSale(sunflower);
        manager->removeFromSale(tomato);
        CHECK(manager->getSaleCount() == 0);
        
        delete rose;
        delete sunflower;
        delete tomato;
    }
    
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

TEST_CASE("InventoryManager - Sorted Insertion by Category and Name") {
    InventoryManager* manager = new InventoryManager();
    
    // Create plants from different categories
    Rose rose;
    Basil basil;
    Lavender lavender;
    Thyme thyme;
    RubberTree rubberTree;
    Ginger ginger;
    Chamomile chamomile;
    Tomato tomato;
    AppleTree appleTree;
    OrangeTree orangeTree;
    Lettuce lettuce;
    Pumpkin pumpkin;
    Cattails cattails;
    SnakePlant snakePlant;
    Chrysanthemum chris;
    Pansy pansy;
    Sunflower sunflower;
    
    // Add plants in random order
    manager->addToNursery(&rose);
    manager->addToNursery(&basil);
    manager->addToNursery(&lavender);
    manager->addToNursery(&thyme);
    manager->addToNursery(&rubberTree);
    manager->addToNursery(&ginger);
    manager->addToNursery(&chamomile);
    manager->addToNursery(&tomato);
    manager->addToNursery(&appleTree);
    manager->addToNursery(&orangeTree);
    manager->addToNursery(&lettuce);
    manager->addToNursery(&pumpkin);
    manager->addToNursery(&cattails);
    manager->addToNursery(&snakePlant);
    manager->addToNursery(&chris);
    manager->addToNursery(&pansy);
    manager->addToNursery(&sunflower);
    
    const vector<Plant*>& nurseryPlants = manager->getNurseryPlants();
    
    SUBCASE("Check total count") {
        CHECK(nurseryPlants.size() == 17);
    }
    
    SUBCASE("Check sorted by category priority") {
        CHECK(nurseryPlants[0]->getCategory() == "Flower");
        CHECK(nurseryPlants[1]->getCategory() == "Flower");
        CHECK(nurseryPlants[2]->getCategory() == "Flower");
        CHECK(nurseryPlants[3]->getCategory() == "Flower");
        CHECK(nurseryPlants[4]->getCategory() == "Herb");
        CHECK(nurseryPlants[5]->getCategory() == "Herb");
        CHECK(nurseryPlants[6]->getCategory() == "Herb");
        CHECK(nurseryPlants[7]->getCategory() == "Fruit");
        CHECK(nurseryPlants[8]->getCategory() == "Fruit");
        CHECK(nurseryPlants[9]->getCategory() == "Fruit");
        CHECK(nurseryPlants[10]->getCategory() == "Vegetable");
        CHECK(nurseryPlants[11]->getCategory() == "Vegetable");
        CHECK(nurseryPlants[12]->getCategory() == "Aquatic");
        CHECK(nurseryPlants[13]->getCategory() == "Indoor");
        CHECK(nurseryPlants[14]->getCategory() == "Indoor");
        CHECK(nurseryPlants[15]->getCategory() == "Medicinal");
        CHECK(nurseryPlants[16]->getCategory() == "Medicinal");
    }
    
    SUBCASE("Check alphabetical order within categories") {
        CHECK(nurseryPlants[0]->getName() == "Chrysanthemum");
        CHECK(nurseryPlants[1]->getName() == "Pansy");
        CHECK(nurseryPlants[2]->getName() == "Rose");
        CHECK(nurseryPlants[3]->getName() == "Sunflower");
        CHECK(nurseryPlants[4]->getName() == "Basil");
        CHECK(nurseryPlants[5]->getName() == "Lavender");
        CHECK(nurseryPlants[6]->getName() == "Thyme");
        CHECK(nurseryPlants[7]->getName() == "Apple Tree");
        CHECK(nurseryPlants[8]->getName() == "Orange Tree");
        CHECK(nurseryPlants[9]->getName() == "Tomato");
        CHECK(nurseryPlants[10]->getName() == "Lettuce");
        CHECK(nurseryPlants[11]->getName() == "Pumpkin");
        CHECK(nurseryPlants[13]->getName() == "Rubber Tree");
        CHECK(nurseryPlants[14]->getName() == "SnakePlant");
        CHECK(nurseryPlants[15]->getName() == "Chamomile");
        CHECK(nurseryPlants[16]->getName() == "Ginger");
    }
    
    manager->removeFromNursery(&rose);
    manager->removeFromNursery(&basil);
    manager->removeFromNursery(&lavender);
    manager->removeFromNursery(&thyme);
    manager->removeFromNursery(&rubberTree);
    manager->removeFromNursery(&ginger);
    manager->removeFromNursery(&chamomile);
    manager->removeFromNursery(&tomato);
    manager->removeFromNursery(&appleTree);
    manager->removeFromNursery(&orangeTree);
    manager->removeFromNursery(&lettuce);
    manager->removeFromNursery(&pumpkin);
    manager->removeFromNursery(&cattails);
    manager->removeFromNursery(&snakePlant);
    manager->removeFromNursery(&chris);
    manager->removeFromNursery(&pansy);
    manager->removeFromNursery(&sunflower);
    
    delete manager;
}

TEST_CASE("InventoryManager - Sorted Insertion to Sale by Category and Name") {
    InventoryManager* manager = new InventoryManager();
    
    // Create plants from different categories
    Rose rose;
    Basil basil;
    Lavender lavender;
    Thyme thyme;
    RubberTree rubberTree;
    Ginger ginger;
    Chamomile chamomile;
    Tomato tomato;
    AppleTree appleTree;
    OrangeTree orangeTree;
    Lettuce lettuce;
    Pumpkin pumpkin;
    Cattails cattails;
    SnakePlant snakePlant;
    Chrysanthemum chris;
    Pansy pansy;
    Sunflower sunflower;
    
    // Add plants to sale in random order
    manager->addToSale(&rose);
    manager->addToSale(&basil);
    manager->addToSale(&lavender);
    manager->addToSale(&thyme);
    manager->addToSale(&rubberTree);
    manager->addToSale(&ginger);
    manager->addToSale(&chamomile);
    manager->addToSale(&tomato);
    manager->addToSale(&appleTree);
    manager->addToSale(&orangeTree);
    manager->addToSale(&lettuce);
    manager->addToSale(&pumpkin);
    manager->addToSale(&cattails);
    manager->addToSale(&snakePlant);
    manager->addToSale(&chris);
    manager->addToSale(&pansy);
    manager->addToSale(&sunflower);
    
    const vector<Plant*>& salePlants = manager->getForSalePlants();
    
    SUBCASE("Check total count") {
        CHECK(salePlants.size() == 17);
    }
    
    SUBCASE("Check sorted by category priority") {
        CHECK(salePlants[0]->getCategory() == "Flower");
        CHECK(salePlants[1]->getCategory() == "Flower");
        CHECK(salePlants[2]->getCategory() == "Flower");
        CHECK(salePlants[3]->getCategory() == "Flower");
        CHECK(salePlants[4]->getCategory() == "Herb");
        CHECK(salePlants[5]->getCategory() == "Herb");
        CHECK(salePlants[6]->getCategory() == "Herb");
        CHECK(salePlants[7]->getCategory() == "Fruit");
        CHECK(salePlants[8]->getCategory() == "Fruit");
        CHECK(salePlants[9]->getCategory() == "Fruit");
        CHECK(salePlants[10]->getCategory() == "Vegetable");
        CHECK(salePlants[11]->getCategory() == "Vegetable");
        CHECK(salePlants[12]->getCategory() == "Aquatic");
        CHECK(salePlants[13]->getCategory() == "Indoor");
        CHECK(salePlants[14]->getCategory() == "Indoor");
        CHECK(salePlants[15]->getCategory() == "Medicinal");
        CHECK(salePlants[16]->getCategory() == "Medicinal");
    }
    
    SUBCASE("Check alphabetical order within categories") {
        CHECK(salePlants[0]->getName() == "Chrysanthemum");
        CHECK(salePlants[1]->getName() == "Pansy");
        CHECK(salePlants[2]->getName() == "Rose");
        CHECK(salePlants[3]->getName() == "Sunflower");
        CHECK(salePlants[4]->getName() == "Basil");
        CHECK(salePlants[5]->getName() == "Lavender");
        CHECK(salePlants[6]->getName() == "Thyme");
        CHECK(salePlants[7]->getName() == "Apple Tree");
        CHECK(salePlants[8]->getName() == "Orange Tree");
        CHECK(salePlants[9]->getName() == "Tomato");
        CHECK(salePlants[10]->getName() == "Lettuce");
        CHECK(salePlants[11]->getName() == "Pumpkin");
        CHECK(salePlants[13]->getName() == "Rubber Tree");
        CHECK(salePlants[14]->getName() == "SnakePlant");
        CHECK(salePlants[15]->getName() == "Chamomile");
        CHECK(salePlants[16]->getName() == "Ginger");
    }
    
    manager->removeFromSale(&rose);
    manager->removeFromSale(&basil);
    manager->removeFromSale(&lavender);
    manager->removeFromSale(&thyme);
    manager->removeFromSale(&rubberTree);
    manager->removeFromSale(&ginger);
    manager->removeFromSale(&chamomile);
    manager->removeFromSale(&tomato);
    manager->removeFromSale(&appleTree);
    manager->removeFromSale(&orangeTree);
    manager->removeFromSale(&lettuce);
    manager->removeFromSale(&pumpkin);
    manager->removeFromSale(&cattails);
    manager->removeFromSale(&snakePlant);
    manager->removeFromSale(&chris);
    manager->removeFromSale(&pansy);
    manager->removeFromSale(&sunflower);
    
    delete manager;
}