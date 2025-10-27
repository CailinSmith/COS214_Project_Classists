#include "doctest.h"
#include "Rose.h"
#include "Basil.h"
#include "Tomato.h"
#include "InventoryManager.h"
#include "Nursery.h"
#include "WaterCommand.h"
#include "StockCommand.h"
#include "PlantCommand.h"
#include "MakeSellableCommand.h"
#include "RemoveCommand.h"
#include "RemoveSaleCommand.h"
#include "PruneCommand.h"
#include "FertiliseCommand.h"
#include "CalcCostCommand.h"
#include "GetInfoCommand.h"
#include "StaffCheckStockCommand.h"
#include "StaffCheckoutCommand.h"
#include "Receipt.h"
#include <vector>

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

TEST_CASE("Command Pattern: WaterCommand affects plant water level") {
    Rose rose;
    float initialWater = rose.getTotalWater();
    WaterCommand waterRose(&rose);
    waterRose.execute();
    CHECK(rose.getTotalWater() > initialWater);
}

TEST_CASE("Command Pattern: PruneCommand affects plant pruned status") {
    Basil basil;
    CHECK_FALSE(basil.getPruned());
    PruneCommand pruneBasil(&basil);
    pruneBasil.execute();
    CHECK(basil.getPruned());
}

TEST_CASE("Command Pattern: FertiliseCommand executes without error") {
    Tomato tomato;
    FertiliseCommand fertiliseTomato(&tomato);
    CHECK_NOTHROW(fertiliseTomato.execute());
}

TEST_CASE("Command Pattern: PlantCommand adds plant to nursery") {
    InventoryManager* manager = new InventoryManager();
    Rose* rose = new Rose();
    size_t initialCount = manager->getNurseryCount();
    
    PlantCommand plantRose(rose, manager);
    plantRose.execute();
    
    CHECK(manager->getNurseryCount() == initialCount + 1);
    CHECK(manager->isInNursery(rose));
    delete rose;
    delete manager;
}

TEST_CASE("Command Pattern: MakeSellableCommand moves plant to sale") {
    InventoryManager* manager = new InventoryManager();
    Rose* rose = new Rose();
    manager->addToNursery(rose);
    
    size_t initialSaleCount = manager->getSaleCount();
    MakeSellableCommand makeSellable(rose, manager);
    makeSellable.execute();
    
    CHECK(manager->getSaleCount() == initialSaleCount + 1);
    CHECK(manager->isInSale(rose));
    CHECK_FALSE(manager->isInNursery(rose));
    delete rose;
    delete manager;
}

TEST_CASE("Command Pattern: RemoveCommand removes plant from nursery") {
    InventoryManager* manager = new InventoryManager();
    Rose* rose = new Rose();
    manager->addToNursery(rose);
    
    CHECK(manager->isInNursery(rose));
    RemoveCommand removeRose(rose, manager);
    removeRose.execute();
    
    CHECK_FALSE(manager->isInNursery(rose));
    delete manager;
    delete rose;
}

TEST_CASE("Command Pattern: RemoveSaleCommand removes plant from sale") {
    InventoryManager* manager = new InventoryManager();
    Rose* rose = new Rose();
    manager->addToSale(rose);
    
    CHECK(manager->isInSale(rose));
    RemoveSaleCommand removeSale(rose, manager);
    removeSale.execute();
    
    CHECK_FALSE(manager->isInSale(rose));
    delete manager;
    delete rose;
}

TEST_CASE("Command Pattern: CalcCostCommand calculates plant cost") {
    InventoryManager* manager = new InventoryManager();
    Nursery* nursery = Nursery::getInstance(manager);
    Rose* rose = new Rose();
    
    CalcCostCommand calcCost(rose, nursery);
    calcCost.execute();
    
    CHECK(calcCost.getCost() >= 0.0f);
    delete manager;
    delete rose;
}

TEST_CASE("Command Pattern: GetInfoCommand returns plant information") {
    Rose rose;
    GetInfoCommand getInfo(&rose);
    getInfo.execute();
    
    std::string info = getInfo.getInfo();
    CHECK_FALSE(info.empty());
    CHECK(info.find("Rose") != std::string::npos);
}

TEST_CASE("Command Pattern: StaffCheckStockCommand checks inventory") {
    InventoryManager* manager = new InventoryManager();
    Nursery* nursery = Nursery::getInstance(manager);
    
    Rose* rose = new Rose();
    manager->addToSale(rose);
    
    StaffCheckStockCommand checkStock(rose, manager);
    CHECK_NOTHROW(checkStock.execute());
    
    // cleanup created plant
    delete rose;
    delete manager;
}

TEST_CASE("Command Pattern: StaffCheckoutCommand processes checkout") {
    InventoryManager* manager = new InventoryManager();
    Nursery* nursery = Nursery::getInstance(manager);
    
    std::vector<Product*> products;
    products.push_back(new Rose());
    products.push_back(new Basil());
    
    for (Product* product : products) {
        manager->addToSale(dynamic_cast<Plant*>(product));
    }
    
    StaffCheckoutCommand checkout(products);
    CHECK_NOTHROW(checkout.execute());
    
    Receipt* receipt = checkout.getReceipt();
    CHECK(receipt != nullptr);
    CHECK(receipt->getCost() >= 0.0f);
    CHECK_FALSE(receipt->toString().empty());
    //caller takes ownership of the returned receipt (getReceipt transfers ownership)
    delete receipt;
    delete manager;

    // Clean up products
    for (Product* product : products) {
        delete product;
    }
}

TEST_CASE("Command Pattern: Receipt functionality with multiple products") {
    std::vector<Product*> products;
    products.push_back(new Rose());
    products.push_back(new Basil());
    products.push_back(new Tomato());
    
    Receipt receipt(products);
    
    CHECK(receipt.getCost() >= 0.0f);
    CHECK_FALSE(receipt.getDate().empty());
    CHECK_FALSE(receipt.toString().empty());
    
    std::string receiptText = receipt.toString();
    CHECK(receiptText.find("GreensOnly") != std::string::npos);
    CHECK(receiptText.find("TOTAL:") != std::string::npos);
    CHECK(receiptText.find("Thank you for shopping!") != std::string::npos);

    // Clean up products
    for (Product* product : products) {
        delete product;
    }
}

TEST_CASE("Command Pattern: Command execution with null plants") {
    WaterCommand waterNull(nullptr);
    CHECK_NOTHROW(waterNull.execute());
    
    PruneCommand pruneNull(nullptr);
    CHECK_NOTHROW(pruneNull.execute());
    
    FertiliseCommand fertiliseNull(nullptr);
    CHECK_NOTHROW(fertiliseNull.execute());
}

TEST_CASE("Command Pattern: Commands with null managers") {
    Rose* rose = new Rose();
    
    PlantCommand plantNull(rose, nullptr);
    CHECK_NOTHROW(plantNull.execute());
    
    MakeSellableCommand sellableNull(rose, nullptr);
    CHECK_NOTHROW(sellableNull.execute());
    
    RemoveCommand removeNull(rose, nullptr);
    CHECK_NOTHROW(removeNull.execute());
    
    delete rose;
}

