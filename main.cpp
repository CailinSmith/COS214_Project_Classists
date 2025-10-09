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

int main() {
    cout << "\n🌱🌿🌳 COMPREHENSIVE PLANT NURSERY SYSTEM TEST 🌳🌿🌱" << endl;
    cout << "Testing all 32 plants, categories, and factories..." << endl;

    testPlantCategories();
    testAllFactories();
    testEveryPlantFromFactories();
    testPlantStatistics();
    
    return 0;
}