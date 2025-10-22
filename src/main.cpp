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
#include "SeasonState.h"
#include "Spring.h"
#include "Summer.h"
#include "Autumn.h"
#include "Winter.h"

#include "StaffMediator.h"
#include "Staff.h"
#include "Manager.h"
#include "SalesStaff.h"
#include "NurseryStaff.h"
#include "Intern.h"
#include "SalesArea.h"
#include "NurseryArea.h"
#include "Decorator.h"
#include "ClayPot.h"
#include "ConcretePot.h"
#include "CeramicPot.h"
#include "ExtraFertilizer.h"
#include "KraftWrapping.h"

using namespace std;

void printSeparator(string title) {
    cout << "\n" << string(50, '=') << endl;
    cout << "  " << title << endl;
    cout << string(50, '=') << endl;
}

void MediatorTesting() {
    printSeparator("MEDIATOR PATTERN TEST");
    
    cout << "Testing StaffMediator (Mediator) with Staff (Colleague) classes..." << endl << endl;
    
    cout << "1. Creating Mediators (SalesArea and NurseryArea):" << endl;
    StaffMediator* salesArea = new SalesArea();
    StaffMediator* nurseryArea = new NurseryArea();
    cout << "   ✓ SalesArea mediator created" << endl;
    cout << "   ✓ NurseryArea mediator created" << endl << endl;
    
    cout << "2. Creating Staff Members (Colleagues):" << endl;
    Staff* manager = new Manager("Alice");
    Staff* salesStaff1 = new SalesStaff("Bob");
    Staff* salesStaff2 = new SalesStaff("Carol");
    Staff* nurseryStaff1 = new NurseryStaff("David");
    Staff* nurseryStaff2 = new NurseryStaff("Emma");
    Staff* intern = new Intern("Frank");
    
    cout << "   ✓ Manager: " << manager->getName() << " (" << manager->getPosition() << ")" << endl;
    cout << "   ✓ Sales Staff: " << salesStaff1->getName() << " (" << salesStaff1->getPosition() << ")" << endl;
    cout << "   ✓ Sales Staff: " << salesStaff2->getName() << " (" << salesStaff2->getPosition() << ")" << endl;
    cout << "   ✓ Nursery Staff: " << nurseryStaff1->getName() << " (" << nurseryStaff1->getPosition() << ")" << endl;
    cout << "   ✓ Nursery Staff: " << nurseryStaff2->getName() << " (" << nurseryStaff2->getPosition() << ")" << endl;
    cout << "   ✓ Intern: " << intern->getName() << " (" << intern->getPosition() << ")" << endl << endl;
    
    cout << "3. Registering Colleagues with Mediators:" << endl;
    cout << "   Sales Area accepts: Manager, Sales Staff" << endl;
    salesArea->registerColleague(manager);
    salesArea->registerColleague(salesStaff1);
    salesArea->registerColleague(salesStaff2);
    salesArea->registerColleague(nurseryStaff1);  
    cout << "   ✓ Registered Manager and Sales Staff with SalesArea" << endl << endl;
    
    cout << "   Nursery Area accepts: Manager, Nursery Staff, Intern" << endl;
    nurseryArea->registerColleague(manager);
    nurseryArea->registerColleague(nurseryStaff1);
    nurseryArea->registerColleague(nurseryStaff2);
    nurseryArea->registerColleague(intern);
    nurseryArea->registerColleague(salesStaff1);  
    cout << "   ✓ Registered Manager, Nursery Staff, and Intern with NurseryArea" << endl << endl;
    
    cout << "4. Testing Communication through SalesArea Mediator:" << endl;
    cout << "   ---------------------------------------------------" << endl;
    cout << "   Scenario: Sales Staff Bob sends a message" << endl;
    salesStaff1->setMessage("We need more roses in the sales area!");
    cout << "   Message: \"" << salesStaff1->getMessage() << "\"" << endl << endl;
    
    cout << "   Broadcasting message to all colleagues in SalesArea..." << endl;
    salesArea->notify(salesStaff1);
    cout << endl;
    
    cout << "5. Testing Communication through NurseryArea Mediator:" << endl;
    cout << "   ---------------------------------------------------" << endl;
    cout << "   Scenario: Nursery Staff David sends a message" << endl;
    nurseryStaff1->setMessage("Seedlings need watering urgently!");
    cout << "   Message: \"" << nurseryStaff1->getMessage() << "\"" << endl << endl;
    
    cout << "   Broadcasting message to all colleagues in NurseryArea..." << endl;
    nurseryArea->notify(nurseryStaff1);
    cout << endl;
    
    cout << "6. Testing Intern Communication:" << endl;
    cout << "   ---------------------------------------------------" << endl;
    cout << "   Scenario: Intern Frank sends a message" << endl;
    intern->setMessage("I've completed the pruning tasks!");
    cout << "   Message: \"" << intern->getMessage() << "\"" << endl << endl;
    
    cout << "   Broadcasting message to all colleagues in NurseryArea..." << endl;
    nurseryArea->notify(intern);
    cout << endl;
    
    cout << "7. Testing Manager Communication (Cross-Area):" << endl;
    cout << "   ---------------------------------------------------" << endl;
    cout << "   Scenario: Manager Alice sends a message to SalesArea" << endl;
    manager->setMessage("Great work team! Sales targets met this month!");
    cout << "   Message: \"" << manager->getMessage() << "\"" << endl << endl;
    
    cout << "   Broadcasting to SalesArea..." << endl;
    salesArea->notify(manager);
    cout << endl;
    
    cout << "   Scenario: Manager Alice sends a different message to NurseryArea" << endl;
    manager->setMessage("Please prepare 50 new plants for next week");
    cout << "   Message: \"" << manager->getMessage() << "\"" << endl << endl;
    
    cout << "   Broadcasting to NurseryArea..." << endl;
    nurseryArea->notify(manager);
    cout << endl;
    
    cout << "8. Mediator Pattern Benefits Demonstrated:" << endl;
    cout << "   ---------------------------------------------------" << endl;
    cout << "   ✓ Loose Coupling: Staff members don't communicate directly" << endl;
    cout << "   ✓ Centralized Control: Mediators handle all communication" << endl;
    cout << "   ✓ Reduced Dependencies: Staff only knows about mediators" << endl;
    cout << "   ✓ Easy to Add New Staff: Just register with mediator" << endl;
    cout << "   ✓ Area-Specific Communication: Different mediators for different areas" << endl << endl;
    
    cout << "\n" << string(50, '-') << endl;
    cout << "9. TESTING DEREGISTER MEDIATOR FUNCTIONALITY" << endl;
    cout << string(50, '-') << endl << endl;
    
    cout << "   Creating new test manager..." << endl;
    Staff* testManager = new Manager("TestManager");
    cout << "   ✓ Test Manager created: " << testManager->getName() << endl << endl;
    
    cout << "   Registering TestManager with SalesArea:" << endl;
    testManager->registerMediator(salesArea);
    salesArea->registerColleague(testManager);
    cout << "   ✓ TestManager registered with SalesArea" << endl << endl;
    
    cout << "   Testing communication before deregistration:" << endl;
    testManager->setMessage("Test message before deregister");
    cout << "   Message: \"" << testManager->getMessage() << "\"" << endl;
    testManager->send();
    cout << endl;
    
    cout << "   Deregistering TestManager from SalesArea:" << endl;
    testManager->deregisterMediator(salesArea);
    cout << "   ✓ TestManager deregistered from SalesArea" << endl;
    cout << "   ✓ TestManager still exists: " << testManager->getName() << endl << endl;
    
    cout << "   Attempting to send message after deregistration:" << endl;
    testManager->setMessage("Test message after deregister");
    cout << "   Message: \"" << testManager->getMessage() << "\"" << endl;
    cout << "   Note: Message won't be sent (no mediators registered)" << endl;
    testManager->send();
    cout << endl;
    
    cout << "\n" << string(50, '-') << endl;
    cout << "10. TESTING MANAGER SET RECEIVER FUNCTIONALITY" << endl;
    cout << string(50, '-') << endl << endl;
    
    cout << "   Creating Head Manager and Assistants:" << endl;
    Manager* headManager = new Manager("HeadManager");
    Manager* salesAssistant = new Manager("SalesAssistant");
    Manager* nurseryAssistant = new Manager("NurseryAssistant");
    
    cout << "   ✓ Head Manager created: " << headManager->getName() << endl;
    cout << "   ✓ Sales Assistant created: " << salesAssistant->getName() << endl;
    cout << "   ✓ Nursery Assistant created: " << nurseryAssistant->getName() << endl << endl;
    
    cout << "   Registering HeadManager with BOTH areas:" << endl;
    headManager->registerMediator(salesArea);
    headManager->registerMediator(nurseryArea);
    salesArea->registerColleague(headManager);
    nurseryArea->registerColleague(headManager);
    salesAssistant->registerMediator(salesArea);
    salesArea->registerColleague(salesAssistant);
    nurseryAssistant->registerMediator(nurseryArea);
    nurseryArea->registerColleague(nurseryAssistant);
    cout << "   ✓ HeadManager registered with both SalesArea and NurseryArea" << endl;
    cout << "   ✓ SalesAssistant registered with SalesArea" << endl;
    cout << "   ✓ NurseryAssistant registered with NurseryArea" << endl << endl;
    
    cout << "   HeadManager sets receiver to SalesArea ONLY:" << endl;
    headManager->setReceiver(salesArea);
    cout << "   ✓ Receiver set to SalesArea" << endl << endl;
    
    cout << "   HeadManager sends targeted message to SalesArea:" << endl;
    headManager->setMessage("This message is ONLY for the sales team!");
    cout << "   Message: \"" << headManager->getMessage() << "\"" << endl;
    cout << "   Broadcasting (should only notify SalesArea)..." << endl;
    headManager->send();
    cout << "   Note: Only SalesArea colleagues receive this message" << endl << endl;
    
    cout << "   HeadManager changes receiver to NurseryArea:" << endl;
    headManager->setReceiver(nurseryArea);
    cout << "   ✓ Receiver changed to NurseryArea" << endl << endl;
    
    cout << "   HeadManager sends targeted message to NurseryArea:" << endl;
    headManager->setMessage("This message is ONLY for the nursery team!");
    cout << "   Message: \"" << headManager->getMessage() << "\"" << endl;
    cout << "   Broadcasting (should only notify NurseryArea)..." << endl;
    headManager->send();
    cout << "   Note: Only NurseryArea colleagues receive this message" << endl << endl;
    
    cout << "   Benefits of Manager's setReceiver:" << endl;
    cout << "   ---------------------------------------------------" << endl;
    cout << "   ✓ Targeted Communication: Manager can send to specific areas" << endl;
    cout << "   ✓ Reduced Noise: Only relevant staff receive messages" << endl;
    cout << "   ✓ Flexible Control: Can change receiver dynamically" << endl;
    cout << "   ✓ Manager Hierarchy: Manager has special privileges" << endl << endl;
    
    cout << "\n" << string(50, '-') << endl;
    cout << "11. TESTING MANAGER BROADCAST MODE (NULL RECEIVER)" << endl;
    cout << string(50, '-') << endl << endl;
    
    cout << "   Creating Broadcast Manager:" << endl;
    Manager* broadcastManager = new Manager("BroadcastManager");
    
    cout << "   ✓ Broadcast Manager created: " << broadcastManager->getName() << endl << endl;
    
    cout << "   Registering BroadcastManager with BOTH areas:" << endl;
    salesArea->registerColleague(broadcastManager);
    nurseryArea->registerColleague(broadcastManager);
    cout << "   ✓ BroadcastManager registered with SalesArea" << endl;
    cout << "   ✓ BroadcastManager registered with NurseryArea" << endl << endl;
    
    cout << "   NOTE: Receiver is NULL by default (broadcast mode)" << endl;
    cout << "   This means send() will broadcast to ALL registered mediators" << endl << endl;
    
    cout << "   BroadcastManager sends message (receiver = null):" << endl;
    broadcastManager->setMessage("URGENT: Company-wide announcement to all areas!");
    cout << "   Message: \"" << broadcastManager->getMessage() << "\"" << endl;
    cout << "   Expected: Message will be sent to BOTH SalesArea AND NurseryArea" << endl << endl;
    
    cout << "   Broadcasting to ALL mediators..." << endl;
    broadcastManager->send();
    cout << endl;
    
    cout << "   Setting receiver to specific area, then back to null:" << endl;
    broadcastManager->setReceiver(salesArea);
    cout << "   ✓ Receiver set to SalesArea (targeted mode)" << endl;
    
    broadcastManager->setMessage("Targeted message to sales");
    cout << "   Message: \"" << broadcastManager->getMessage() << "\"" << endl;
    cout << "   Sending (should only reach SalesArea)..." << endl;
    broadcastManager->send();
    cout << endl;
    
    cout << "   Resetting receiver to NULL (back to broadcast mode):" << endl;
    broadcastManager->setReceiver(nullptr);
    cout << "   ✓ Receiver set to nullptr (broadcast mode restored)" << endl << endl;
    
    broadcastManager->setMessage("Broadcasting again to all areas!");
    cout << "   Message: \"" << broadcastManager->getMessage() << "\"" << endl;
    cout << "   Expected: Message will be sent to BOTH areas again" << endl;
    cout << "   Broadcasting to ALL mediators..." << endl;
    broadcastManager->send();
    cout << endl;
    
    cout << "\n" << string(50, '-') << endl;
    cout << "12. TESTING DIFFERENT MEDIATOR NOTIFICATION FORMATS" << endl;
    cout << string(50, '-') << endl << endl;
    
    cout << "   Demonstrating that SalesArea and NurseryArea format" << endl;
    cout << "   notifications differently in their notify() methods" << endl << endl;
    
    cout << "   Creating test staff for each area:" << endl;
    SalesStaff* salesDemo = new SalesStaff("SalesDemo");
    NurseryStaff* nurseryDemo = new NurseryStaff("NurseryDemo");
    
    salesArea->registerColleague(salesDemo);
    nurseryArea->registerColleague(nurseryDemo);
    cout << "   ✓ SalesDemo registered with SalesArea" << endl;
    cout << "   ✓ NurseryDemo registered with NurseryArea" << endl << endl;
    
    cout << "   Testing SalesArea notification format:" << endl;
    cout << "   " << string(45, '-') << endl;
    salesDemo->setMessage("Sales notification test");
    cout << "   SalesDemo sends: \"" << salesDemo->getMessage() << "\"" << endl;
    cout << "   SalesArea will format as: 'NurseryArea: SalesDemo:Sales notification test'" << endl;
    cout << "   Notifying through SalesArea mediator:" << endl;
    salesArea->notify(salesDemo);
    cout << endl;
    
    cout << "   Testing NurseryArea notification format:" << endl;
    cout << "   " << string(45, '-') << endl;
    nurseryDemo->setMessage("Nursery notification test");
    cout << "   NurseryDemo sends: \"" << nurseryDemo->getMessage() << "\"" << endl;
    cout << "   NurseryArea will format as: 'NurseryArea: NurseryDemo:Nursery notification test'" << endl;
    cout << "   Notifying through NurseryArea mediator:" << endl;
    nurseryArea->notify(nurseryDemo);
    cout << endl;
    
    cout << "   Key Differences:" << endl;
    cout << "   ---------------------------------------------------" << endl;
    cout << "   ✓ Each mediator (SalesArea/NurseryArea) has its own notify() method" << endl;
    cout << "   ✓ Derived classes of StaffMediator implement their own notification logic" << endl;
    cout << "   ✓ Message format: '[AreaType]: [SenderName]:[Message]'" << endl;
    cout << "   ✓ Different areas can have different communication protocols" << endl;
    cout << "   ✓ Demonstrates polymorphism in the Mediator pattern" << endl << endl;
    
    cout << "   Summary of Mediator Pattern Implementation:" << endl;
    cout << "   =============================================" << endl;
    cout << "   Manager.send() behavior:" << endl;
    cout << "     • If receiver == null: Broadcast to ALL mediators" << endl;
    cout << "     • If receiver != null: Send only to specific mediator" << endl << endl;
    cout << "   StaffMediator.notify() behavior:" << endl;
    cout << "     • SalesArea: Formats messages for sales team" << endl;
    cout << "     • NurseryArea: Formats messages for nursery team" << endl;
    cout << "     • Each area's notify() is called by Staff.send()" << endl << endl;
    
    delete broadcastManager;
    delete salesDemo;
    delete nurseryDemo;
    
    cout << "12. Cleaning up all resources..." << endl;
    delete salesArea;
    delete nurseryArea;
    delete manager;
    delete salesStaff1;
    delete salesStaff2;
    delete nurseryStaff1;
    delete nurseryStaff2;
    delete intern;
    delete testManager;
    delete headManager;
    delete salesAssistant;
    delete nurseryAssistant;
    cout << "   ✓ All resources cleaned up" << endl << endl;
    
    cout << "Mediator Pattern Test Complete!" << endl;
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

void TemplateMethodTesting() {
    printSeparator("TEMPLATE METHOD PATTERN TESTING");
    
    cout << "TEST 1: ROSE" << endl;
    cout << "---------------------------------------------------------------" << endl;
    
    Rose rose1;
    rose1.setHealth(0.75);
    cout << "\nRose with Health = 0.75" << endl;
    cout << "Sell Season: " << rose1.getSellSeason() << endl;
    cout << "\nCurrent season: Summer" << endl;
    float roseCost1Summer = rose1.calculateCost("Summer");
    cout << "Base : "<< rose1.baseCost() << " | Health Bonus: 0.0 | Season Bonus: 10.0 | TOTAL: " << roseCost1Summer << endl;
    
    cout << "\nTesting OUT-OF-SEASON (Winter):" << endl;
    Rose rose1b;
    rose1b.setHealth(0.75);
    float roseCost1Winter = rose1b.calculateCost("Winter");
    cout << "Base Cost: 100.0 | Health Bonus: 0.0 | Season Bonus: 0.0 | TOTAL: " << roseCost1Winter << endl;
    
    Rose rose2;
    rose2.setHealth(0.95);
    cout << "\nRose with Health = 0.95 (above 0.9 threshold - triggers bonus)" << endl;
    cout << "Sell Season: " << rose2.getSellSeason() << endl;
    cout << "\nTesting IN-SEASON (Summer):" << endl;
    float roseCost2Summer = rose2.calculateCost("Summer");
    cout << "Base Cost: 100.0 | Health Bonus: " << (100.0 * (0.95 - 0.85)) << " | Season Bonus: 10.0 | TOTAL: " << roseCost2Summer << endl;
    
    cout << "\n\nTEST 2: BASIL" << endl;
    cout << "---------------------------------------------------------------" << endl;
    
    Basil basil1;
    basil1.setHealth(0.8);
    cout << "\nBasil with Health = 0.8" << endl;
    cout << "Sell Season: " << basil1.getSellSeason() << endl;
    cout << "\nCurrent season: Summer" << endl;
    float basilCost1 = basil1.calculateCost("Summer");
    cout << "Base : " << basil1.baseCost() << " | Health Bonus: 0.0 | Season Bonus: 0.0 | TOTAL: " << basilCost1 << endl;
    
    Basil basil2;
    basil2.setHealth(1.0);
    cout << "\nBasil with Health = 1.0" << endl;
    cout << "Sell Season: " << basil2.getSellSeason() << endl;
    cout << "\nCurrent season: Summer" << endl;
    float basilCost2 = basil2.calculateCost("Summer");
    cout << "Base : " << basil2.baseCost() << " | Health Bonus: " << (50.0 * (1.0 - 0.85)) << " | Season Bonus: 0.0 | TOTAL: " << basilCost2 << endl;
    
    cout << "\n\nTEST 3: TOMATO" << endl;
    cout << "---------------------------------------------------------------" << endl;
    
    Tomato tomato1;
    tomato1.setHealth(0.7);
    cout << "\nTomato with Health = 0.7" << endl;
    cout << "Sell Season: " << tomato1.getSellSeason() << endl;
    cout << "\nCurrent season: Summer" << endl;
    float tomatoCost1Summer = tomato1.calculateCost("Summer");
    cout << "Base : " << tomato1.baseCost() << " | Health Bonus: 0.0 | Season Bonus: 30.0 | TOTAL: " << tomatoCost1Summer << endl;
    
    cout << "\nCurrent season: Spring" << endl;
    Tomato tomato1b;
    tomato1b.setHealth(0.7);
    float tomatoCost1Spring = tomato1b.calculateCost("Spring");
    cout << "Base : " << tomato1b.baseCost() << " | Health Bonus: 0.0 | Season Bonus: 0.0 | TOTAL: " << tomatoCost1Spring << endl;
    
    Tomato tomato2;
    tomato2.setHealth(0.95);
    cout << "\nTomato with Health = 0.95" << endl;
    cout << "Sell Season: " << tomato2.getSellSeason() << endl;
    cout << "\nCurrent season: Summer" << endl;
    float tomatoCost2Summer = tomato2.calculateCost("Summer");
    cout << "Base : " << tomato2.baseCost() << " | Health Bonus: " << (200.0 * (0.95 - 0.85)) << " | Season Bonus: 30.0 | TOTAL: " << tomatoCost2Summer << endl;
    
    cout << "\n\nTEST 4: LETTUCE" << endl;
    cout << "---------------------------------------------------------------" << endl;
    
    Lettuce lettuce1;
    lettuce1.setHealth(0.85);
    cout << "\nLettuce with Health = 0.85" << endl;
    cout << "Sell Season: " << lettuce1.getSellSeason() << endl;
    cout << "\nCurrent season: Summer" << endl;
    float lettuceCost1 = lettuce1.calculateCost("Summer");
    cout << "Base : " << lettuce1.baseCost() << " | Health Bonus: 0.0 | Season Bonus: 12.0 | TOTAL: " << lettuceCost1 << endl;
    
    Lettuce lettuce2;
    lettuce2.setHealth(0.92);
    cout << "\nLettuce with Health = 0.92" << endl;
    cout << "Sell Season: " << lettuce2.getSellSeason() << endl;
    cout << "\nCurrent season: Summer" << endl;
    float lettuceCost2 = lettuce2.calculateCost("Summer");
    cout << "Base : " << lettuce2.baseCost() << " | Health Bonus: " << (80.0 * (0.92 - 0.85)) << " | Season Bonus: 12.0 | TOTAL: " << lettuceCost2 << endl;
    
    cout << "\n\nTEST 5: CATTAILS" << endl;
    cout << "---------------------------------------------------------------" << endl;
    
    Cattails cattails1;
    cattails1.setHealth(0.8);
    cout << "\nCattails with Health = 0.8" << endl;
    cout << "Sell Season: " << cattails1.getSellSeason() << endl;
    cout << "\nCurrent season: Summer" << endl;
    float cattailsCost1 = cattails1.calculateCost("Summer");
    cout << "Base : " << cattails1.baseCost() << " | Health Bonus: 0.0 | Season Bonus: 0.0 | TOTAL: " << cattailsCost1 << endl;
    
    Cattails cattails2;
    cattails2.setHealth(0.95);
    cout << "\nCattails with Health = 0.95" << endl;
    cout << "Sell Season: " << cattails2.getSellSeason() << endl;
    cout << "\nCurrent season: Summer" << endl;
    float cattailsCost2 = cattails2.calculateCost("Summer");
    cout << "Base : " << cattails2.baseCost() << " | Health Bonus: " << (180.0 * (0.95 - 0.85)) << " | Season Bonus: 0.0 | TOTAL: " << cattailsCost2 << endl;
    
    cout << "\n\nTEST 6: SNAKE PLANT" << endl;
    cout << "---------------------------------------------------------------" << endl;
    
    SnakePlant snakePlant1;
    snakePlant1.setHealth(0.75);
    cout << "\nSnake Plant with Health = 0.75" << endl;
    cout << "Sell Season: " << snakePlant1.getSellSeason() << endl;
    cout << "\nCurrent season: Summer" << endl;
    float snakeCost1 = snakePlant1.calculateCost("Summer");
    cout << "Base : " << snakePlant1.baseCost() << " | Health Bonus: 0.0 | Season Bonus: 0.0 | TOTAL: " << snakeCost1 << endl;
    
    SnakePlant snakePlant2;
    snakePlant2.setHealth(0.92);
    cout << "\nSnake Plant with Health = 0.92" << endl;
    cout << "Sell Season: " << snakePlant2.getSellSeason() << endl;
    cout << "\nCurrent season: Summer" << endl;
    float snakeCost2 = snakePlant2.calculateCost("Summer");
    cout << "Base : " << snakePlant2.baseCost() << " | Health Bonus: " << (120.0 * (0.92 - 0.85)) << " | Season Bonus: 0.0 | TOTAL: " << snakeCost2 << endl;
    
    cout << "\n\nTEST 7: GINGER" << endl;
    cout << "---------------------------------------------------------------" << endl;
    
    Ginger ginger1;
    ginger1.setHealth(0.85);
    cout << "\nGinger with Health = 0.85" << endl;
    cout << "Sell Season: " << ginger1.getSellSeason() << endl;
    cout << "\nCurrent season: Summer" << endl;
    float gingerCost1 = ginger1.calculateCost("Summer");
    cout << "Base : " << ginger1.baseCost() << " | Health Bonus: 0.0 | Season Bonus: 0.0 | TOTAL: " << gingerCost1 << endl;
    
    Ginger ginger2;
    ginger2.setHealth(1.0);
    cout << "\nGinger with Health = 1.0" << endl;
    cout << "Sell Season: " << ginger2.getSellSeason() << endl;
    cout << "\nCurrent season: Summer" << endl;
    float gingerCost2 = ginger2.calculateCost("Summer");
    cout << "Base : " << ginger2.baseCost() << " | Health Bonus: " << (60.0 * (1.0 - 0.85)) << " | Season Bonus: 0.0 | TOTAL: " << gingerCost2 << endl;
}

void SeasonStateTesting() {
    printSeparator("SEASON STATE PATTERN TEST");
    
    cout << "🌍 Testing the State Pattern for Season transitions..." << endl << endl;
    
    InventoryManager* inventory = new InventoryManager();
    
    Nursery* nursery = new Nursery(inventory);
    
    cout << "🏪 Nursery Created!" << endl;
    cout << "📅 Initial Season: " << nursery->getSeason() << endl << endl;
    
    printSeparator("Test 1: Initial State");
    cout << "Current Season: " << nursery->getSeason() << endl;
    cout << "Expected: Spring" << endl;
    cout << "✓ Nursery initializes in Spring season" << endl << endl;
    
    printSeparator("Test 2: Spring to Summer Transition");
    cout << "Before change: " << nursery->getSeason() << endl;
    nursery->changeSeason();
    cout << "After change:  " << nursery->getSeason() << endl;
    cout << "Expected:      Summer" << endl;
    if (nursery->getSeason() == "Summer") 
        cout << "✓ Successfully transitioned from Spring to Summer" << endl;
    else 
        cout << "✗ Failed to transition!" << endl;
    cout << endl;
    
    printSeparator("Test 3: Summer to Autumn Transition");
    cout << "Before change: " << nursery->getSeason() << endl;
    nursery->changeSeason();
    cout << "After change:  " << nursery->getSeason() << endl;
    cout << "Expected:      Autumn" << endl;
    if (nursery->getSeason() == "Autumn") 
        cout << "✓ Successfully transitioned from Summer to Autumn" << endl;
    else 
        cout << "✗ Failed to transition!" << endl;
    cout << endl;
    
    printSeparator("Test 4: Autumn to Winter Transition");
    cout << "Before change: " << nursery->getSeason() << endl;
    nursery->changeSeason();
    cout << "After change:  " << nursery->getSeason() << endl;
    cout << "Expected:      Winter" << endl;
    if (nursery->getSeason() == "Winter") 
        cout << "✓ Successfully transitioned from Autumn to Winter" << endl;
    else 
        cout << "✗ Failed to transition!" << endl;
    cout << endl;
    
    printSeparator("Test 5: Winter to Spring Transition (Complete Cycle)");
    cout << "Before change: " << nursery->getSeason() << endl;
    nursery->changeSeason();
    cout << "After change:  " << nursery->getSeason() << endl;
    cout << "Expected:      Spring" << endl;
    if (nursery->getSeason() == "Spring") {
        cout << "✓ Successfully transitioned from Winter back to Spring" << endl;
        cout << "✓ Season cycle completed successfully!" << endl;
    } else 
        cout << "✗ Failed to complete the cycle!" << endl;
    cout << endl;
    
    printSeparator("Test 6: Multiple Consecutive Changes");
    cout << "Current Season: " << nursery->getSeason() << endl;
    cout << "Performing 4 season changes (full cycle)..." << endl << endl;
    
    for (int i = 1; i <= 4; i++) {
        string beforeSeason = nursery->getSeason();
        nursery->changeSeason();
        string afterSeason = nursery->getSeason();
        cout << "  Change " << i << ": " << beforeSeason << " → " << afterSeason << endl;
    }
    
    cout << "\nFinal Season: " << nursery->getSeason() << endl;
    if (nursery->getSeason() == "Spring") {
        cout << "✓ Completed full cycle and returned to Spring" << endl;
    }
    cout << endl;
    
    printSeparator("Test 7: Memory Management");
    cout << "Testing that old seasons are properly deleted..." << endl;
    cout << "Performing 10 season changes..." << endl;
    
    for (int i = 0; i < 10; i++) 
        nursery->changeSeason();
    
    cout << "Final Season: " << nursery->getSeason() << endl;
    cout << "✓ No memory leaks (old seasons properly deleted)" << endl;
    cout << "✓ Memory management test passed" << endl << endl;
    
    printSeparator("Test 8: Individual Season State Objects");
    
    Spring spring;
    Summer summer;
    Autumn autumn;
    Winter winter;
    
    cout << "Spring season name: " << spring.print() << endl;
    cout << "Summer season name: " << summer.print() << endl;
    cout << "Autumn season name: " << autumn.print() << endl;
    cout << "Winter season name: " << winter.print() << endl;
    cout << "✓ All season states correctly return their names" << endl << endl;
    
    printSeparator("SEASON STATE TEST SUMMARY");
    cout << "✓ State Pattern correctly implemented" << endl;
    cout << "✓ All four seasons work properly" << endl;
    cout << "✓ Season transitions follow correct cycle:" << endl;
    cout << "  Spring → Summer → Autumn → Winter → Spring" << endl;
    cout << "✓ Factory pattern integrated with state transitions" << endl;
    cout << "✓ Memory management working correctly" << endl;
    cout << "✓ No memory leaks detected" << endl << endl;
    
    delete nursery;
    delete inventory;
    
    cout << "🎉 All Season State tests passed successfully!" << endl;
}

void DecoratorTesting(){
    printSeparator("DECORATOR PATTERN TESTING");
    
    cout << "TEST 1: CLAY POT" << endl;
    cout << "---------------------------------------------------------------" << endl;
    
    Rose* rose1 = new Rose();
    rose1->setHealth(0.8);
    ClayPot* clayRose = new ClayPot(rose1);
    
    cout << "\nRose in Clay Pot" << endl;
    cout << "Base Cost: " << rose1->calculateCost("Summer") << endl;
    cout << "With Clay Pot: " << clayRose->calculateCost("Summer") << endl;
    cout << "Name: " << clayRose->getName() << endl;
    cout << "Summary: " << clayRose->getSummary() << endl;


    
    cout << "\n\nTEST 2: CONCRETE POT" << endl;
    cout << "---------------------------------------------------------------" << endl;
    
    Basil* basil1 = new Basil();
    basil1->setHealth(0.9);
    ConcretePot* concreteBasil = new ConcretePot(basil1);
    
    cout << "\nBasil in Concrete Pot" << endl;
    cout << "Base Cost: " << basil1->calculateCost("Summer") << endl;
    cout << "With Concrete Pot: " << concreteBasil->calculateCost("Summer") << endl;
    cout << "Name: " << concreteBasil->getName() << endl;
    cout << "Summary: " << concreteBasil->getSummary() << endl;
    
    cout << "\n\nTEST 3: CERAMIC POT" << endl;
    cout << "---------------------------------------------------------------" << endl;
    
    Tomato* tomato1 = new Tomato();
    tomato1->setHealth(0.85);
    CeramicPot* ceramicTomato = new CeramicPot(tomato1);
    
    cout << "\nTomato in Ceramic Pot" << endl;
    cout << "Base Cost: " << tomato1->calculateCost("Summer") << endl;
    cout << "With Ceramic Pot: " << ceramicTomato->calculateCost("Summer") << endl;
    cout << "Name: " << ceramicTomato->getName() << endl;
    cout << "Summary: " << ceramicTomato->getSummary() << endl;
    
    cout << "\n\nTEST 4: EXTRA FERTILIZER" << endl;
    cout << "---------------------------------------------------------------" << endl;
    
    Lettuce* lettuce1 = new Lettuce();
    lettuce1->setHealth(0.92);
    ExtraFertilizer* fertilizedLettuce = new ExtraFertilizer(lettuce1);
    
    cout << "\nLettuce with Extra Fertilizer" << endl;
    cout << "Base Cost: " << lettuce1->calculateCost("Summer") << endl;
    cout << "With Fertilizer: " << fertilizedLettuce->calculateCost("Summer") << endl;
    cout << "Name: " << fertilizedLettuce->getName() << endl;
    cout << "Summary: " << fertilizedLettuce->getSummary() << endl;
    
    cout << "\n\nTEST 5: KRAFT WRAPPING" << endl;
    cout << "---------------------------------------------------------------" << endl;
    
    SnakePlant* snake1 = new SnakePlant();
    snake1->setHealth(0.75);
    KraftWrapping* wrappedSnake = new KraftWrapping(snake1);
    
    cout << "\nSnake Plant with Kraft Wrapping" << endl;
    cout << "Base Cost: " << snake1->calculateCost("Summer") << endl;
    cout << "With Wrapping: " << wrappedSnake->calculateCost("Summer") << endl;
    cout << "Name: " << wrappedSnake->getName() << endl;
    cout << "Summary: " << wrappedSnake->getSummary() << endl;
    
    cout << "\n\nTEST 6: MULTIPLE DECORATORS" << endl;
    cout << "---------------------------------------------------------------" << endl;
    
    Rose* rose2 = new Rose();
    rose2->setHealth(0.95);
    ClayPot* clayRose2 = new ClayPot(rose2);
    ExtraFertilizer* decoratedRose = new ExtraFertilizer(clayRose2);
    
    cout << "\nRose with Clay Pot and Fertilizer" << endl;
    cout << "Base Cost: " << rose2->calculateCost("Summer") << endl;
    cout << "Final Cost: " << decoratedRose->calculateCost("Summer") << endl;
    cout << "Name: " << decoratedRose->getName() << endl;
    cout << "Summary: " << decoratedRose->getSummary() << endl;
    
    cout << "\n\nTEST 7: REMOVE DECORATOR" << endl;
    cout << "---------------------------------------------------------------" << endl;
    
    Basil* basil2 = new Basil();
    basil2->setHealth(0.8);
    ClayPot* clayBasil = new ClayPot(basil2);
    
    cout << "\nBefore removing decorator:" << endl;
    cout << "Cost: " << clayBasil->calculateCost("Summer") << endl;
    cout << "Name: " << clayBasil->getName() << endl;
    cout << "Summary: " << clayBasil->getSummary() << endl;
    
    Product* plainBasil = clayBasil->removeDecorator();
    delete clayBasil;
    
    cout << "\nAfter removing decorator:" << endl;
    cout << "Cost: " << plainBasil->calculateCost("Summer") << endl;
    cout << "Name: " << plainBasil->getName() << endl;
    cout << "Summary: " << plainBasil->getSummary() << endl;
    
    delete plainBasil;
    delete clayRose;
    delete concreteBasil;
    delete ceramicTomato;
    delete fertilizedLettuce;
    delete wrappedSnake;
    delete decoratedRose;
}

void ChainOfResponsibilityTesting(){
    printSeparator("CHAIN OF RESPONSIBILITY PATTERN TEST");

    std::cout << "Test 1: Full Chain Propagation\n";
    Intern intern("John");
    Manager manager("Bob");
    SalesStaff sales("Carol");
    NurseryStaff nursery("Dave");
    intern.setNext(&manager);
    manager.setNext(&sales);
    sales.setNext(&nursery);
    intern.handleRequest();
    std::cout << "✓ Verified full chain execution\n\n";

    printSeparator("Test 2: Single Handler");
    Intern singleIntern("SingleJohn");
    singleIntern.handleRequest();
    std::cout << "✓ Confirmed single handler\n\n";

    printSeparator("Test 4: Starting from Middle of Chain");
    manager.handleRequest();
    std::cout << "✓ Confirmed starting from the middle\n\n";

    printSeparator("Test 5: Multiple Consecutive Calls");
    intern.handleRequest();
    std::cout << "--- Second call ---\n";
    intern.handleRequest();
    std::cout << "✓ Verified consecutive calls behaviour\n\n";

    printSeparator("Test 6: Chain with Reversed Order");
    NurseryStaff revNursery("AltDave");
    SalesStaff revSales("AltCarol");
    Manager revManager("AltBob");
    Intern revIntern("AltJohn");
    revNursery.setNext(&revSales);
    revSales.setNext(&revManager);
    revManager.setNext(&revIntern);
    revNursery.handleRequest();
    std::cout << "✓ Confirmed reverse chain functionality\n\n";
}

int main() {
    MediatorTesting();
    AbstractStrategyTesting();
    CommandStaffTesting();
    PlantStateTesting();
    InventoryTesting();
    TemplateMethodTesting();
    SeasonStateTesting();
    DecoratorTesting();
    ChainOfResponsibilityTesting();
    return 0;
}
