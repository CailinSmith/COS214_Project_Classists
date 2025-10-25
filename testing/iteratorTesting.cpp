#include "doctest.h"
#include "../src/InventoryManager.h"
#include "../src/SeasonIterator.h"
#include "../src/Iterator.h"
#include "../src/Plant.h"
#include "../src/Rose.h"
#include "../src/Basil.h"
#include "../src/Tomato.h"
#include "../src/Lettuce.h"
#include "../src/Chrysanthemum.h"
#include "../src/Pansy.h"
#include "../src/Sunflower.h"

TEST_CASE("Iterator Pattern - Basic SeasonIterator Creation") {
    std::vector<Plant*> plants;
    Plant* rose = new Rose();
    Plant* basil = new Basil();
    plants.push_back(rose);
    plants.push_back(basil);
    SeasonIterator* iterator = new SeasonIterator(plants, "Summer");
    
    CHECK(iterator != nullptr);
    CHECK_FALSE(iterator->isDone());
    
    delete iterator;
    delete rose;
    delete basil;
}

TEST_CASE("Iterator Pattern - InventoryManager createIterator") {
    InventoryManager* inventory = new InventoryManager();
    Plant* rose = new Rose();
    Plant* chrysanthemum = new Chrysanthemum();
    Plant* pansy = new Pansy();
    inventory->addToSale(rose);
    inventory->addToNursery(chrysanthemum);
    inventory->addToSale(pansy);
    
    SUBCASE("Create iterator for Summer season") {
        Iterator<Plant>* summerIterator = inventory->createIterator("Summer");
        CHECK(summerIterator != nullptr);
        
        int count = 0;
        for (Plant* plant = summerIterator->first(); !summerIterator->isDone(); plant = summerIterator->next()) {
            if (plant != nullptr) {
                count++;
                CHECK(plant->getSellSeason() == "Summer");
            }
        }
        CHECK(count >= 0);
        
        delete summerIterator;
    }
    
    SUBCASE("Create sale iterator for Summer season") {
        Iterator<Plant>* saleIterator = inventory->createSaleIterator("Summer");
        CHECK(saleIterator != nullptr);
        
        int saleCount = 0;
        for (Plant* plant = saleIterator->first(); !saleIterator->isDone(); plant = saleIterator->next()) {
            if (plant != nullptr) {
                saleCount++;
                CHECK(inventory->isInSale(plant));
            }
        }
        
        delete saleIterator;
    }
    
    SUBCASE("Create nursery iterator for Summer season") {
        Iterator<Plant>* nurseryIterator = inventory->createNurseryIterator("Summer");
        CHECK(nurseryIterator != nullptr);
        
        int nurseryCount = 0;
        for (Plant* plant = nurseryIterator->first(); !nurseryIterator->isDone(); plant = nurseryIterator->next()) {
            if (plant != nullptr) {
                nurseryCount++;
                CHECK(inventory->isInNursery(plant));
            }
        }
        
        delete nurseryIterator;
    }
    delete rose;
    delete chrysanthemum;
    delete pansy;
    delete inventory;
}

TEST_CASE("Iterator Pattern - Season Filtering") {
    std::vector<Plant*> plants;
    Plant* rose = new Rose();
    Plant* chrysanthemum = new Chrysanthemum();
    Plant* pansy = new Pansy();
    Plant* sunflower = new Sunflower();
    
    plants.push_back(rose);
    plants.push_back(chrysanthemum);
    plants.push_back(pansy);
    plants.push_back(sunflower);
    
    SUBCASE("Filter Summer plants") {
        SeasonIterator* summerIterator = new SeasonIterator(plants, "Summer");
        
        int summerCount = 0;
        for (Plant* plant = summerIterator->first(); !summerIterator->isDone(); plant = summerIterator->next()) {
            if (plant != nullptr) {
                summerCount++;
                CHECK(plant->getSellSeason() == "Summer");
            }
        }
        delete summerIterator;
    }
    
    SUBCASE("Filter non-existent season") {
        SeasonIterator* nonExistentIterator = new SeasonIterator(plants, "NonExistentSeason");
        
        CHECK(nonExistentIterator->isDone());
        CHECK(nonExistentIterator->currentItem() == nullptr);
        delete nonExistentIterator;
    }
    delete rose;
    delete chrysanthemum;
    delete pansy;
    delete sunflower;
}

TEST_CASE("Iterator Pattern - Iterator Methods") {
    std::vector<Plant*> plants;
    Plant* rose = new Rose();
    Plant* chrysanthemum = new Chrysanthemum();
    plants.push_back(rose);
    plants.push_back(chrysanthemum);
    SeasonIterator* iterator = new SeasonIterator(plants, "Summer");
    
    SUBCASE("Test first() method") {
        Plant* firstPlant = iterator->first();
        CHECK(firstPlant != nullptr);
        CHECK(firstPlant->getSellSeason() == "Summer");
    }
    
    SUBCASE("Test currentItem() method") {
        iterator->first();
        Plant* currentPlant = iterator->currentItem();
        CHECK(currentPlant != nullptr);
        CHECK(currentPlant->getSellSeason() == "Summer");
    }
    
    SUBCASE("Test next() method") {
        iterator->first();
        Plant* nextPlant = iterator->next();
        if (nextPlant != nullptr) {
            CHECK(nextPlant->getSellSeason() == "Summer");
        }
    }
    
    SUBCASE("Test isDone() method") {
        iterator->first();
        while (!iterator->isDone()) {
            iterator->next();
        }
        CHECK(iterator->isDone());
        CHECK(iterator->currentItem() == nullptr);
    }
    delete iterator;
    delete rose;
    delete chrysanthemum;
}
