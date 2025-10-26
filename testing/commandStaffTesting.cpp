#include "doctest.h"
#include "Rose.h"
#include "Basil.h"
#include "Tomato.h"
#include "InventoryManager.h"
#include "Nursery.h"
#include "WaterCommand.h"
#include "StockCommand.h"

//WILL ADD MORE DOCTESTS TO COVER ALL PATTERNS

TEST_CASE("Command Pattern: WaterCommand executes without error") {
    Rose rose;
    WaterCommand waterRose(&rose);
    CHECK_NOTHROW(waterRose.execute());
}

TEST_CASE("Command Pattern: StockCommand executes without error") {
    InventoryManager* manager = new InventoryManager();
    Nursery* nursery = Nursery::getInstance(manager);
    StockCommand stockNursery;
    CHECK_NOTHROW(stockNursery.execute());
    delete manager;
}

