#include "doctest.h"
#include "Rose.h"
#include "Basil.h"
#include "Tomato.h"
#include "JadePlant.h"
#include "Lettuce.h"
#include "Plant.h"

TEST_CASE("State Pattern: Plant initializes in Seed State") {
    Rose plant;
    CHECK(plant.getState() == "Seed State");
}

TEST_CASE("State Pattern: Seed transitions to Seedling State") {
    Basil plant;
    plant.setHeight(0.15);
    plant.setHealth(0.15);
    plant.changePlantState();
    CHECK(plant.getState() == "Seedling State");
}

TEST_CASE("State Pattern: Seedling transitions to Growing State") {
    Tomato plant;
    plant.setHeight(0.25);
    plant.setHealth(0.25);
    plant.changePlantState();
    plant.changePlantState();
    CHECK(plant.getState() == "Growing");
}

TEST_CASE("State Pattern: Growing transitions to Mature State") {
    Rose plant;
    plant.setHeight(0.6);
    plant.setHealth(0.6);
    plant.changePlantState();
    plant.changePlantState();
    plant.changePlantState();
    CHECK(plant.getState() == "Mature");
}

TEST_CASE("State Pattern: Mature transitions to Ready for Sale State") {
    Basil plant;
    plant.setHeight(0.95);
    plant.setHealth(0.95);
    plant.changePlantState();
    plant.changePlantState();
    plant.changePlantState();
    plant.changePlantState();
    CHECK(plant.getState() == "Ready for Sale");
}

TEST_CASE("State Pattern: Growing transitions to Dying State when health drops") {
    Tomato plant;
    plant.setHeight(0.3);
    plant.setHealth(0.3);
    plant.changePlantState();
    plant.changePlantState();
    plant.changePlantState();
    plant.setHealth(0.15);
    plant.changePlantState();
    CHECK(plant.getState() == "Dying");
}

TEST_CASE("State Pattern: Dying transitions to Dead State when health is zero") {
    Rose plant;
    plant.setHeight(0.4);
    plant.setHealth(0.4);
    plant.changePlantState();
    plant.changePlantState();
    plant.changePlantState();
    plant.setHealth(0.15);
    plant.changePlantState();
    plant.setHealth(0.0);
    plant.changePlantState();
    CHECK(plant.getState() == "Dead");
}

TEST_CASE("State Pattern: Dead State does not change") {
    Basil plant;
    plant.setHeight(0.4);
    plant.setHealth(0.4);
    plant.changePlantState();
    plant.changePlantState();
    plant.changePlantState();
    plant.setHealth(0.15);
    plant.changePlantState();
    plant.setHealth(0.0);
    plant.changePlantState();
    plant.setHealth(1.0);
    plant.changePlantState();
    plant.changePlantState();
    CHECK(plant.getState() == "Dead");
}

TEST_CASE("State Pattern: Plant recovers from Dying to Growing State") {
    Lettuce plant;
    plant.setHeight(0.3);
    plant.setHealth(0.15);
    plant.changePlantState();
    plant.changePlantState();
    plant.changePlantState();
    plant.setHealth(0.3);
    plant.changePlantState();
    CHECK(plant.getState() == "Growing");
}

TEST_CASE("State Pattern: Ready for Sale degrades to Mature State") {
    JadePlant plant;
    plant.setHeight(0.95);
    plant.setHealth(0.95);
    plant.changePlantState();
    plant.changePlantState();
    plant.changePlantState();
    plant.changePlantState();
    plant.setHealth(0.65);
    plant.changePlantState();
    CHECK(plant.getState() == "Mature");
}

TEST_CASE("State Pattern: Seed transitions at exact minimum threshold") {
    Rose plant;
    plant.setHeight(0.1);
    plant.setHealth(0.11);
    plant.changePlantState();
    CHECK(plant.getState() == "Seedling State");
}

TEST_CASE("State Pattern: Seed remains when below threshold") {
    Tomato plant;
    plant.setHeight(0.09);
    plant.setHealth(0.15);
    plant.changePlantState();
    CHECK(plant.getState() == "Seed State");
}