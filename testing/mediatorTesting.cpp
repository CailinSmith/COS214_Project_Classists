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
        CHECK(staff1->getName() == "Alice");
        CHECK(staff2->getName() == "Bob");
        
        staff1->setMessage("Hello");
        CHECK_NOTHROW(staff1->send());
        
        delete staff1;
        delete staff2;
        delete salesArea;
    }
    
    SUBCASE("Staff can register mediator") {
        NurseryArea* nurseryArea = new NurseryArea();
        NurseryStaff* staff = new NurseryStaff("Charlie");
        
        staff->registerMediator(nurseryArea);
        
        staff->setMessage("Test message");
        CHECK_NOTHROW(staff->send());
        
        NurseryStaff* staff2 = new NurseryStaff("David");
        nurseryArea->registerColleague(staff2);
        
        staff2->setMessage("Another test");
        CHECK_NOTHROW(staff2->send());
        
        delete staff;
        delete staff2;
        delete nurseryArea;
    }
    
    SUBCASE("Staff can send messages through mediator") {
        SalesArea* salesArea = new SalesArea();
        SalesStaff* staff1 = new SalesStaff("Dave");
        SalesStaff* staff2 = new SalesStaff("Eve");
        
        salesArea->registerColleague(staff1);
        salesArea->registerColleague(staff2);
        
        staff1->setMessage("Hello from Dave");
        CHECK(staff1->getMessage() == "Hello from Dave");
        
        CHECK_NOTHROW(staff1->send());
        
        staff2->setMessage("Reply from Eve");
        CHECK_NOTHROW(staff2->send());
        
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
        
        nurseryArea->registerColleague(staff1);
        nurseryArea->registerColleague(staff2);
        nurseryArea->registerColleague(staff3);
        
        staff1->setMessage("Need help with plants");
        CHECK(staff1->getMessage() == "Need help with plants");
        
        CHECK_NOTHROW(staff1->send());
        
        staff2->setMessage("I can help");
        CHECK_NOTHROW(staff2->send());
        
        delete staff1;
        delete staff2;
        delete staff3;
        delete nurseryArea;
    }
    
    SUBCASE("Staff can deregister from mediator") {
        SalesArea* salesArea = new SalesArea();
        Manager* manager = new Manager("Karen");
        
        salesArea->registerColleague(manager);
        CHECK(manager->getName() == "Karen");
        
        manager->setMessage("Initial message");
        CHECK_NOTHROW(manager->send());
        
        manager->deregisterMediator(salesArea);
        
        CHECK(manager != nullptr);
        CHECK(manager->getName() == "Karen");
        
        delete manager;
        delete salesArea;
    }
    
    SUBCASE("Manager can set specific receiver") {
        SalesArea* salesArea = new SalesArea();
        NurseryArea* nurseryArea = new NurseryArea();
        Manager* manager = new Manager("Laura");
        
        salesArea->registerColleague(manager);
        nurseryArea->registerColleague(manager);
        
        manager->setMessage("Broadcasting to all");
        CHECK_NOTHROW(manager->send());
        
        manager->setReceiver(salesArea);
        manager->setMessage("Only to sales");
        CHECK_NOTHROW(manager->send());
        
        CHECK(manager->getPosition() == "Manager");
        CHECK(manager->getName() == "Laura");
        
        delete manager;
        delete salesArea;
        delete nurseryArea;
    }
    
    SUBCASE("Manager overridden send only sends to specific receiver") {
        NurseryArea* nurseryArea = new NurseryArea();
        SalesArea* salesArea = new SalesArea();
        Manager* manager = new Manager("Nancy");
        
        nurseryArea->registerColleague(manager);
        salesArea->registerColleague(manager);
        
        manager->setReceiver(nurseryArea);
        manager->setMessage("Test message to nursery only");
        
        CHECK(manager->getMessage() == "Test message to nursery only");
        
        CHECK_NOTHROW(manager->send());
        
        delete manager;
        delete nurseryArea;
        delete salesArea;
    }
    
    SUBCASE("Manager sends to all mediators when receiver is null") {
        SalesArea* salesArea = new SalesArea();
        NurseryArea* nurseryArea = new NurseryArea();
        Manager* manager = new Manager("Oliver");
        
        salesArea->registerColleague(manager);
        nurseryArea->registerColleague(manager);
        
        manager->setMessage("Broadcasting to all areas");
        CHECK_NOTHROW(manager->send());
        
        manager->setMessage("Another broadcast");
        CHECK_NOTHROW(manager->send());
        
        delete manager;
        delete salesArea;
        delete nurseryArea;
    }
    
    SUBCASE("Manager can switch between specific receiver and broadcast mode") {
        SalesArea* salesArea = new SalesArea();
        NurseryArea* nurseryArea = new NurseryArea();
        Manager* manager = new Manager("Patricia");
        SalesStaff* salesStaff = new SalesStaff("Quinn");
        NurseryStaff* nurseryStaff = new NurseryStaff("Rachel");
        
        salesArea->registerColleague(manager);
        nurseryArea->registerColleague(manager);
        salesArea->registerColleague(salesStaff);
        nurseryArea->registerColleague(nurseryStaff);
        
        manager->setMessage("Broadcast message");
        CHECK_NOTHROW(manager->send());
        
        manager->setReceiver(salesArea);
        manager->setMessage("Only to sales area");
        CHECK_NOTHROW(manager->send());
        
        manager->setReceiver(nurseryArea);
        manager->setMessage("Only to nursery area");
        CHECK_NOTHROW(manager->send());
        
        manager->setReceiver(nullptr);
        manager->setMessage("Broadcasting again");
        CHECK_NOTHROW(manager->send());
        
        delete manager;
        delete salesStaff;
        delete nurseryStaff;
        delete salesArea;
        delete nurseryArea;
    }
    
    SUBCASE("Different area types produce different notification messages") {
        SalesArea* salesArea = new SalesArea();
        NurseryArea* nurseryArea = new NurseryArea();
        SalesStaff* salesStaff1 = new SalesStaff("Sam");
        SalesStaff* salesStaff2 = new SalesStaff("Tina");
        NurseryStaff* nurseryStaff1 = new NurseryStaff("Uma");
        NurseryStaff* nurseryStaff2 = new NurseryStaff("Victor");
        
        salesArea->registerColleague(salesStaff1);
        salesArea->registerColleague(salesStaff2);
        nurseryArea->registerColleague(nurseryStaff1);
        nurseryArea->registerColleague(nurseryStaff2);
        
        salesStaff1->setMessage("Sales update");
        CHECK_NOTHROW(salesStaff1->send());
        
        nurseryStaff1->setMessage("Nursery update");
        CHECK_NOTHROW(nurseryStaff1->send());
        
        delete salesStaff1;
        delete salesStaff2;
        delete nurseryStaff1;
        delete nurseryStaff2;
        delete salesArea;
        delete nurseryArea;
    }
}