#include "doctest.h"
#include "Rose.h"
#include "Basil.h"
#include "Tomato.h"
#include "InventoryManager.h"
#include "Nursery.h"
#include "WaterCommand.h"
#include "StockCommand.h"
#include "SellCommand.h"

//WILL ADD MORE DOCTESTS TO COVER ALL PATTERNS

TEST_CASE("Command Pattern: WaterCommand executes without error") {
    Rose rose;
    WaterCommand waterRose(&rose);
    CHECK_NOTHROW(waterRose.execute());
}

TEST_CASE("Command Pattern: StockCommand executes without error") {
    InventoryManager* manager = new InventoryManager();
    Nursery nursery(manager);
    StockCommand stockNursery(&nursery);
    CHECK_NOTHROW(stockNursery.execute());
    delete manager;
}

TEST_CASE("Command Pattern: SellCommand executes without error") {
    InventoryManager* manager = new InventoryManager();
    Tomato tomato;
    manager->addToNursery(&tomato);
    SellCommand sellTomato(&tomato, manager);
    CHECK_NOTHROW(sellTomato.execute());
    delete manager;
}
