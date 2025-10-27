#include "doctest.h"
#include "Rose.h"
#include "Basil.h"
#include "Tomato.h"
#include "Lettuce.h"
#include "SnakePlant.h"
#include "ClayPot.h"
#include "ConcretePot.h"
#include "CeramicPot.h"
#include "ExtraFertilizer.h"
#include "KraftWrapping.h"

TEST_CASE("Decorator: Clay Pot functionality") {
    Rose* rose = new Rose();
    rose->setHealth(0.8);
    float baseCost = rose->calculateCost("Summer");
    ClayPot* clayRose = new ClayPot(rose);
    
    CHECK(clayRose != nullptr);
    CHECK(clayRose->calculateCost("Summer") == baseCost + 50.0);
    CHECK(clayRose->getName() == "Rose, in a Clay Pot");
    
    delete clayRose;
}

TEST_CASE("Decorator: Concrete Pot functionality") {
    Basil* basil = new Basil();
    basil->setHealth(0.9);
    float baseCost = basil->calculateCost("Summer");
    ConcretePot* concreteBasil = new ConcretePot(basil);
    
    CHECK(concreteBasil != nullptr);
    CHECK(concreteBasil->calculateCost("Summer") == baseCost + 60.0);
    CHECK(concreteBasil->getName() == "Basil, in a Concrete Pot");
    
    delete concreteBasil;
}

TEST_CASE("Decorator: Ceramic Pot functionality") {
    Tomato* tomato = new Tomato();
    tomato->setHealth(0.85);
    float baseCost = tomato->calculateCost("Summer");
    CeramicPot* ceramicTomato = new CeramicPot(tomato);
    
    CHECK(ceramicTomato != nullptr);
    CHECK(ceramicTomato->calculateCost("Summer") == baseCost + 80.0);
    CHECK(ceramicTomato->getName() == "Tomato, in a Ceramic Pot");
    
    delete ceramicTomato;
}

TEST_CASE("Decorator: Extra Fertilizer functionality") {
    Lettuce* lettuce = new Lettuce();
    lettuce->setHealth(0.92);
    float baseCost = lettuce->calculateCost("Summer");
    ExtraFertilizer* fertilizedLettuce = new ExtraFertilizer(lettuce);
    
    CHECK(fertilizedLettuce != nullptr);
    CHECK(fertilizedLettuce->calculateCost("Summer") == doctest::Approx(baseCost + 80.0));
    CHECK(fertilizedLettuce->getName() == "Lettuce, with extra fertilizer");
    
    delete fertilizedLettuce;
}

TEST_CASE("Decorator: Kraft Wrapping functionality") {
    SnakePlant* snake = new SnakePlant();
    snake->setHealth(0.75);
    float baseCost = snake->calculateCost("Summer");
    KraftWrapping* wrappedSnake = new KraftWrapping(snake);
    
    CHECK(wrappedSnake != nullptr);
    CHECK(wrappedSnake->calculateCost("Summer") == baseCost + 20.0);
    CHECK(wrappedSnake->getName() == "SnakePlant with kraft wrapping");
    
    delete wrappedSnake;
}

TEST_CASE("Decorator: Multiple decorators chain correctly") {
    Rose* rose = new Rose();
    rose->setHealth(0.95);
    float baseCost = rose->calculateCost("Summer");
    ClayPot* clayRose = new ClayPot(rose);
    ExtraFertilizer* decoratedRose = new ExtraFertilizer(clayRose);
    
    float finalCost = decoratedRose->calculateCost("Summer");
    CHECK(finalCost == baseCost + 50.0 + 80.0); 
    string finalName = decoratedRose->getName();
    CHECK(finalName == "Rose, in a Clay Pot, with extra fertilizer");
    
    delete decoratedRose;
}

TEST_CASE("Decorator: Triple decorators work correctly") {
    Basil* basil = new Basil();
    basil->setHealth(1.0);
    float baseCost = basil->calculateCost("Summer");
    ConcretePot* concreteBasil = new ConcretePot(basil);
    ExtraFertilizer* fertilizedBasil = new ExtraFertilizer(concreteBasil);
    KraftWrapping* fullyDecorated = new KraftWrapping(fertilizedBasil);

    float finalCost = fullyDecorated->calculateCost("Summer");
    CHECK(finalCost == baseCost + 60.0 + 80.0 + 20.0);
    
    delete fullyDecorated;
}

TEST_CASE("Decorator: removeDecorator works correctly") {
    Basil* basil = new Basil();
    basil->setHealth(0.8);
    ClayPot* clayBasil = new ClayPot(basil);
    
    CHECK(clayBasil->calculateCost("Summer") == 100.0); 
    CHECK(clayBasil->getName() == "Basil, in a Clay Pot");
    Product* plainBasil = clayBasil->removeDecorator();
    delete clayBasil;
    CHECK(plainBasil->calculateCost("Summer") == 50.0);
    CHECK(plainBasil->getName() == "Basil");
    
    delete plainBasil;
}

TEST_CASE("Decorator: Season price effect still works") {
    Rose* rose = new Rose();
    rose->setHealth(0.8);
    ClayPot* clayRose = new ClayPot(rose);
    float summerCost = clayRose->calculateCost("Spring");
    float winterCost = clayRose->calculateCost("Winter");
    
    CHECK(summerCost == 160.0); 
    CHECK(winterCost == 150.0);
    
    delete clayRose;
}
