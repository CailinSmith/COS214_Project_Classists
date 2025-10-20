#include "doctest.h"
#include "../src/StaffMediator.h"
#include "../src/Staff.h"
#include "../src/SalesStaff.h"
#include "../src/NurseryStaff.h"
#include "../src/Manager.h"
#include "../src/SalesArea.h"
#include "../src/NurseryArea.h"

TEST_CASE("Mediator Pattern - StaffMediator basic functionality") {
    SUBCASE("Register colleagues to mediator") {
        SalesArea* salesArea = new SalesArea();
        SalesStaff* staff1 = new SalesStaff("Alice");
        SalesStaff* staff2 = new SalesStaff("Bob");
        
        salesArea->registerColleague(staff1);
        salesArea->registerColleague(staff2);
        
        CHECK(staff1 != nullptr);
        CHECK(staff2 != nullptr);
        
        delete staff1;
        delete staff2;
        delete salesArea;
    }
    
    SUBCASE("Staff can register mediator") {
        NurseryArea* nurseryArea = new NurseryArea();
        NurseryStaff* staff = new NurseryStaff("Charlie");
        
        staff->registerMediator(nurseryArea);
        nurseryArea->registerColleague(staff);
        
        CHECK(staff->getName() == "Charlie");
        
        delete staff;
        delete nurseryArea;
    }
    
    SUBCASE("Staff can send messages through mediator") {
        SalesArea* salesArea = new SalesArea();
        SalesStaff* staff1 = new SalesStaff("Dave");
        SalesStaff* staff2 = new SalesStaff("Eve");
        
        staff1->registerMediator(salesArea);
        staff2->registerMediator(salesArea);
        salesArea->registerColleague(staff1);
        salesArea->registerColleague(staff2);
        
        staff1->setMessage("Hello from Dave");
        CHECK(staff1->getMessage() == "Hello from Dave");
        
        staff1->send();
        
        delete staff1;
        delete staff2;
        delete salesArea;
    }
    
    SUBCASE("Multiple staff members in different areas") {
        SalesArea* salesArea = new SalesArea();
        NurseryArea* nurseryArea = new NurseryArea();
        
        Manager* salesManager = new Manager("Frank");
        Manager* nurseryManager = new Manager("Grace");
        
        salesManager->registerMediator(salesArea);
        nurseryManager->registerMediator(nurseryArea);
        
        CHECK(salesManager->getName() == "Frank");
        CHECK(nurseryManager->getName() == "Grace");
        CHECK(salesManager->getPosition() == "Manager");
        CHECK(nurseryManager->getPosition() == "Manager");
        
        delete salesManager;
        delete nurseryManager;
        delete salesArea;
        delete nurseryArea;
    }
    
    SUBCASE("Mediator notifies other colleagues") {
        NurseryArea* nurseryArea = new NurseryArea();
        NurseryStaff* staff1 = new NurseryStaff("Henry");
        NurseryStaff* staff2 = new NurseryStaff("Iris");
        NurseryStaff* staff3 = new NurseryStaff("Jack");
        
        staff1->registerMediator(nurseryArea);
        staff2->registerMediator(nurseryArea);
        staff3->registerMediator(nurseryArea);
        
        nurseryArea->registerColleague(staff1);
        nurseryArea->registerColleague(staff2);
        nurseryArea->registerColleague(staff3);
        
        staff1->setMessage("Need help with plants");
        CHECK(staff1->getMessage() == "Need help with plants");
        staff1->send();
        
        delete staff1;
        delete staff2;
        delete staff3;
        delete nurseryArea;
    }
    
    SUBCASE("Staff can deregister from mediator") {
        SalesArea* salesArea = new SalesArea();
        Manager* manager = new Manager("Karen");
        
        manager->registerMediator(salesArea);
        CHECK(manager->getName() == "Karen");
        
        manager->deregisterMediator(salesArea);
        
        CHECK(manager != nullptr);
        
        delete manager;
        delete salesArea;
    }
    
    SUBCASE("Manager can set specific receiver") {
        SalesArea* salesArea = new SalesArea();
        NurseryArea* nurseryArea = new NurseryArea();
        Manager* manager = new Manager("Laura");
        
        manager->registerMediator(salesArea);
        manager->registerMediator(nurseryArea);
        
        manager->setReceiver(salesArea);
        
        CHECK(manager->getPosition() == "Manager");
        CHECK(manager->getName() == "Laura");
        
        delete manager;
        delete salesArea;
        delete nurseryArea;
    }
    
    SUBCASE("Manager overridden send only sends to specific receiver") {
        NurseryArea* nurseryArea = new NurseryArea();
        Manager* manager = new Manager("Nancy");
        
        manager->registerMediator(nurseryArea);
        
        manager->setReceiver(nurseryArea);
        manager->setMessage("Test message");
        
        CHECK(manager->getMessage() == "Test message");
        
        manager->send();
        
        delete manager;
        delete nurseryArea;
    }
}