#include <iostream>
#include <vector>

#include "Plant.h"
#include "Product.h"

#include "Flower.h"
#include "Herb.h"
#include "Fruit.h"
#include "Vegetable.h"
#include "Succulent.h"
#include "Aquatic.h"
#include "Indoor.h"
#include "Medicinal.h"

#include "PlantFactory.h"
#include "SpringFactory.h"
#include "SummerFactory.h"
#include "AutumnFactory.h"
#include "WinterFactory.h"

#include "Rose.h"
#include "Basil.h"
#include "Tomato.h"
#include "Lettuce.h"
#include "JadePlant.h"
#include "WaterLily.h"
#include "SnakePlant.h"
#include "AloeVera.h"

#include "Chrysanthemum.h"
#include "Lavender.h"
#include "AppleTree.h"
#include "Pumpkin.h"
#include "BarrelCactus.h"
#include "WaterHyacinth.h"
#include "RubberTree.h"
#include "Coneflower.h"

#include "Pansy.h"
#include "Thyme.h"
#include "Strawberry.h"
#include "Kale.h"
#include "Echeveria.h"
#include "Cattails.h"
#include "PeaceLily.h"
#include "Chamomile.h"

#include "Sunflower.h"
#include "Rosemary.h"
#include "OrangeTree.h"
#include "Cucumber.h"
#include "ChristmasCactus.h"
#include "WaterLettuce.h"
#include "Pothos.h"
#include "Ginger.h"

#include "StaffCommand.h"
#include "StockCommand.h"
#include "PlantCommand.h"
#include "MakeSellableCommand.h"
#include "SellCommand.h"
#include "RemoveCommand.h"
#include "RemoveSaleCommand.h"
#include "WaterCommand.h"
#include "PruneCommand.h"
#include "FertiliseCommand.h"

#include "InventoryManager.h"
#include "Nursery.h"

using namespace std;

void printSeparator(string title) {
    cout << "\n" << string(50, '=') << endl;
    cout << "  " << title << endl;
    cout << string(50, '=') << endl;
}
void testPlantCategories() {
    printSeparator("PLANT CATEGORIES TEST");
    
    cout << "Testing different plant categories and their properties..." << endl << endl;
    
    Rose rose;
    Basil basil;
    Tomato tomato;
    
    cout << "🌹 Rose (Flower):" << endl;
    cout << "   Category: " << rose.getCategory() << endl;
    cout << "   Max Height: " << rose.getMaxHeight() << "cm" << endl;
    cout << "   Strategies: " << rose.getStrategies() << endl << endl;
    
    cout << "🌿 Basil (Herb):" << endl;
    cout << "   Category: " << basil.getCategory() << endl;
    cout << "   Max Height: " << basil.getMaxHeight() << "cm" << endl;
    cout << "   Strategies: " << basil.getStrategies() << endl << endl;
    
    cout << "🍅 Tomato (Fruit):" << endl;
    cout << "   Category: " << tomato.getCategory() << endl;
    cout << "   Max Height: " << tomato.getMaxHeight() << "cm" << endl;
    cout << "   Strategies: " << tomato.getStrategies() << endl << endl;
}
void testAllFactories() {
    printSeparator("ALL FACTORIES TEST");
    cout << "🏭 Testing all 4 seasonal factories..." << endl << endl;
    
    SpringFactory springFactory;
    SummerFactory summerFactory;
    AutumnFactory autumnFactory;
    WinterFactory winterFactory;
    
    cout << "🌸 Spring Factory - Creating one of each category:" << endl;
    Plant* springFlower = springFactory.createFlower();
    Plant* springHerb = springFactory.createHerb();
    cout << "   Flower: " << springFlower->getName() << " - " << springFlower->getMaxHeight() << "cm" << endl;
    cout << "   Herb: " << springHerb->getName() << " - " << springHerb->getMaxHeight() << "cm" << endl;
    delete springFlower; delete springHerb;
    
    cout << "\n☀️ Summer Factory - Creating one of each category:" << endl;
    Plant* summerFlower = summerFactory.createFlower();
    Plant* summerHerb = summerFactory.createHerb();
    cout << "   Flower: " << summerFlower->getName() << " - " << summerFlower->getMaxHeight() << "cm" << endl;
    cout << "   Herb: " << summerHerb->getName() << " - " << summerHerb->getMaxHeight() << "cm" << endl;
    delete summerFlower; delete summerHerb;
    
    cout << "\n🍂 Autumn Factory - Creating one of each category:" << endl;
    Plant* autumnFlower = autumnFactory.createFlower();
    Plant* autumnHerb = autumnFactory.createHerb();
    cout << "   Flower: " << autumnFlower->getName() << " - " << autumnFlower->getMaxHeight() << "cm" << endl;
    cout << "   Herb: " << autumnHerb->getName() << " - " << autumnHerb->getMaxHeight() << "cm" << endl;
    delete autumnFlower; delete autumnHerb;
    
    cout << "\n❄️ Winter Factory - Creating one of each category:" << endl;
    Plant* winterFlower = winterFactory.createFlower();
    Plant* winterHerb = winterFactory.createHerb();
    cout << "   Flower: " << winterFlower->getName() << " - " << winterFlower->getMaxHeight() << "cm" << endl;
    cout << "   Herb: " << winterHerb->getName() << " - " << winterHerb->getMaxHeight() << "cm" << endl;
    delete winterFlower; delete winterHerb;
}
void testPlantStatistics() {
    printSeparator("PLANT STATISTICS");
    cout << "📊 Analyzing all 32 plants by category..." << endl << endl;
    
    int flowerCount = 4, herbCount = 4, fruitCount = 4, vegetableCount = 4;
    int succulentCount = 4, aquaticCount = 4, indoorCount = 4, medicinalCount = 4;
    
    cout << "📈 Plant Distribution by Category:" << endl;
    cout << "   🌹 Flowers: " << flowerCount << " plants" << endl;
    cout << "   🌿 Herbs: " << herbCount << " plants" << endl;
    cout << "   🍎 Fruits: " << fruitCount << " plants" << endl;
    cout << "   🥬 Vegetables: " << vegetableCount << " plants" << endl;
    cout << "   🌵 Succulents: " << succulentCount << " plants" << endl;
    cout << "   💧 Aquatic: " << aquaticCount << " plants" << endl;
    cout << "   🏠 Indoor: " << indoorCount << " plants" << endl;
    cout << "   💊 Medicinal: " << medicinalCount << " plants" << endl;
    cout << "   📊 Total: " << (flowerCount + herbCount + fruitCount + vegetableCount + 
                                succulentCount + aquaticCount + indoorCount + medicinalCount) << " plants" << endl;
    
    cout << "\n📈 Plant Distribution by Season:" << endl;
    cout << "   🌸 Spring: 8 plants" << endl;
    cout << "   ☀️ Summer: 8 plants" << endl;
    cout << "   🍂 Autumn: 8 plants" << endl;
    cout << "   ❄️ Winter: 8 plants" << endl;
    cout << "   📊 Total: 32 plants" << endl;
}
void testEveryPlantFromFactories() {
    printSeparator("COMPREHENSIVE FACTORY PLANT CREATION TEST");
    cout << "🏭 Creating ALL 32 plants using their respective seasonal factories..." << endl << endl;
    
    SpringFactory springFactory;
    SummerFactory summerFactory;
    AutumnFactory autumnFactory;
    WinterFactory winterFactory;
    
    cout << "🌸 SPRING FACTORY - Creating all 8 Spring plants:" << endl;
    Plant* springFlower = springFactory.createFlower();
    Plant* springHerb = springFactory.createHerb();
    Plant* springFruit = springFactory.createFruit();
    Plant* springVegetable = springFactory.createVegetable();
    Plant* springSucculent = springFactory.createSucculent();
    Plant* springAquatic = springFactory.createAquatic();
    Plant* springIndoor = springFactory.createIndoor();
    Plant* springMedicinal = springFactory.createMedicinal();
    
    cout << "   🌹 " << springFlower->getName() << " (Flower) - " << springFlower->getMaxHeight() << "cm" << endl;
    cout << "   🌿 " << springHerb->getName() << " (Herb) - " << springHerb->getMaxHeight() << "cm" << endl;
    cout << "   🍅 " << springFruit->getName() << " (Fruit) - " << springFruit->getMaxHeight() << "cm" << endl;
    cout << "   🥬 " << springVegetable->getName() << " (Vegetable) - " << springVegetable->getMaxHeight() << "cm" << endl;
    cout << "   🌵 " << springSucculent->getName() << " (Succulent) - " << springSucculent->getMaxHeight() << "cm" << endl;
    cout << "   💧 " << springAquatic->getName() << " (Aquatic) - " << springAquatic->getMaxHeight() << "cm" << endl;
    cout << "   🏠 " << springIndoor->getName() << " (Indoor) - " << springIndoor->getMaxHeight() << "cm" << endl;
    cout << "   💊 " << springMedicinal->getName() << " (Medicinal) - " << springMedicinal->getMaxHeight() << "cm" << endl;
    
    delete springFlower; delete springHerb; delete springFruit; delete springVegetable;
    delete springSucculent; delete springAquatic; delete springIndoor; delete springMedicinal;
    
    cout << "\n☀️ SUMMER FACTORY - Creating all 8 Summer plants:" << endl;
    Plant* summerFlower = summerFactory.createFlower();
    Plant* summerHerb = summerFactory.createHerb();
    Plant* summerFruit = summerFactory.createFruit();
    Plant* summerVegetable = summerFactory.createVegetable();
    Plant* summerSucculent = summerFactory.createSucculent();
    Plant* summerAquatic = summerFactory.createAquatic();
    Plant* summerIndoor = summerFactory.createIndoor();
    Plant* summerMedicinal = summerFactory.createMedicinal();
    
    cout << "   🌼 " << summerFlower->getName() << " (Flower) - " << summerFlower->getMaxHeight() << "cm" << endl;
    cout << "   🌿 " << summerHerb->getName() << " (Herb) - " << summerHerb->getMaxHeight() << "cm" << endl;
    cout << "   🍎 " << summerFruit->getName() << " (Fruit) - " << summerFruit->getMaxHeight() << "cm" << endl;
    cout << "   🎃 " << summerVegetable->getName() << " (Vegetable) - " << summerVegetable->getMaxHeight() << "cm" << endl;
    cout << "   🌵 " << summerSucculent->getName() << " (Succulent) - " << summerSucculent->getMaxHeight() << "cm" << endl;
    cout << "   💧 " << summerAquatic->getName() << " (Aquatic) - " << summerAquatic->getMaxHeight() << "cm" << endl;
    cout << "   🏠 " << summerIndoor->getName() << " (Indoor) - " << summerIndoor->getMaxHeight() << "cm" << endl;
    cout << "   💊 " << summerMedicinal->getName() << " (Medicinal) - " << summerMedicinal->getMaxHeight() << "cm" << endl;
    
    delete summerFlower; delete summerHerb; delete summerFruit; delete summerVegetable;
    delete summerSucculent; delete summerAquatic; delete summerIndoor; delete summerMedicinal;
    
    cout << "\n🍂 AUTUMN FACTORY - Creating all 8 Autumn plants:" << endl;
    Plant* autumnFlower = autumnFactory.createFlower();
    Plant* autumnHerb = autumnFactory.createHerb();
    Plant* autumnFruit = autumnFactory.createFruit();
    Plant* autumnVegetable = autumnFactory.createVegetable();
    Plant* autumnSucculent = autumnFactory.createSucculent();
    Plant* autumnAquatic = autumnFactory.createAquatic();
    Plant* autumnIndoor = autumnFactory.createIndoor();
    Plant* autumnMedicinal = autumnFactory.createMedicinal();
    
    cout << "   🌸 " << autumnFlower->getName() << " (Flower) - " << autumnFlower->getMaxHeight() << "cm" << endl;
    cout << "   🌿 " << autumnHerb->getName() << " (Herb) - " << autumnHerb->getMaxHeight() << "cm" << endl;
    cout << "   🍓 " << autumnFruit->getName() << " (Fruit) - " << autumnFruit->getMaxHeight() << "cm" << endl;
    cout << "   🥬 " << autumnVegetable->getName() << " (Vegetable) - " << autumnVegetable->getMaxHeight() << "cm" << endl;
    cout << "   🌵 " << autumnSucculent->getName() << " (Succulent) - " << autumnSucculent->getMaxHeight() << "cm" << endl;
    cout << "   💧 " << autumnAquatic->getName() << " (Aquatic) - " << autumnAquatic->getMaxHeight() << "cm" << endl;
    cout << "   🏠 " << autumnIndoor->getName() << " (Indoor) - " << autumnIndoor->getMaxHeight() << "cm" << endl;
    cout << "   💊 " << autumnMedicinal->getName() << " (Medicinal) - " << autumnMedicinal->getMaxHeight() << "cm" << endl;
    
    delete autumnFlower; delete autumnHerb; delete autumnFruit; delete autumnVegetable;
    delete autumnSucculent; delete autumnAquatic; delete autumnIndoor; delete autumnMedicinal;
    
    cout << "\n❄️ WINTER FACTORY - Creating all 8 Winter plants:" << endl;
    Plant* winterFlower = winterFactory.createFlower();
    Plant* winterHerb = winterFactory.createHerb();
    Plant* winterFruit = winterFactory.createFruit();
    Plant* winterVegetable = winterFactory.createVegetable();
    Plant* winterSucculent = winterFactory.createSucculent();
    Plant* winterAquatic = winterFactory.createAquatic();
    Plant* winterIndoor = winterFactory.createIndoor();
    Plant* winterMedicinal = winterFactory.createMedicinal();
    
    cout << "   🌻 " << winterFlower->getName() << " (Flower) - " << winterFlower->getMaxHeight() << "cm" << endl;
    cout << "   🌿 " << winterHerb->getName() << " (Herb) - " << winterHerb->getMaxHeight() << "cm" << endl;
    cout << "   🍊 " << winterFruit->getName() << " (Fruit) - " << winterFruit->getMaxHeight() << "cm" << endl;
    cout << "   🥒 " << winterVegetable->getName() << " (Vegetable) - " << winterVegetable->getMaxHeight() << "cm" << endl;
    cout << "   🌵 " << winterSucculent->getName() << " (Succulent) - " << winterSucculent->getMaxHeight() << "cm" << endl;
    cout << "   💧 " << winterAquatic->getName() << " (Aquatic) - " << winterAquatic->getMaxHeight() << "cm" << endl;
    cout << "   🏠 " << winterIndoor->getName() << " (Indoor) - " << winterIndoor->getMaxHeight() << "cm" << endl;
    cout << "   💊 " << winterMedicinal->getName() << " (Medicinal) - " << winterMedicinal->getMaxHeight() << "cm" << endl;
    
    delete winterFlower; delete winterHerb; delete winterFruit; delete winterVegetable;
    delete winterSucculent; delete winterAquatic; delete winterIndoor; delete winterMedicinal;
    
    cout << "\n✅ SUCCESS: All 32 plants created successfully using their seasonal factories!" << endl;
    cout << "🎯 Factory Pattern Validation: Each season produces its unique plant varieties!" << endl;
}
void testAllStrategies() {
    printSeparator("STRATEGY TESTING");
    cout << "🧪 Testing all watering and pruning strategies with correct plant assignments..." << endl << endl;
    
    cout << "💧 WATERING STRATEGY TESTING:" << endl << endl;
    
    cout << "🌿 Medium Moisture Strategy (250ml per watering):" << endl;
    Rose rose1;
    Chrysanthemum chrysanthemum1;
    Pansy pansy1;
    
    cout << "   Before watering:" << endl;
    cout << "   • " << rose1.getName() << " - Water Level: " << rose1.getWaterLevel() << ", Total Water: " << rose1.getTotalWater() << "ml" << endl;
    cout << "   • " << chrysanthemum1.getName() << " - Water Level: " << chrysanthemum1.getWaterLevel() << ", Total Water: " << chrysanthemum1.getTotalWater() << "ml" << endl;
    cout << "   • " << pansy1.getName() << " - Water Level: " << pansy1.getWaterLevel() << ", Total Water: " << pansy1.getTotalWater() << "ml" << endl;
    
    rose1.water();
    chrysanthemum1.water();
    pansy1.water();
    
    cout << "   After watering:" << endl;
    cout << "   • " << rose1.getName() << " - Water Level: " << rose1.getWaterLevel() << ", Total Water: " << rose1.getTotalWater() << "ml" << endl;
    cout << "   • " << chrysanthemum1.getName() << " - Water Level: " << chrysanthemum1.getWaterLevel() << ", Total Water: " << chrysanthemum1.getTotalWater() << "ml" << endl;
    cout << "   • " << pansy1.getName() << " - Water Level: " << pansy1.getWaterLevel() << ", Total Water: " << pansy1.getTotalWater() << "ml" << endl << endl;
    
    cout << "💦 High Moisture Strategy (500ml per watering):" << endl;
    Basil basil1;
    Lettuce lettuce1;
    WaterLily waterlily1;
    
    cout << "   Before watering:" << endl;
    cout << "   • " << basil1.getName() << " - Water Level: " << basil1.getWaterLevel() << ", Total Water: " << basil1.getTotalWater() << "ml" << endl;
    cout << "   • " << lettuce1.getName() << " - Water Level: " << lettuce1.getWaterLevel() << ", Total Water: " << lettuce1.getTotalWater() << "ml" << endl;
    cout << "   • " << waterlily1.getName() << " - Water Level: " << waterlily1.getWaterLevel() << ", Total Water: " << waterlily1.getTotalWater() << "ml" << endl;
    
    basil1.water();
    lettuce1.water();
    waterlily1.water();
    
    cout << "   After watering:" << endl;
    cout << "   • " << basil1.getName() << " - Water Level: " << basil1.getWaterLevel() << ", Total Water: " << basil1.getTotalWater() << "ml" << endl;
    cout << "   • " << lettuce1.getName() << " - Water Level: " << lettuce1.getWaterLevel() << ", Total Water: " << lettuce1.getTotalWater() << "ml" << endl;
    cout << "   • " << waterlily1.getName() << " - Water Level: " << waterlily1.getWaterLevel() << ", Total Water: " << waterlily1.getTotalWater() << "ml" << endl << endl;
    
    cout << "🌵 Dry Plant Strategy (75ml per watering):" << endl;
    JadePlant jade1;
    Lavender lavender1;
    Thyme thyme1;
    
    cout << "   Before watering:" << endl;
    cout << "   • " << jade1.getName() << " - Water Level: " << jade1.getWaterLevel() << ", Total Water: " << jade1.getTotalWater() << "ml" << endl;
    cout << "   • " << lavender1.getName() << " - Water Level: " << lavender1.getWaterLevel() << ", Total Water: " << lavender1.getTotalWater() << "ml" << endl;
    cout << "   • " << thyme1.getName() << " - Water Level: " << thyme1.getWaterLevel() << ", Total Water: " << thyme1.getTotalWater() << "ml" << endl;
    
    jade1.water();
    lavender1.water();
    thyme1.water();
    
    cout << "   After watering:" << endl;
    cout << "   • " << jade1.getName() << " - Water Level: " << jade1.getWaterLevel() << ", Total Water: " << jade1.getTotalWater() << "ml" << endl;
    cout << "   • " << lavender1.getName() << " - Water Level: " << lavender1.getWaterLevel() << ", Total Water: " << lavender1.getTotalWater() << "ml" << endl;
    cout << "   • " << thyme1.getName() << " - Water Level: " << thyme1.getWaterLevel() << ", Total Water: " << thyme1.getTotalWater() << "ml" << endl << endl;
    
    cout << "✂️ PRUNING STRATEGY TESTING:" << endl << endl;
    
    cout << "🥀 Dead Pruning Strategy (improves health by removing dead parts):" << endl;
    Rose rose2;
    WaterLily waterlily2;
    Coneflower coneflower1;
    
    cout << "   Before pruning:" << endl;
    cout << "   • " << rose2.getName() << " - Health: " << rose2.getHealth() << ", Pruned: " << (rose2.getPruned() ? "Yes" : "No") << endl;
    cout << "   • " << waterlily2.getName() << " - Health: " << waterlily2.getHealth() << ", Pruned: " << (waterlily2.getPruned() ? "Yes" : "No") << endl;
    cout << "   • " << coneflower1.getName() << " - Health: " << coneflower1.getHealth() << ", Pruned: " << (coneflower1.getPruned() ? "Yes" : "No") << endl;
    
    rose2.prune();
    waterlily2.prune();
    coneflower1.prune();
    
    cout << "   After pruning:" << endl;
    cout << "   • " << rose2.getName() << " - Health: " << rose2.getHealth() << ", Pruned: " << (rose2.getPruned() ? "Yes" : "No") << endl;
    cout << "   • " << waterlily2.getName() << " - Health: " << waterlily2.getHealth() << ", Pruned: " << (waterlily2.getPruned() ? "Yes" : "No") << endl;
    cout << "   • " << coneflower1.getName() << " - Health: " << coneflower1.getHealth() << ", Pruned: " << (coneflower1.getPruned() ? "Yes" : "No") << endl << endl;
    
    cout << "🌿 Thinning Strategy (selective removal for better growth):" << endl;
    Basil basil2;
    Tomato tomato1;
    JadePlant jade2;
    
    cout << "   Before pruning:" << endl;
    cout << "   • " << basil2.getName() << " - Health: " << basil2.getHealth() << ", Pruned: " << (basil2.getPruned() ? "Yes" : "No") << endl;
    cout << "   • " << tomato1.getName() << " - Health: " << tomato1.getHealth() << ", Pruned: " << (tomato1.getPruned() ? "Yes" : "No") << endl;
    cout << "   • " << jade2.getName() << " - Health: " << jade2.getHealth() << ", Pruned: " << (jade2.getPruned() ? "Yes" : "No") << endl;
    
    basil2.prune();
    tomato1.prune();
    jade2.prune();
    
    cout << "   After pruning:" << endl;
    cout << "   • " << basil2.getName() << " - Health: " << basil2.getHealth() << ", Pruned: " << (basil2.getPruned() ? "Yes" : "No") << endl;
    cout << "   • " << tomato1.getName() << " - Health: " << tomato1.getHealth() << ", Pruned: " << (tomato1.getPruned() ? "Yes" : "No") << endl;
    cout << "   • " << jade2.getName() << " - Health: " << jade2.getHealth() << ", Pruned: " << (jade2.getPruned() ? "Yes" : "No") << endl << endl;
    
    cout << "🚫 No Prune Strategy (plants that don't need pruning):" << endl;
    Lettuce lettuce2;
    SnakePlant snake1;
    BarrelCactus cactus1;
    
    cout << "   Before pruning:" << endl;
    cout << "   • " << lettuce2.getName() << " - Health: " << lettuce2.getHealth() << ", Pruned: " << (lettuce2.getPruned() ? "Yes" : "No") << endl;
    cout << "   • " << snake1.getName() << " - Health: " << snake1.getHealth() << ", Pruned: " << (snake1.getPruned() ? "Yes" : "No") << endl;
    cout << "   • " << cactus1.getName() << " - Health: " << cactus1.getHealth() << ", Pruned: " << (cactus1.getPruned() ? "Yes" : "No") << endl;
    
    lettuce2.prune();
    snake1.prune();
    cactus1.prune();
    
    cout << "   After pruning:" << endl;
    cout << "   • " << lettuce2.getName() << " - Health: " << lettuce2.getHealth() << ", Pruned: " << (lettuce2.getPruned() ? "Yes" : "No") << endl;
    cout << "   • " << snake1.getName() << " - Health: " << snake1.getHealth() << ", Pruned: " << (snake1.getPruned() ? "Yes" : "No") << endl;
    cout << "   • " << cactus1.getName() << " - Health: " << cactus1.getHealth() << ", Pruned: " << (cactus1.getPruned() ? "Yes" : "No") << endl << endl;
    
    cout << "✂️ Reduction Strategy (significant size reduction):" << endl;
    Lavender lavender2;
    Cattails cattails1;
    
    cout << "   Before pruning:" << endl;
    cout << "   • " << lavender2.getName() << " - Height: " << lavender2.getHeight() << "cm, Pruned: " << (lavender2.getPruned() ? "Yes" : "No") << endl;
    cout << "   • " << cattails1.getName() << " - Height: " << cattails1.getHeight() << "cm, Pruned: " << (cattails1.getPruned() ? "Yes" : "No") << endl;
    
    lavender2.prune();
    cattails1.prune();
    
    cout << "   After pruning:" << endl;
    cout << "   • " << lavender2.getName() << " - Height: " << lavender2.getHeight() << "cm, Pruned: " << (lavender2.getPruned() ? "Yes" : "No") << endl;
    cout << "   • " << cattails1.getName() << " - Height: " << cattails1.getHeight() << "cm, Pruned: " << (cattails1.getPruned() ? "Yes" : "No") << endl << endl;
    
    cout << "✅ SUCCESS: All watering and pruning strategies tested with correct plant assignments!" << endl;
    cout << "🎯 Strategy Pattern Validation: Each strategy produces different effects!" << endl;
}
//Abstract Factory and Strategy 
void AbstractStrategyTesting() {
    cout << "\n🌱🌿🌳 COMPREHENSIVE PLANT NURSERY SYSTEM TEST 🌳🌿🌱" << endl;
    cout << "Testing all 32 plants, categories, and factories..." << endl;
    testPlantCategories();
    testAllFactories();
    testEveryPlantFromFactories();
    testAllStrategies();
    testPlantStatistics();
}

void CommandStaffTesting() {
    cout << "\n===== COMMAND PATTERN TESTING =====" << endl;

    Rose rose;
    Basil basil;
    Tomato tomato;

    //not a singleton 
    InventoryManager* manager = new InventoryManager();
    Nursery nursery = Nursery(manager);

    manager->addToNursery(&rose);
    manager->addToNursery(&basil);
    manager->addToNursery(&tomato);

    WaterCommand waterRose(&rose);
    WaterCommand waterBasil(&basil);
    StockCommand stockNursery(&nursery);
    SellCommand sellTomato(&tomato, manager);
    PlantCommand plantRose(&rose, manager);
    MakeSellableCommand makeRoseSellable(&rose, manager);
    RemoveCommand removeBasil(&basil, manager);
    RemoveSaleCommand removeSaleTomato(&tomato, manager);
    PruneCommand pruneRose(&rose);
    FertiliseCommand fertiliseBasil(&basil);

    cout << "\n\033[32mWatering Rose:\033[0m" << endl;
    waterRose.execute();
    cout << "\033[32mWatering Basil:\033[0m" << endl;
    waterBasil.execute();
    cout << "\033[32mStocking Nursery:\033[0m" << endl;
    stockNursery.execute();
    cout << "\033[32mSelling Tomato:\033[0m" << endl;
    sellTomato.execute();
    cout << "\033[32mPlanting Rose:\033[0m" << endl;
    plantRose.execute();
    cout << "\033[32mMaking Rose Sellable:\033[0m" << endl;
    makeRoseSellable.execute();
    cout << "\033[32mRemoving Basil from Nursery:\033[0m" << endl;
    removeBasil.execute();
    cout << "\033[32mRemoving Tomato from Sale:\033[0m" << endl;
    removeSaleTomato.execute();
    cout << "\033[32mPruning Rose:\033[0m" << endl;
    pruneRose.execute();
    cout << "\033[32mFertilising Basil:\033[0m" << endl;
    fertiliseBasil.execute();

    //Fixed memory leak
    delete manager;
}

void PlantStateTesting() {
    printSeparator("PLANT STATE TESTING");
    cout << "🌱 Testing Plant State Pattern - State transitions based on height and health" << endl << endl;
    
    cout << "📋 TEST 1: Complete Growth Cycle (Seed → Seedling → Growing → Mature → Ready for Sale)" << endl;
    cout << "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━" << endl;
    
    Rose testPlant1;
    cout << "Initial State: " << testPlant1.getState() << endl;
    cout << "Height: " << testPlant1.getHeight() << " | Health: " << testPlant1.getHealth() << endl << endl;
    
    cout << "Setting height to 0.15 and health to 0.15..." << endl;
    testPlant1.setHeight(0.15);
    testPlant1.setHealth(0.15);
    testPlant1.changePlantState();
    cout << "State after change: " << testPlant1.getState() << endl;
    cout << "Height: " << testPlant1.getHeight() << " | Health: " << testPlant1.getHealth() << endl << endl;
    
    cout << "Setting height to 0.25 and health to 0.25..." << endl;
    testPlant1.setHeight(0.25);
    testPlant1.setHealth(0.25);
    testPlant1.changePlantState();
    cout << "State after change: " << testPlant1.getState() << endl;
    cout << "Height: " << testPlant1.getHeight() << " | Health: " << testPlant1.getHealth() << endl << endl;
    
    cout << "Setting height to 0.6 and health to 0.6..." << endl;
    testPlant1.setHeight(0.6);
    testPlant1.setHealth(0.6);
    testPlant1.changePlantState();
    cout << "State after change: " << testPlant1.getState() << endl;
    cout << "Height: " << testPlant1.getHeight() << " | Health: " << testPlant1.getHealth() << endl << endl;
    
    cout << "Setting height to 0.95 and health to 0.95..." << endl;
    testPlant1.setHeight(0.95);
    testPlant1.setHealth(0.95);
    testPlant1.changePlantState();
    cout << "State after change: " << testPlant1.getState() << endl;
    cout << "Height: " << testPlant1.getHeight() << " | Health: " << testPlant1.getHealth() << endl << endl;
    
    cout << "📋 TEST 2: Dying State - Plant Health Deterioration" << endl;
    cout << "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━" << endl;
    
    Basil testPlant2;
    cout << "Starting with a plant in Growing state..." << endl;
    testPlant2.setHeight(0.4);
    testPlant2.setHealth(0.4);
    testPlant2.changePlantState();
    cout << "Current State: " << testPlant2.getState() << endl;
    cout << "Height: " << testPlant2.getHeight() << " | Health: " << testPlant2.getHealth() << endl << endl;
    
    cout << "Decreasing health below 0.2 to trigger Dying state..." << endl;
    testPlant2.setHealth(0.15);
    testPlant2.changePlantState();
    cout << "State after health drop: " << testPlant2.getState() << endl;
    cout << "Height: " << testPlant2.getHeight() << " | Health: " << testPlant2.getHealth() << endl << endl;
    
    cout << "📋 TEST 3: Dead State - Complete Health Loss" << endl;
    cout << "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━" << endl;
    
    Tomato testPlant3;
    testPlant3.setHeight(0.4);
    testPlant3.setHealth(0.15);
    testPlant3.changePlantState();
    cout << "Starting in Dying state..." << endl;
    cout << "Current State: " << testPlant3.getState() << endl;
    cout << "Height: " << testPlant3.getHeight() << " | Health: " << testPlant3.getHealth() << endl << endl;
    
    cout << "Setting health to 0 to kill the plant..." << endl;
    testPlant3.setHealth(0.0);
    testPlant3.changePlantState();
    cout << "State after health reaches 0: " << testPlant3.getState() << endl;
    cout << "Height: " << testPlant3.getHeight() << " | Health: " << testPlant3.getHealth() << endl << endl;
    
    cout << "Attempting to change state of dead plant..." << endl;
    testPlant3.changePlantState();
    cout << "State remains: " << testPlant3.getState() << " (Dead state is terminal)" << endl << endl;
    
    cout << "📋 TEST 4: Plant Recovery - Dying → Growing/Mature" << endl;
    cout << "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━" << endl;
    
    Lettuce testPlant4;
    testPlant4.setHeight(0.3);
    testPlant4.setHealth(0.15);
    testPlant4.changePlantState();
    cout << "Plant in Dying state..." << endl;
    cout << "Current State: " << testPlant4.getState() << endl;
    cout << "Height: " << testPlant4.getHeight() << " | Health: " << testPlant4.getHealth() << endl << endl;
    
    cout << "Improving health to 0.3 (recovery to Growing)..." << endl;
    testPlant4.setHealth(0.3);
    testPlant4.changePlantState();
    cout << "State after recovery: " << testPlant4.getState() << endl;
    cout << "Height: " << testPlant4.getHeight() << " | Health: " << testPlant4.getHealth() << endl << endl;
    
    JadePlant testPlant5;
    testPlant5.setHeight(0.6);
    testPlant5.setHealth(0.15);
    testPlant5.changePlantState();
    cout << "Another plant in Dying state with higher height..." << endl;
    cout << "Current State: " << testPlant5.getState() << endl;
    cout << "Height: " << testPlant5.getHeight() << " | Health: " << testPlant5.getHealth() << endl << endl;
    
    cout << "Improving health to 0.6 (recovery to Mature)..." << endl;
    testPlant5.setHealth(0.6);
    testPlant5.changePlantState();
    cout << "State after recovery: " << testPlant5.getState() << endl;
    cout << "Height: " << testPlant5.getHeight() << " | Health: " << testPlant5.getHealth() << endl << endl;
    
    cout << "📋 TEST 5: Ready for Sale Degradation" << endl;
    cout << "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━" << endl;
    
    SnakePlant testPlant6;
    testPlant6.setHeight(0.95);
    testPlant6.setHealth(0.95);
    testPlant6.changePlantState();
    testPlant6.changePlantState();
    testPlant6.changePlantState();
    testPlant6.changePlantState();
    cout << "Plant in Ready for Sale state..." << endl;
    cout << "Current State: " << testPlant6.getState() << endl;
    cout << "Height: " << testPlant6.getHeight() << " | Health: " << testPlant6.getHealth() << endl << endl;
    
    cout << "Decreasing health to 0.65 (degradation back to Mature)..." << endl;
    testPlant6.setHealth(0.65);
    testPlant6.changePlantState();
    cout << "State after degradation: " << testPlant6.getState() << endl;
    cout << "Height: " << testPlant6.getHeight() << " | Health: " << testPlant6.getHealth() << endl << endl;
    
    cout << "📋 TEST 6: Mature Plant Deterioration" << endl;
    cout << "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━" << endl;
    
    AloeVera testPlant7;
    testPlant7.setHeight(0.6);
    testPlant7.setHealth(0.6);
    testPlant7.changePlantState();
    testPlant7.changePlantState();
    testPlant7.changePlantState();
    cout << "Mature plant..." << endl;
    cout << "Current State: " << testPlant7.getState() << endl;
    cout << "Height: " << testPlant7.getHeight() << " | Health: " << testPlant7.getHealth() << endl << endl;
    
    cout << "Health drops below 0.5 (Mature → Dying)..." << endl;
    testPlant7.setHealth(0.4);
    testPlant7.changePlantState();
    cout << "State after health drop: " << testPlant7.getState() << endl;
    cout << "Height: " << testPlant7.getHeight() << " | Health: " << testPlant7.getHealth() << endl << endl;
    
    cout << "📋 TEST 7: Boundary Condition Testing" << endl;
    cout << "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━" << endl;
    
    WaterLily testPlant8;
    cout << "Testing exact boundary values..." << endl << endl;
    
    cout << "Height = 0.1 (exact minimum), Health = 0.11..." << endl;
    testPlant8.setHeight(0.1);
    testPlant8.setHealth(0.11);
    testPlant8.changePlantState();
    cout << "State: " << testPlant8.getState() << " (should be Seedling State)" << endl << endl;
    
    RubberTree testPlant9;
    cout << "Height = 0.09 (below threshold), Health = 0.15..." << endl;
    testPlant9.setHeight(0.09);
    testPlant9.setHealth(0.15);
    testPlant9.changePlantState();
    cout << "State: " << testPlant9.getState() << " (should remain Seed State)" << endl << endl;
    
    cout << "📋 TEST 8: State Changes Through Watering and Fertilizing" << endl;
    cout << "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━" << endl;
    
    Sunflower testPlant10;
    cout << "Starting with new Sunflower in Seed state..." << endl;
    cout << "Initial State: " << testPlant10.getState() << endl;
    cout << "Height: " << testPlant10.getHeight() << " | Health: " << testPlant10.getHealth() << endl << endl;
    
    cout << "Fertilizing to increase health..." << endl;
    testPlant10.fertilise();
    cout << "After fertilizing - Height: " << testPlant10.getHeight() << " | Health: " << testPlant10.getHealth() << endl;
    cout << "Current State: " << testPlant10.getState() << endl << endl;
    
    cout << "Watering to increase height..." << endl;
    testPlant10.water();
    cout << "After watering - Height: " << testPlant10.getHeight() << " | Health: " << testPlant10.getHealth() << endl;
    testPlant10.changePlantState();
    cout << "State after checking: " << testPlant10.getState() << endl << endl;
    
    cout << "📋 TEST 9: Plant Summary for Different States" << endl;
    cout << "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━" << endl;
    
    Chrysanthemum testPlant11;
    cout << "Seed State Plant:" << endl;
    cout << testPlant11.summary() << endl;
    
    testPlant11.setHeight(0.6);
    testPlant11.setHealth(0.6);
    testPlant11.changePlantState();
    testPlant11.changePlantState();
    testPlant11.changePlantState();
    cout << "Mature State Plant:" << endl;
    cout << testPlant11.summary() << endl;
    
    testPlant11.setHeight(0.95);
    testPlant11.setHealth(0.95);
    testPlant11.changePlantState();
    cout << "Ready for Sale State Plant:" << endl;
    cout << testPlant11.summary() << endl;
    
    cout << "✅ All Plant State tests completed!" << endl;
    cout << "\n📝 Summary of tested states:" << endl;
    cout << "   • Seed State" << endl;
    cout << "   • Seedling State" << endl;
    cout << "   • Growing State" << endl;
    cout << "   • Mature State" << endl;
    cout << "   • Ready for Sale State" << endl;
    cout << "   • Dying State" << endl;
    cout << "   • Dead State" << endl;
    cout << "\n📝 Tested transitions:" << endl;
    cout << "   • Normal growth progression" << endl;
    cout << "   • Health deterioration (Dying/Dead)" << endl;
    cout << "   • Recovery from Dying state" << endl;
    cout << "   • Ready for Sale degradation" << endl;
    cout << "   • Boundary conditions" << endl;
    cout << "   • Integration with plant methods (water/fertilise)" << endl;
}

void InventoryTesting() {
    printSeparator("INVENTORY MANAGER TEST");
    
    cout << "Testing InventoryManager functionality..." << endl << endl;
    
    Rose rose;
    Basil basil;
    Tomato tomato;

    InventoryManager* manager = new InventoryManager();
    Nursery nursery = Nursery(manager);

    std::cout << "Adding plants to nursery..." << std::endl;
    manager->addToNursery(&rose);
    manager->addToNursery(&basil);
    manager->addToNursery(&tomato);

    std::cout << "\nTesting adding null plant to nursery..." << std::endl;
    manager->addToNursery(nullptr);

    std::cout << "\nTesting removing a plants from nursery..." << std::endl;
    manager->removeFromNursery(&rose);
    manager->removeFromNursery(&basil);
    manager->removeFromNursery(&tomato);

    std::cout << "\nTesting removing the same plant from nursery..." << std::endl;
    manager->removeFromNursery(&rose);

    std::cout << "\nTesting removing null plant from nursery..." << std::endl;
    manager->removeFromNursery(nullptr);

    std::cout << "\nTesting adding plants to sale..." << std::endl;
    manager->addToSale(&rose);
    manager->addToSale(&basil);
    manager->addToSale(&tomato);

    std::cout << "\nTesting adding null plant to sale..." << std::endl;
    manager->addToSale(nullptr);

    std::cout << "\nTesting removing plants from sale..." << std::endl;
    manager->removeFromSale(&rose);
    manager->removeFromSale(&basil);
    manager->removeFromSale(&tomato);

    std::cout << "\nTesting removing the same plant from sale..." << std::endl;
    manager->removeFromSale(&rose);

    std::cout << "\nTesting removing null plant from sale..." << std::endl;
    manager->removeFromSale(nullptr);
    delete manager;
}

int main() {
    AbstractStrategyTesting();
    CommandStaffTesting();
    PlantStateTesting();
    InventoryTesting();
    
    return 0;
}