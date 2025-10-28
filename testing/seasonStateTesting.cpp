#include "doctest.h"
#include "../src/SeasonState.h"
#include "../src/Spring.h"
#include "../src/Summer.h"
#include "../src/Autumn.h"
#include "../src/Winter.h"
#include "../src/Nursery.h"
#include "../src/InventoryManager.h"

TEST_CASE("Testing Season State - Spring print method") {
    Spring* spring = new Spring();
    CHECK(spring->print() == "Spring");
    delete spring;
}

TEST_CASE("Testing Season State - Summer print method") {
    Summer* summer = new Summer();
    CHECK(summer->print() == "Summer");
    delete summer;
}

TEST_CASE("Testing Season State - Autumn print method") {
    Autumn* autumn = new Autumn();
    CHECK(autumn->print() == "Autumn");
    delete autumn;
}

TEST_CASE("Testing Season State - Winter print method") {
    Winter* winter = new Winter();
    CHECK(winter->print() == "Winter");
    delete winter;
}

TEST_CASE("Testing Season State - Spring to Summer transition") {
    InventoryManager* manager = new InventoryManager();
    Nursery* nursery = Nursery::getInstance(manager);
    
    nursery->setSeason(new Spring());
    CHECK(nursery->getSeason() == "Spring");
    
    nursery->changeSeason();
    CHECK(nursery->getSeason() == "Summer");
    
     
    delete manager;
}

TEST_CASE("Testing Season State - Summer to Autumn transition") {
    InventoryManager* manager = new InventoryManager();
    Nursery* nursery = Nursery::getInstance(manager);
    
    nursery->setSeason(new Summer());
    CHECK(nursery->getSeason() == "Summer");
    
    nursery->changeSeason();
    CHECK(nursery->getSeason() == "Autumn");
    
     
    delete manager;
}

TEST_CASE("Testing Season State - Autumn to Winter transition") {
    InventoryManager* manager = new InventoryManager();
    Nursery* nursery = Nursery::getInstance(manager);
    
    nursery->setSeason(new Autumn());
    CHECK(nursery->getSeason() == "Autumn");
    
    nursery->changeSeason();
    CHECK(nursery->getSeason() == "Winter");
    
     
    delete manager;
}

TEST_CASE("Testing Season State - Winter to Spring transition (full cycle)") {
    InventoryManager* manager = new InventoryManager();
    Nursery* nursery = Nursery::getInstance(manager);
    
    nursery->setSeason(new Winter());
    CHECK(nursery->getSeason() == "Winter");
    
    nursery->changeSeason();
    CHECK(nursery->getSeason() == "Spring");
    
     
    delete manager;
}

TEST_CASE("Testing Season State - Complete seasonal cycle") {
    InventoryManager* manager = new InventoryManager();
    Nursery* nursery = Nursery::getInstance(manager);
    
    nursery->setSeason(new Spring());
    CHECK(nursery->getSeason() == "Spring");
    
    nursery->changeSeason();
    CHECK(nursery->getSeason() == "Summer");
    
    nursery->changeSeason();
    CHECK(nursery->getSeason() == "Autumn");
    
    nursery->changeSeason();
    CHECK(nursery->getSeason() == "Winter");
    
    nursery->changeSeason();
    CHECK(nursery->getSeason() == "Spring");
    
     
    delete manager;
}

TEST_CASE("Testing Season State - Multiple cycles") {
    InventoryManager* manager = new InventoryManager();
    Nursery* nursery = Nursery::getInstance(manager);
    
    nursery->setSeason(new Spring());
    
    for (int cycle = 0; cycle < 2; cycle++) {
        CHECK(nursery->getSeason() == "Spring");
        nursery->changeSeason();
        
        CHECK(nursery->getSeason() == "Summer");
        nursery->changeSeason();
        
        CHECK(nursery->getSeason() == "Autumn");
        nursery->changeSeason();
        
        CHECK(nursery->getSeason() == "Winter");
        nursery->changeSeason();
    }
    
    CHECK(nursery->getSeason() == "Spring");
    
     
    delete manager;
}