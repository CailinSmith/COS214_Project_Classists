#include "doctest.h"
#include "../src/StaffMediator.h"
#include "../src/Staff.h"
#include "../src/SalesStaff.h"
#include "../src/NurseryStaff.h"
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
        
        SalesStaff* salesStaff = new SalesStaff("Frank");
        NurseryStaff* nurseryStaff = new NurseryStaff("Grace");
        
        salesStaff->registerMediator(salesArea);
        nurseryStaff->registerMediator(nurseryArea);
        salesArea->registerColleague(salesStaff);
        nurseryArea->registerColleague(nurseryStaff);
        
        CHECK(salesStaff->getPosition() == "Sales staff");
        CHECK(nurseryStaff->getPosition() == "Nursery staff");
        
        delete salesStaff;
        delete nurseryStaff;
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
        staff1->send();
        
        delete staff1;
        delete staff2;
        delete staff3;
        delete nurseryArea;
    }
}