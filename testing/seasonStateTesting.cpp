#include "doctest.h"
#include "../src/SeasonState.h"
#include "../src/Spring.h"
#include "../src/Summer.h"
#include "../src/Autumn.h"
#include "../src/Winter.h"
#include "../src/Nursery.h"
#include "../src/InventoryManager.h"

TEST_CASE("Season State: Print Methods - Basic Functionality") {
    SUBCASE("Spring print method returns correct string") {
        Spring* spring = new Spring();
        CHECK(spring->print() == "Spring");
        delete spring;
    }

    SUBCASE("Summer print method returns correct string") {
        Summer* summer = new Summer();
        CHECK(summer->print() == "Summer");
        delete summer;
    }

    SUBCASE("Autumn print method returns correct string") {
        Autumn* autumn = new Autumn();
        CHECK(autumn->print() == "Autumn");
        delete autumn;
    }

    SUBCASE("Winter print method returns correct string") {
        Winter* winter = new Winter();
        CHECK(winter->print() == "Winter");
        delete winter;
    }
}

TEST_CASE("Season State: Print Methods - Multiple Instances") {
    SUBCASE("Multiple Spring instances have consistent output") {
        Spring* spring1 = new Spring();
        Spring* spring2 = new Spring();
        Spring* spring3 = new Spring();
        
        CHECK(spring1->print() == "Spring");
        CHECK(spring2->print() == "Spring");
        CHECK(spring3->print() == "Spring");
        CHECK(spring1->print() == spring2->print());
        
        delete spring1;
        delete spring2;
        delete spring3;
    }
}

TEST_CASE("Season State: Individual Season Transitions") {
    SUBCASE("Spring to Summer transition") {
        InventoryManager* manager = new InventoryManager();
        Nursery* nursery = Nursery::getInstance(manager);
        
        nursery->setSeason(new Spring());
        CHECK(nursery->getSeason() == "Spring");
        
        nursery->changeSeason();
        CHECK(nursery->getSeason() == "Summer");
        
        delete manager;
    }

    SUBCASE("Summer to Autumn transition") {
        InventoryManager* manager = new InventoryManager();
        Nursery* nursery = Nursery::getInstance(manager);
        
        nursery->setSeason(new Summer());
        CHECK(nursery->getSeason() == "Summer");
        
        nursery->changeSeason();
        CHECK(nursery->getSeason() == "Autumn");
        
        delete manager;
    }

    SUBCASE("Autumn to Winter transition") {
        InventoryManager* manager = new InventoryManager();
        Nursery* nursery = Nursery::getInstance(manager);
        
        nursery->setSeason(new Autumn());
        CHECK(nursery->getSeason() == "Autumn");
        
        nursery->changeSeason();
        CHECK(nursery->getSeason() == "Winter");
        
        delete manager;
    }

    SUBCASE("Winter to Spring transition (full cycle completion)") {
        InventoryManager* manager = new InventoryManager();
        Nursery* nursery = Nursery::getInstance(manager);
        
        nursery->setSeason(new Winter());
        CHECK(nursery->getSeason() == "Winter");
        
        nursery->changeSeason();
        CHECK(nursery->getSeason() == "Spring");
        
        delete manager;
    }
}

TEST_CASE("Season State: Complete Seasonal Cycles") {
    SUBCASE("Single complete seasonal cycle") {
        InventoryManager* manager = new InventoryManager();
        Nursery* nursery = Nursery::getInstance(manager);
        
        nursery->setSeason(new Spring());
        CHECK(nursery->getSeason() == "Spring");
        
        nursery->changeSeason();
        CHECK(nursery->getSeason() == "Summer");
        
        nursery->changeSeason();
        CHECK(nursery->getSeason() == "Autumn");
        
        nursery->changeSeason();
        CHECK(nursery->getSeason() == "Winter");
        
        nursery->changeSeason();
        CHECK(nursery->getSeason() == "Spring");
        
        delete manager;
    }

    SUBCASE("Two complete cycles") {
        InventoryManager* manager = new InventoryManager();
        Nursery* nursery = Nursery::getInstance(manager);
        
        nursery->setSeason(new Spring());
        
        for (int cycle = 0; cycle < 2; cycle++) {
            CHECK(nursery->getSeason() == "Spring");
            nursery->changeSeason();
            
            CHECK(nursery->getSeason() == "Summer");
            nursery->changeSeason();
            
            CHECK(nursery->getSeason() == "Autumn");
            nursery->changeSeason();
            
            CHECK(nursery->getSeason() == "Winter");
            nursery->changeSeason();
        }
        
        CHECK(nursery->getSeason() == "Spring");
        
        delete manager;
    }
}

TEST_CASE("Season State: Partial Cycle Transitions") {
    SUBCASE("Start from Spring, stop at Summer") {
        InventoryManager* manager = new InventoryManager();
        Nursery* nursery = Nursery::getInstance(manager);
        
        nursery->setSeason(new Spring());
        nursery->changeSeason();
        
        CHECK(nursery->getSeason() == "Summer");
        
        delete manager;
    }
    
    SUBCASE("Start from Spring, stop at Autumn") {
        InventoryManager* manager = new InventoryManager();
        Nursery* nursery = Nursery::getInstance(manager);
        
        nursery->setSeason(new Spring());
        nursery->changeSeason();
        nursery->changeSeason();
        
        CHECK(nursery->getSeason() == "Autumn");
        
        delete manager;
    }
    
    SUBCASE("Start from Spring, stop at Winter") {
        InventoryManager* manager = new InventoryManager();
        Nursery* nursery = Nursery::getInstance(manager);
        
        nursery->setSeason(new Spring());
        nursery->changeSeason();
        nursery->changeSeason();
        nursery->changeSeason();
        
        CHECK(nursery->getSeason() == "Winter");
        
        delete manager;
    }
}

TEST_CASE("Season State: Rapid Season Changes") {
    SUBCASE("10 rapid consecutive changes") {
        InventoryManager* manager = new InventoryManager();
        Nursery* nursery = Nursery::getInstance(manager);
        
        nursery->setSeason(new Spring());
        
        for (int i = 0; i < 10; i++) 
            nursery->changeSeason();
        
        CHECK(nursery->getSeason() == "Autumn");
        
        delete manager;
    }
}

TEST_CASE("Season State: Direct Season Setting") {
    SUBCASE("Set to each season directly") {
        InventoryManager* manager = new InventoryManager();
        Nursery* nursery = Nursery::getInstance(manager);
        
        nursery->setSeason(new Spring());
        CHECK(nursery->getSeason() == "Spring");
        
        nursery->setSeason(new Summer());
        CHECK(nursery->getSeason() == "Summer");
        
        nursery->setSeason(new Autumn());
        CHECK(nursery->getSeason() == "Autumn");
        
        nursery->setSeason(new Winter());
        CHECK(nursery->getSeason() == "Winter");
        
        delete manager;
    }
}

TEST_CASE("Season State: Mixed Setting and Changing Operations") { 
    SUBCASE("Multiple changes after each set") {
        InventoryManager* manager = new InventoryManager();
        Nursery* nursery = Nursery::getInstance(manager);
        
        nursery->setSeason(new Spring());
        nursery->changeSeason();
        nursery->changeSeason();
        CHECK(nursery->getSeason() == "Autumn");
        
        nursery->setSeason(new Summer());
        nursery->changeSeason();
        nursery->changeSeason();
        nursery->changeSeason();
        CHECK(nursery->getSeason() == "Spring");
        
        nursery->setSeason(new Winter());
        nursery->changeSeason();
        CHECK(nursery->getSeason() == "Spring");
        
        delete manager;
    }
}

TEST_CASE("Season State: Consistency and Invariant Tests") {
    SUBCASE("getSeason always returns valid season") {
        InventoryManager* manager = new InventoryManager();
        Nursery* nursery = Nursery::getInstance(manager);
        
        vector<string> validSeasons = {"Spring", "Summer", "Autumn", "Winter"};
        
        nursery->setSeason(new Spring());
        
        for (int i = 0; i < 20; i++) {
            string currentSeason = nursery->getSeason();
            bool isValid = false;
            for (const auto& season : validSeasons) 
                if (currentSeason == season) {
                    isValid = true;
                    break;
                }
            CHECK(isValid);
            nursery->changeSeason();
        }
        
        delete manager;
    }
}

TEST_CASE("Season State: Edge Cases and Boundary Conditions") {
    SUBCASE("Zero season changes") {
        InventoryManager* manager = new InventoryManager();
        Nursery* nursery = Nursery::getInstance(manager);
        
        nursery->setSeason(new Spring());
        CHECK(nursery->getSeason() == "Spring");
        
        CHECK(nursery->getSeason() == "Spring");
        
        delete manager;
    }
    
    SUBCASE("Verify exactly 4 seasons in complete cycle") {
        InventoryManager* manager = new InventoryManager();
        Nursery* nursery = Nursery::getInstance(manager);
        
        nursery->setSeason(new Spring());
        string start = nursery->getSeason();
        
        nursery->changeSeason();
        CHECK(nursery->getSeason() != start);
        
        nursery->changeSeason();
        CHECK(nursery->getSeason() != start);
        
        nursery->changeSeason();
        CHECK(nursery->getSeason() != start);
        
        nursery->changeSeason(); 
        CHECK(nursery->getSeason() == start);
        
        delete manager;
    }
}

TEST_CASE("Season State: Null Pointer Edge Cases") {
    SUBCASE("Set season to nullptr") {
        InventoryManager* manager = new InventoryManager();
        Nursery* nursery = Nursery::getInstance(manager);
        
        nursery->setSeason(new Spring());
        CHECK(nursery->getSeason() == "Spring");
        
        CHECK_NOTHROW(nursery->setSeason(nullptr));
        
        delete manager;
    }
    
    SUBCASE("Initialize Nursery with nullptr manager") {
        CHECK_NOTHROW(Nursery::getInstance(nullptr));
    }
    
    SUBCASE("Change season without setting initial season") {
        InventoryManager* manager = new InventoryManager();
        Nursery* nursery = Nursery::getInstance(manager);
        
        CHECK_NOTHROW(nursery->changeSeason());
        
        delete manager;
    }
    
    SUBCASE("Get season without setting initial season") {
        InventoryManager* manager = new InventoryManager();
        Nursery* nursery = Nursery::getInstance(manager);
        
        CHECK_NOTHROW(nursery->getSeason());
        
        delete manager;
    }
    
    SUBCASE("Multiple nullptr setSeason calls") {
        InventoryManager* manager = new InventoryManager();
        Nursery* nursery = Nursery::getInstance(manager);
        
        nursery->setSeason(new Spring());
        
        for (int i = 0; i < 5; i++) 
            CHECK_NOTHROW(nursery->setSeason(nullptr));
        
        delete manager;
    }
    
    SUBCASE("Alternate between valid season and nullptr") {
        InventoryManager* manager = new InventoryManager();
        Nursery* nursery = Nursery::getInstance(manager);
        
        nursery->setSeason(new Spring());
        CHECK(nursery->getSeason() == "Spring");
        
        nursery->setSeason(nullptr);
        
        nursery->setSeason(new Summer());
        CHECK_NOTHROW(nursery->getSeason());
        
        delete manager;
    }
}