#include "doctest.h"
#include "Rose.h"
#include "Basil.h"
#include "Tomato.h"
#include "JadePlant.h"
#include "Lettuce.h"
#include "Plant.h"

TEST_CASE("Plant State: Initialization - All plants start in Seed State") {
    SUBCASE("Rose plant initialization") {
        Rose plant;
        CHECK(plant.getState() == "Seed State");
        CHECK(plant.getHealth() == 0.0);
        CHECK(plant.getHeight() == 0.0);
    }
    
    SUBCASE("Basil plant initialization") {
        Basil plant;
        CHECK(plant.getState() == "Seed State");
        CHECK(plant.getHealth() == 0.0);
        CHECK(plant.getHeight() == 0.0);
    }
    
    SUBCASE("Tomato plant initialization") {
        Tomato plant;
        CHECK(plant.getState() == "Seed State");
        CHECK(plant.getHealth() == 0.0);
        CHECK(plant.getHeight() == 0.0);
    }
    
    SUBCASE("JadePlant initialization") {
        JadePlant plant;
        CHECK(plant.getState() == "Seed State");
        CHECK(plant.getHealth() == 0.0);
        CHECK(plant.getHeight() == 0.0);
    }
    
    SUBCASE("Lettuce plant initialization") {
        Lettuce plant;
        CHECK(plant.getState() == "Seed State");
        CHECK(plant.getHealth() == 0.0);
        CHECK(plant.getHeight() == 0.0);
    }
}

TEST_CASE("Plant State: Seed to Seedling Transitions") {
    SUBCASE("Normal transition at threshold") {
        Basil plant;
        plant.setHeight(0.15);
        plant.setHealth(0.15);
        plant.changePlantState();
        CHECK(plant.getState() == "Seedling State");
    }
    
    SUBCASE("Transition at exact minimum threshold (0.1)") {
        Rose plant;
        plant.setHeight(0.1);
        plant.setHealth(0.1);
        plant.changePlantState();
        CHECK(plant.getState() == "Seedling State");
    }
    
    SUBCASE("No transition just below threshold") {
        Tomato plant;
        plant.setHeight(0.09);
        plant.setHealth(0.09);
        plant.changePlantState();
        CHECK(plant.getState() == "Seed State");
    }
    
    SUBCASE("Transition with height at threshold but health higher") {
        Rose plant;
        plant.setHeight(0.1);
        plant.setHealth(0.5);
        plant.changePlantState();
        CHECK(plant.getState() == "Seedling State");
    }
    
    SUBCASE("Transition with health at threshold but height higher") {
        Basil plant;
        plant.setHeight(0.5);
        plant.setHealth(0.1);
        plant.changePlantState();
        CHECK(plant.getState() == "Seedling State");
    }
    
    SUBCASE("No transition when only height meets threshold") {
        Lettuce plant;
        plant.setHeight(0.15);
        plant.setHealth(0.05);
        plant.changePlantState();
        CHECK(plant.getState() == "Seed State");
    }
    
    SUBCASE("No transition when only health meets threshold") {
        JadePlant plant;
        plant.setHeight(0.05);
        plant.setHealth(0.15);
        plant.changePlantState();
        CHECK(plant.getState() == "Seed State");
    }
    
    SUBCASE("Transition with very high values") {
        Tomato plant;
        plant.setHeight(0.8);
        plant.setHealth(0.8);
        plant.changePlantState();
        CHECK(plant.getState() == "Seedling State");
    }
}

TEST_CASE("Plant State: Seedling to Growing Transitions") {
    SUBCASE("Normal progression to Growing") {
        Tomato plant;
        plant.setHeight(0.25);
        plant.setHealth(0.25);
        plant.changePlantState();
        plant.changePlantState();
        CHECK(plant.getState() == "Growing");
    }
    
    SUBCASE("Transition at exact threshold (0.2)") {
        Rose plant;
        plant.setHeight(0.2);
        plant.setHealth(0.2);
        plant.changePlantState();
        plant.changePlantState();
        CHECK(plant.getState() == "Growing");
    }
    
    SUBCASE("No transition just below threshold") {
        Basil plant;
        plant.setHeight(0.19);
        plant.setHealth(0.19);
        plant.changePlantState();
        plant.changePlantState();
        CHECK(plant.getState() == "Seedling State");
    }
    
    SUBCASE("Multiple state changes with incremental growth") {
        Lettuce plant;
        plant.setHeight(0.15);
        plant.setHealth(0.15);
        plant.changePlantState();
        CHECK(plant.getState() == "Seedling State");
        
        plant.setHeight(0.25);
        plant.setHealth(0.25);
        plant.changePlantState();
        CHECK(plant.getState() == "Growing");
    }
}

TEST_CASE("Plant State: Growing to Mature Transitions") {
    SUBCASE("Normal progression to Mature") {
        Rose plant;
        plant.setHeight(0.6);
        plant.setHealth(0.6);
        plant.changePlantState();
        plant.changePlantState();
        plant.changePlantState();
        CHECK(plant.getState() == "Mature");
    }
    
    SUBCASE("Transition at exact threshold (0.5)") {
        Basil plant;
        plant.setHeight(0.5);
        plant.setHealth(0.5);
        plant.changePlantState();
        plant.changePlantState();
        plant.changePlantState();
        CHECK(plant.getState() == "Mature");
    }
    
    SUBCASE("No transition just below threshold") {
        Tomato plant;
        plant.setHeight(0.49);
        plant.setHealth(0.49);
        plant.changePlantState();
        plant.changePlantState();
        plant.changePlantState();
        CHECK(plant.getState() == "Growing");
    }
    
    SUBCASE("Rapid growth to Mature") {
        JadePlant plant;
        plant.setHeight(0.7);
        plant.setHealth(0.7);
        plant.changePlantState();
        plant.changePlantState();
        plant.changePlantState();
        CHECK(plant.getState() == "Mature");
    }
}

TEST_CASE("Plant State: Mature to Ready for Sale Transitions") {
    SUBCASE("Normal progression to Ready for Sale") {
        Basil plant;
        plant.setHeight(0.95);
        plant.setHealth(0.95);
        plant.changePlantState();
        plant.changePlantState();
        plant.changePlantState();
        plant.changePlantState();
        CHECK(plant.getState() == "Ready for Sale");
    }
    
    SUBCASE("Transition at exact threshold (0.9)") {
        Rose plant;
        plant.setHeight(0.91);
        plant.setHealth(0.91);
        plant.changePlantState();
        plant.changePlantState();
        plant.changePlantState();
        plant.changePlantState();
        CHECK(plant.getState() == "Ready for Sale");
    }
    
    SUBCASE("No transition just below threshold") {
        Tomato plant;
        plant.setHeight(0.89);
        plant.setHealth(0.89);
        plant.changePlantState();
        plant.changePlantState();
        plant.changePlantState();
        plant.changePlantState();
        CHECK(plant.getState() == "Mature");
    }
    
    SUBCASE("Maximum values progression") {
        Lettuce plant;
        plant.setHeight(1.0);
        plant.setHealth(1.0);
        plant.changePlantState();
        plant.changePlantState();
        plant.changePlantState();
        plant.changePlantState();
        CHECK(plant.getState() == "Ready for Sale");
    }
}

TEST_CASE("Plant State: Transitions to and from Dying State") {
    SUBCASE("Growing to Dying when health drops") {
        Tomato plant;
        plant.setHeight(0.3);
        plant.setHealth(0.3);
        plant.changePlantState();
        plant.changePlantState();
        plant.changePlantState();
        CHECK(plant.getState() == "Growing");
        
        plant.setHealth(0.15);
        plant.changePlantState();
        CHECK(plant.getState() == "Dying");
    }
    
    SUBCASE("Mature to Dying when health drops") {
        Rose plant;
        plant.setHeight(0.6);
        plant.setHealth(0.6);
        plant.changePlantState();
        plant.changePlantState();
        plant.changePlantState();
        CHECK(plant.getState() == "Mature");
        
        plant.setHealth(0.15);
        plant.changePlantState();
        CHECK(plant.getState() == "Dying");
    }
    
    SUBCASE("Dying at exact threshold (0.2)") {
        Basil plant;
        plant.setHeight(0.5);
        plant.setHealth(0.5);
        plant.changePlantState();
        plant.changePlantState();
        plant.changePlantState();
        
        plant.setHealth(0.2);
        plant.changePlantState();
        CHECK(plant.getState() == "Dying");
    }
    
    SUBCASE("Plant recovers from Dying to Growing") {
        Lettuce plant;
        plant.setHeight(0.3);
        plant.setHealth(0.3);
        plant.changePlantState();
        plant.changePlantState();
        plant.changePlantState();
        
        plant.setHealth(0.15);
        plant.changePlantState();
        CHECK(plant.getState() == "Dying");
        
        plant.setHealth(0.35);
        plant.changePlantState();
        CHECK(plant.getState() == "Growing");
    }
    
    SUBCASE("Plant recovers from Dying to Mature") {
        JadePlant plant;
        plant.setHeight(0.7);
        plant.setHealth(0.7);
        plant.changePlantState();
        plant.changePlantState();
        plant.changePlantState();
        CHECK(plant.getState() == "Mature");
        
        plant.setHealth(0.15);
        plant.changePlantState();
        CHECK(plant.getState() == "Dying");
        
        plant.setHealth(0.65);
        plant.changePlantState();
        CHECK(plant.getState() == "Mature");
    }
    
    SUBCASE("Dying with zero health") {
        Tomato plant;
        plant.setHeight(0.4);
        plant.setHealth(0.4);
        plant.changePlantState();
        plant.changePlantState();
        plant.changePlantState();
        
        plant.setHealth(0.0);
        plant.changePlantState();
        CHECK(plant.getState() == "Dying");
    }
}

TEST_CASE("Plant State: Dead State - Terminal State Tests") {
    SUBCASE("Dying to Dead when health is zero") {
        Rose plant;
        plant.setHeight(0.4);
        plant.setHealth(0.4);
        plant.changePlantState();
        plant.changePlantState();
        plant.changePlantState();
        
        plant.setHealth(0.15);
        plant.changePlantState();
        CHECK(plant.getState() == "Dying");
        
        plant.setHealth(0.0);
        plant.changePlantState();
        CHECK(plant.getState() == "Dead");
    }
    
    SUBCASE("Dead state is permanent - high health doesn't revive") {
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
        CHECK(plant.getState() == "Dead");
        
        plant.setHealth(1.0);
        plant.changePlantState();
        CHECK(plant.getState() == "Dead");
    }
    
    SUBCASE("Dead state is permanent - multiple state changes") {
        Tomato plant;
        plant.setHeight(0.5);
        plant.setHealth(0.5);
        plant.changePlantState();
        plant.changePlantState();
        plant.changePlantState();
        
        plant.setHealth(0.0);
        plant.changePlantState();
        plant.changePlantState();
        CHECK(plant.getState() == "Dead");
        
        for (int i = 0; i < 10; i++) {
            plant.changePlantState();
        }
        CHECK(plant.getState() == "Dead");
    }
    
    SUBCASE("Dead state with maximum health and height") {
        Lettuce plant;
        plant.setHeight(0.3);
        plant.setHealth(0.3);
        plant.changePlantState();
        plant.changePlantState();
        plant.changePlantState();
        
        plant.setHealth(0.0);
        plant.changePlantState();
        plant.changePlantState();
        
        plant.setHeight(1.0);
        plant.setHealth(1.0);
        plant.changePlantState();
        CHECK(plant.getState() == "Dead");
    }
}

TEST_CASE("Plant State: State Degradation Tests") {
    SUBCASE("Ready for Sale degrades to Mature") {
        JadePlant plant;
        plant.setHeight(0.95);
        plant.setHealth(0.95);
        plant.changePlantState();
        plant.changePlantState();
        plant.changePlantState();
        plant.changePlantState();
        CHECK(plant.getState() == "Ready for Sale");
        
        plant.setHealth(0.65);
        plant.changePlantState();
        CHECK(plant.getState() == "Mature");
    }
    
    SUBCASE("Ready for Sale degrades at exact threshold") {
        Rose plant;
        plant.setHeight(0.95);
        plant.setHealth(0.95);
        plant.changePlantState();
        plant.changePlantState();
        plant.changePlantState();
        plant.changePlantState();
        CHECK(plant.getState() == "Ready for Sale");
        
        plant.setHealth(0.69);
        plant.changePlantState();
        CHECK(plant.getState() == "Mature");
    }
    
    SUBCASE("Mature degrades to Dying when health drops below 0.5") {
        Basil plant;
        plant.setHeight(0.7);
        plant.setHealth(0.7);
        plant.changePlantState();
        plant.changePlantState();
        plant.changePlantState();
        CHECK(plant.getState() == "Mature");
        
        plant.setHealth(0.35);
        plant.changePlantState();
        CHECK(plant.getState() == "Dying");
    }
    
    SUBCASE("Growing degrades to Dying when health drops below 0.2") {
        Tomato plant;
        plant.setHeight(0.3);
        plant.setHealth(0.3);
        plant.changePlantState();
        plant.changePlantState();
        plant.changePlantState();
        CHECK(plant.getState() == "Growing");
        
        plant.setHealth(0.15);
        plant.changePlantState();
        CHECK(plant.getState() == "Dying");
    }
}

TEST_CASE("Plant State: Boundary Value Analysis") {
    SUBCASE("Health at 0.0") {
        Rose plant;
        plant.setHeight(0.5);
        plant.setHealth(0.0);
        plant.changePlantState();
        plant.changePlantState();
        plant.changePlantState();
        // Should handle gracefully
        CHECK(plant.getState() != "");
    }
    
    SUBCASE("Health at 1.0 (maximum)") {
        Basil plant;
        plant.setHeight(1.0);
        plant.setHealth(1.0);
        plant.changePlantState();
        plant.changePlantState();
        plant.changePlantState();
        plant.changePlantState();
        CHECK(plant.getState() == "Ready for Sale");
    }
    
    SUBCASE("Height and health at 0.09 (just below first threshold)") {
        Tomato plant;
        plant.setHeight(0.09);
        plant.setHealth(0.09);
        plant.changePlantState();
        CHECK(plant.getState() == "Seed State");
    }
    
    SUBCASE("Height and health at 0.1 (at first threshold)") {
        Lettuce plant;
        plant.setHeight(0.1);
        plant.setHealth(0.1);
        plant.changePlantState();
        CHECK(plant.getState() == "Seedling State");
    }
    
    SUBCASE("Height and health at 0.19 (just below second threshold)") {
        JadePlant plant;
        plant.setHeight(0.19);
        plant.setHealth(0.19);
        plant.changePlantState();
        plant.changePlantState();
        CHECK(plant.getState() == "Seedling State");
    }
    
    SUBCASE("Height and health at 0.2 (at second threshold)") {
        Rose plant;
        plant.setHeight(0.2);
        plant.setHealth(0.2);
        plant.changePlantState();
        plant.changePlantState();
        CHECK(plant.getState() == "Growing");
    }
}

TEST_CASE("Plant State: Edge Cases and Unusual Scenarios") {
    SUBCASE("Multiple state changes without property updates") {
        Basil plant;
        plant.setHeight(0.5);
        plant.setHealth(0.5);
        
        plant.changePlantState();
        string firstState = plant.getState();
        plant.changePlantState();
        string secondState = plant.getState();
        plant.changePlantState();
        string thirdState = plant.getState();
        
        // Should progress through states
        CHECK(firstState == "Seedling State");
        CHECK(secondState == "Growing");
        CHECK(thirdState == "Mature");
    }
    
    SUBCASE("Alternating health values") {
        Tomato plant;
        plant.setHeight(0.5);
        plant.setHealth(0.5);
        plant.changePlantState();
        plant.changePlantState();
        plant.changePlantState();
        CHECK(plant.getState() == "Mature");
        
        plant.setHealth(0.15);
        plant.changePlantState();
        CHECK(plant.getState() == "Dying");
        
        plant.setHealth(0.6);
        plant.changePlantState();
        CHECK(plant.getState() == "Mature");
        
        plant.setHealth(0.15);
        plant.changePlantState();
        CHECK(plant.getState() == "Dying");
    }
    
    SUBCASE("Very small incremental changes") {
        Rose plant;
        plant.setHeight(0.09);
        plant.setHealth(0.09);
        plant.changePlantState();
        CHECK(plant.getState() == "Seed State");
        
        plant.setHeight(0.095);
        plant.setHealth(0.095);
        plant.changePlantState();
        CHECK(plant.getState() == "Seed State");
        
        plant.setHeight(0.1);
        plant.setHealth(0.1);
        plant.changePlantState();
        CHECK(plant.getState() == "Seedling State");
    }
    
    SUBCASE("Height much higher than health") {
        Lettuce plant;
        plant.setHeight(0.9);
        plant.setHealth(0.1);
        plant.changePlantState();
        CHECK(plant.getState() == "Seedling State");
    }
    
    SUBCASE("Health much higher than height") {
        JadePlant plant;
        plant.setHeight(0.1);
        plant.setHealth(0.9);
        plant.changePlantState();
        CHECK(plant.getState() == "Seedling State");
    }
}

TEST_CASE("Plant State: Complete Lifecycle Scenarios") {
    SUBCASE("Full healthy lifecycle") {
        Rose plant;
        CHECK(plant.getState() == "Seed State");
        
        plant.setHeight(0.15);
        plant.setHealth(0.15);
        plant.changePlantState();
        CHECK(plant.getState() == "Seedling State");
        
        plant.setHeight(0.3);
        plant.setHealth(0.3);
        plant.changePlantState();
        CHECK(plant.getState() == "Growing");
        
        plant.setHeight(0.6);
        plant.setHealth(0.6);
        plant.changePlantState();
        CHECK(plant.getState() == "Mature");
        
        plant.setHeight(0.95);
        plant.setHealth(0.95);
        plant.changePlantState();
        CHECK(plant.getState() == "Ready for Sale");
    }
    
    SUBCASE("Lifecycle with near-death and recovery") {
        Basil plant;
        plant.setHeight(0.3);
        plant.setHealth(0.3);
        plant.changePlantState();
        plant.changePlantState();
        plant.changePlantState();
        CHECK(plant.getState() == "Growing");
        
        plant.setHealth(0.15);
        plant.changePlantState();
        CHECK(plant.getState() == "Dying");
        
        plant.setHeight(0.4);
        plant.setHealth(0.4);
        plant.changePlantState();
        CHECK(plant.getState() == "Growing");
        
        plant.setHeight(0.7);
        plant.setHealth(0.7);
        plant.changePlantState();
        CHECK(plant.getState() == "Mature");
        
        plant.setHeight(0.95);
        plant.setHealth(0.95);
        plant.changePlantState();
        CHECK(plant.getState() == "Ready for Sale");
    }
    
    SUBCASE("Lifecycle ending in death") {
        Tomato plant;
        plant.setHeight(0.3);
        plant.setHealth(0.3);
        plant.changePlantState();
        plant.changePlantState();
        plant.changePlantState();
        CHECK(plant.getState() == "Growing");
        
        plant.setHealth(0.15);
        plant.changePlantState();
        CHECK(plant.getState() == "Dying");
        
        plant.setHealth(0.0);
        plant.changePlantState();
        plant.changePlantState();
        CHECK(plant.getState() == "Dead");
        
        plant.setHealth(1.0);
        plant.setHeight(1.0);
        plant.changePlantState();
        CHECK(plant.getState() == "Dead");
    }
}

TEST_CASE("Plant State: Negative Value Edge Cases") {
    SUBCASE("Negative health value") {
        Rose plant;
        plant.setHeight(0.5);
        plant.setHealth(-0.1);
        plant.changePlantState();
        CHECK(plant.getState() != "");
    }
    
    SUBCASE("Negative height value") {
        Basil plant;
        plant.setHeight(-0.5);
        plant.setHealth(0.5);
        plant.changePlantState();
        CHECK(plant.getState() != "");
    }
    
    SUBCASE("Both negative values") {
        Tomato plant;
        plant.setHeight(-0.3);
        plant.setHealth(-0.3);
        plant.changePlantState();
        CHECK(plant.getState() != "");
    }
    
    SUBCASE("Very large negative values") {
        Lettuce plant;
        plant.setHeight(-100.0);
        plant.setHealth(-100.0);
        plant.changePlantState();
        CHECK(plant.getState() != "");
    }
}

TEST_CASE("Plant State: Values Beyond Maximum Edge Cases") {
    SUBCASE("Health greater than 1.0") {
        Rose plant;
        plant.setHeight(0.5);
        plant.setHealth(1.5);
        plant.changePlantState();
        plant.changePlantState();
        CHECK(plant.getState() != "");
    }
    
    SUBCASE("Height greater than 1.0") {
        Basil plant;
        plant.setHeight(2.0);
        plant.setHealth(0.5);
        plant.changePlantState();
        plant.changePlantState();
        CHECK(plant.getState() != "");
    }
    
    SUBCASE("Both values greater than 1.0") {
        Tomato plant;
        plant.setHeight(1.8);
        plant.setHealth(1.8);
        plant.changePlantState();
        plant.changePlantState();
        plant.changePlantState();
        plant.changePlantState();
        CHECK(plant.getState() != "");
    }
    
    SUBCASE("Extremely large values") {
        JadePlant plant;
        plant.setHeight(1000.0);
        plant.setHealth(1000.0);
        plant.changePlantState();
        plant.changePlantState();
        plant.changePlantState();
        plant.changePlantState();
        CHECK(plant.getState() != "");
    }
    
    SUBCASE("Values slightly above 1.0") {
        Lettuce plant;
        plant.setHeight(1.01);
        plant.setHealth(1.01);
        plant.changePlantState();
        plant.changePlantState();
        plant.changePlantState();
        plant.changePlantState();
        CHECK(plant.getState() != "");
    }
}

TEST_CASE("Plant State: Mixed Extreme Values") {
    SUBCASE("Negative health with positive height") {
        Rose plant;
        plant.setHeight(0.5);
        plant.setHealth(-0.2);
        plant.changePlantState();
        plant.changePlantState();
        CHECK(plant.getState() != "");
    }
    
    SUBCASE("Positive health with negative height") {
        Basil plant;
        plant.setHeight(-0.3);
        plant.setHealth(0.7);
        plant.changePlantState();
        CHECK(plant.getState() != "");
    }
    
    SUBCASE("Health above 1.0 with negative height") {
        Tomato plant;
        plant.setHeight(-0.5);
        plant.setHealth(1.5);
        plant.changePlantState();
        CHECK(plant.getState() != "");
    }
    
    SUBCASE("Height above 1.0 with zero health") {
        Lettuce plant;
        plant.setHeight(2.0);
        plant.setHealth(0.0);
        plant.changePlantState();
        plant.changePlantState();
        CHECK(plant.getState() != "");
    }
}