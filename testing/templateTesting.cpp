#include "doctest.h"
#include "Rose.h"
#include "Basil.h"
#include "Tomato.h"
#include "Lettuce.h"
#include "Cattails.h"
#include "SnakePlant.h"
#include "Ginger.h"

TEST_CASE("Template Method Pattern: Flower base cost is 100.0") {
    Rose rose;
    CHECK(rose.baseCost() == 100.0f);
}

TEST_CASE("Template Method Pattern: Herb base cost is 50.0") {
    Basil basil;
    CHECK(basil.baseCost() == 50.0f);
}

TEST_CASE("Template Method Pattern: Fruit base cost is 200.0") {
    Tomato tomato;
    CHECK(tomato.baseCost() == 200.0f);
}

TEST_CASE("Template Method Pattern: Vegetable base cost is 80.0") {
    Lettuce lettuce;
    CHECK(lettuce.baseCost() == 80.0f);
}

TEST_CASE("Template Method Pattern: Aquatic base cost is 180.0") {
    Cattails cattails;
    CHECK(cattails.baseCost() == 180.0f);
}

TEST_CASE("Template Method Pattern: Indoor base cost is 120.0") {
    SnakePlant snakePlant;
    CHECK(snakePlant.baseCost() == 120.0f);
}

TEST_CASE("Template Method Pattern: Medicinal base cost is 60.0") {
    Ginger ginger;
    CHECK(ginger.baseCost() == 60.0f);
}


TEST_CASE("Template Method Pattern: Rose with health 0.75 in-season") {
    Rose rose;
    rose.setHealth(0.75f);
    float cost = rose.calculateCost("Summer");
    CHECK(cost == 110.0f); 
}

TEST_CASE("Template Method Pattern: Basil with health 0.8") {
    Basil basil;
    basil.setHealth(0.8f);
    float cost = basil.calculateCost("Summer");
    CHECK(cost == 50.0f); 
}

TEST_CASE("Template Method Pattern: Tomato with health 0.7 in-season") {
    Tomato tomato;
    tomato.setHealth(0.7f);
    float cost = tomato.calculateCost("Summer");
    CHECK(cost == 230.0f); 
}

TEST_CASE("Template Method Pattern: Rose with health 0.95 in-season") {
    Rose rose;
    rose.setHealth(0.95f);
    float cost = rose.calculateCost("Summer");
    CHECK(cost == 120.0f);
}

TEST_CASE("Template Method Pattern: Basil with health 1.0") {
    Basil basil;
    basil.setHealth(1.0f);
    float cost = basil.calculateCost("Summer");
    CHECK(cost == 57.5f); 
}

TEST_CASE("Template Method Pattern: Lettuce with health 0.92 in-season") {
    Lettuce lettuce;
    lettuce.setHealth(0.92f);
    float cost = lettuce.calculateCost("Summer");
    CHECK(cost == 97.6f); 
}

TEST_CASE("Template Method Pattern: Cattails with health 0.95") {
    Cattails cattails;
    cattails.setHealth(0.95f);
    float cost = cattails.calculateCost("Summer");
    CHECK(cost == 198.0f); 
}

TEST_CASE("Template Method Pattern: Rose out-of-season has no season bonus") {
    Rose rose;
    rose.setHealth(0.75f);
    float cost = rose.calculateCost("Winter");
    CHECK(cost == 100.0f); 
}