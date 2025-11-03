#include "doctest.h"
#include "../src/Rose.h"
#include "../src/Basil.h"
#include "../src/Tomato.h"

TEST_CASE("Plant defaults and basic getters") {
    Rose rose;
    CHECK(rose.getWaterLevel() == doctest::Approx(0.0));
    CHECK(rose.getHealth() == doctest::Approx(0.0));
    CHECK(rose.getHeight() == doctest::Approx(0.0));
    CHECK_FALSE(rose.getName().empty());
    CHECK_FALSE(rose.getStrategies().empty());
}

TEST_CASE("changeHealth increases health and height when well watered") {
    Rose rose;
    rose.setPruned(false);
    rose.setWaterLevel(1.0f);
    rose.setHealth(0.2f);

    float beforeHealth = rose.getHealth();
    float beforeHeight = rose.getHeight();
    float beforeWater = rose.getWaterLevel();

    rose.changeHealth();

    CHECK(rose.getHealth() > beforeHealth);
    CHECK(rose.getHeight() > beforeHeight);
    CHECK(rose.getWaterLevel() < beforeWater);
    CHECK(rose.getWaterLevel() >= 0.0f);
}

TEST_CASE("changeHealth decays when dry") {
    Basil basil;
    basil.setHealth(0.5f);
    basil.setWaterLevel(0.0f);
    basil.setPruned(false); 

    float before = basil.getHealth();
    basil.changeHealth();
    // when dry, health should not increase
    CHECK(basil.getHealth() <= before);
}

TEST_CASE("fertilise clamps health to 1.0") {
    Tomato tomato;
    tomato.setHealth(0.8f);
    tomato.fertilise();
    CHECK(tomato.getHealth() == doctest::Approx(1.0f));
}

TEST_CASE("pruning influences health and reduces height") {
    Rose rose;
    //pruning gives small health bump
    rose.setHealth(0.3f);
    rose.setWaterLevel(0.5f);
    rose.setPruned(true);
    float hBefore = rose.getHealth();
    rose.changeHealth();
    CHECK(rose.getHealth() > hBefore);

    //pruning reduces height slightly
    Rose rose2;
    rose2.setHeight(0.6f);
    rose2.setPruned(true);
    float htBefore = rose2.getHeight();
    rose2.changeHealth();
    CHECK(rose2.getHeight() < htBefore);
}
