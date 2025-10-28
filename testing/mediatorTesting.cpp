#include "doctest.h"
#include "../src/StaffMediator.h"
#include "../src/Staff.h"
#include "../src/SalesStaff.h"
#include "../src/NurseryStaff.h"
#include "../src/Manager.h"
#include "../src/SalesArea.h"
#include "../src/NurseryArea.h"

TEST_CASE("Mediator Pattern - Basic Registration and Setup") {
    SUBCASE("Register single colleague to mediator") {
        SalesArea* salesArea = new SalesArea();
        SalesStaff* staff = new SalesStaff("Alice");
        
        salesArea->registerColleague(staff);
        
        CHECK(staff != nullptr);
        CHECK(staff->getName() == "Alice");
        CHECK(staff->getPosition() == "Sales staff");
        
        delete staff;
        delete salesArea;
    }
    
    SUBCASE("Register multiple colleagues to same mediator") {
        SalesArea* salesArea = new SalesArea();
        SalesStaff* staff1 = new SalesStaff("Alice");
        SalesStaff* staff2 = new SalesStaff("Bob");
        SalesStaff* staff3 = new SalesStaff("Charlie");
        
        salesArea->registerColleague(staff1);
        salesArea->registerColleague(staff2);
        salesArea->registerColleague(staff3);
        
        CHECK(staff1->getName() == "Alice");
        CHECK(staff2->getName() == "Bob");
        CHECK(staff3->getName() == "Charlie");
        
        delete staff1;
        delete staff2;
        delete staff3;
        delete salesArea;
    }
    
    SUBCASE("Staff with empty name") {
        NurseryArea* nurseryArea = new NurseryArea();
        NurseryStaff* staff = new NurseryStaff("");
        
        nurseryArea->registerColleague(staff);
        CHECK(staff->getName() == "");
        CHECK(staff->getPosition() == "Nursery staff");
        
        delete staff;
        delete nurseryArea;
    }
    
    SUBCASE("Staff with special characters in name") {
        SalesArea* salesArea = new SalesArea();
        SalesStaff* staff1 = new SalesStaff("O'Brien");
        SalesStaff* staff2 = new SalesStaff("Jean-Pierre");
        SalesStaff* staff3 = new SalesStaff("Müller");
        
        salesArea->registerColleague(staff1);
        salesArea->registerColleague(staff2);
        salesArea->registerColleague(staff3);
        
        CHECK(staff1->getName() == "O'Brien");
        CHECK(staff2->getName() == "Jean-Pierre");
        CHECK(staff3->getName() == "Müller");
        
        delete staff1;
        delete staff2;
        delete staff3;
        delete salesArea;
    }
    
    SUBCASE("Register same colleague to multiple mediators") {
        SalesArea* salesArea = new SalesArea();
        NurseryArea* nurseryArea = new NurseryArea();
        Manager* manager = new Manager("MultiArea Manager");
        
        salesArea->registerColleague(manager);
        nurseryArea->registerColleague(manager);
        
        CHECK(manager->getName() == "MultiArea Manager");
        CHECK(manager->getPosition() == "Manager");
        
        delete manager;
        delete salesArea;
        delete nurseryArea;
    }
}

TEST_CASE("Mediator Pattern - Message Sending and Communication") {
    SUBCASE("Send message with empty string") {
        SalesArea* salesArea = new SalesArea();
        SalesStaff* staff = new SalesStaff("EmptyMsg");
        
        salesArea->registerColleague(staff);
        staff->setMessage("");
        CHECK(staff->getMessage() == "");
        CHECK_NOTHROW(staff->send());
        
        delete staff;
        delete salesArea;
    }
    
    SUBCASE("Send very long message") {
        NurseryArea* nurseryArea = new NurseryArea();
        NurseryStaff* staff = new NurseryStaff("LongMsg");
        
        string longMsg(1000, 'A');
        nurseryArea->registerColleague(staff);
        staff->setMessage(longMsg);
        CHECK(staff->getMessage() == longMsg);
        CHECK_NOTHROW(staff->send());
        
        delete staff;
        delete nurseryArea;
    }
    
    SUBCASE("Send message with special characters") {
        SalesArea* salesArea = new SalesArea();
        SalesStaff* staff = new SalesStaff("SpecialChar");
        
        salesArea->registerColleague(staff);
        staff->setMessage("Hello! @#$%^&*() 你好 🌱");
        CHECK_NOTHROW(staff->send());
        
        delete staff;
        delete salesArea;
    }
    
    SUBCASE("Send message with newlines and tabs") {
        NurseryArea* nurseryArea = new NurseryArea();
        NurseryStaff* staff = new NurseryStaff("Formatted");
        
        nurseryArea->registerColleague(staff);
        staff->setMessage("Line1\nLine2\tTabbed");
        CHECK(staff->getMessage() == "Line1\nLine2\tTabbed");
        CHECK_NOTHROW(staff->send());
        
        delete staff;
        delete nurseryArea;
    }
    
    SUBCASE("Multiple consecutive sends from same staff") {
        SalesArea* salesArea = new SalesArea();
        SalesStaff* staff = new SalesStaff("Chatty");
        
        salesArea->registerColleague(staff);
        
        for (int i = 0; i < 10; i++) {
            staff->setMessage("Message " + to_string(i));
            CHECK_NOTHROW(staff->send());
        }
        
        delete staff;
        delete salesArea;
    }
    
    SUBCASE("Send without setting message first") {
        NurseryArea* nurseryArea = new NurseryArea();
        NurseryStaff* staff = new NurseryStaff("NoMsg");
        
        nurseryArea->registerColleague(staff);
        CHECK_NOTHROW(staff->send());
        
        delete staff;
        delete nurseryArea;
    }
    
    SUBCASE("Multiple staff sending simultaneously") {
        SalesArea* salesArea = new SalesArea();
        SalesStaff* staff1 = new SalesStaff("Staff1");
        SalesStaff* staff2 = new SalesStaff("Staff2");
        SalesStaff* staff3 = new SalesStaff("Staff3");
        
        salesArea->registerColleague(staff1);
        salesArea->registerColleague(staff2);
        salesArea->registerColleague(staff3);
        
        staff1->setMessage("From Staff1");
        staff2->setMessage("From Staff2");
        staff3->setMessage("From Staff3");
        
        CHECK_NOTHROW(staff1->send());
        CHECK_NOTHROW(staff2->send());
        CHECK_NOTHROW(staff3->send());
        
        delete staff1;
        delete staff2;
        delete staff3;
        delete salesArea;
    }
}

TEST_CASE("Mediator Pattern - Registration and Deregistration Edge Cases") {
    SUBCASE("Staff registers mediator manually") {
        NurseryArea* nurseryArea = new NurseryArea();
        NurseryStaff* staff = new NurseryStaff("ManualReg");
        
        staff->registerMediator(nurseryArea);
        staff->setMessage("After manual registration");
        CHECK_NOTHROW(staff->send());
        
        delete staff;
        delete nurseryArea;
    }
    
    SUBCASE("Deregister and re-register mediator") {
        SalesArea* salesArea = new SalesArea();
        Manager* manager = new Manager("ReRegister");
        
        salesArea->registerColleague(manager);
        manager->setMessage("First message");
        CHECK_NOTHROW(manager->send());
        
        manager->deregisterMediator(salesArea);
        
        salesArea->registerColleague(manager);
        manager->setMessage("After re-registration");
        CHECK_NOTHROW(manager->send());
        
        delete manager;
        delete salesArea;
    }
    
    SUBCASE("Deregister from non-registered mediator") {
        SalesArea* salesArea = new SalesArea();
        NurseryArea* nurseryArea = new NurseryArea();
        Manager* manager = new Manager("WrongDeregister");
        
        salesArea->registerColleague(manager);
        CHECK_NOTHROW(manager->deregisterMediator(nurseryArea));
        
        delete manager;
        delete salesArea;
        delete nurseryArea;
    }
    
    SUBCASE("Multiple deregistrations") {
        NurseryArea* nurseryArea = new NurseryArea();
        NurseryStaff* staff = new NurseryStaff("MultiDeregister");
        
        nurseryArea->registerColleague(staff);
        staff->deregisterMediator(nurseryArea);
        CHECK_NOTHROW(staff->deregisterMediator(nurseryArea));
        
        delete staff;
        delete nurseryArea;
    }
    
    SUBCASE("Register to same mediator multiple times") {
        SalesArea* salesArea = new SalesArea();
        SalesStaff* staff = new SalesStaff("DuplicateReg");
        
        salesArea->registerColleague(staff);
        salesArea->registerColleague(staff);
        salesArea->registerColleague(staff);
        
        staff->setMessage("After multiple registrations");
        CHECK_NOTHROW(staff->send());
        
        delete staff;
        delete salesArea;
    }
}

TEST_CASE("Mediator Pattern - Manager Specific Functionality") {
    SUBCASE("Manager with null receiver broadcasts") {
        SalesArea* salesArea = new SalesArea();
        NurseryArea* nurseryArea = new NurseryArea();
        Manager* manager = new Manager("Broadcaster");
        
        salesArea->registerColleague(manager);
        nurseryArea->registerColleague(manager);
        
        manager->setReceiver(nullptr);
        manager->setMessage("Broadcast message");
        CHECK_NOTHROW(manager->send());
        
        delete manager;
        delete salesArea;
        delete nurseryArea;
    }
    
    SUBCASE("Manager switches receiver rapidly") {
        SalesArea* salesArea = new SalesArea();
        NurseryArea* nurseryArea = new NurseryArea();
        Manager* manager = new Manager("RapidSwitch");
        
        salesArea->registerColleague(manager);
        nurseryArea->registerColleague(manager);
        
        for (int i = 0; i < 5; i++) {
            manager->setReceiver(salesArea);
            manager->setMessage("To sales " + to_string(i));
            CHECK_NOTHROW(manager->send());
            
            manager->setReceiver(nurseryArea);
            manager->setMessage("To nursery " + to_string(i));
            CHECK_NOTHROW(manager->send());
        }
        
        delete manager;
        delete salesArea;
        delete nurseryArea;
    }
    
    SUBCASE("Manager sets receiver to unregistered mediator") {
        SalesArea* salesArea = new SalesArea();
        NurseryArea* nurseryArea = new NurseryArea();
        Manager* manager = new Manager("UnregisteredReceiver");
        
        salesArea->registerColleague(manager);
        
        manager->setReceiver(nurseryArea);
        manager->setMessage("To unregistered nursery");
        CHECK_NOTHROW(manager->send());
        
        delete manager;
        delete salesArea;
        delete nurseryArea;
    }
    
    SUBCASE("Manager with no registered mediators") {
        Manager* manager = new Manager("NoMediators");
        
        manager->setMessage("No mediators registered");
        CHECK_NOTHROW(manager->send());
        
        delete manager;
    }
    
    SUBCASE("Manager alternates between broadcast and targeted") {
        SalesArea* salesArea = new SalesArea();
        NurseryArea* nurseryArea = new NurseryArea();
        Manager* manager = new Manager("Alternating");
        
        salesArea->registerColleague(manager);
        nurseryArea->registerColleague(manager);
        
        manager->setReceiver(nullptr);
        manager->setMessage("Broadcast 1");
        CHECK_NOTHROW(manager->send());
        
        manager->setReceiver(salesArea);
        manager->setMessage("Targeted to sales");
        CHECK_NOTHROW(manager->send());
        
        manager->setReceiver(nullptr);
        manager->setMessage("Broadcast 2");
        CHECK_NOTHROW(manager->send());
        
        manager->setReceiver(nurseryArea);
        manager->setMessage("Targeted to nursery");
        CHECK_NOTHROW(manager->send());
        
        delete manager;
        delete salesArea;
        delete nurseryArea;
    }
}

TEST_CASE("Mediator Pattern - Cross-Area Communication") {
    SUBCASE("Large team communication in single area") {
        SalesArea* salesArea = new SalesArea();
        vector<SalesStaff*> team;
        
        for (int i = 0; i < 20; i++) {
            SalesStaff* staff = new SalesStaff("Staff" + to_string(i));
            team.push_back(staff);
            salesArea->registerColleague(staff);
        }
        
        for (auto staff : team) {
            staff->setMessage("Message from " + staff->getName());
            CHECK_NOTHROW(staff->send());
        }
        
        for (auto staff : team) {
            delete staff;
        }
        delete salesArea;
    }
    
    SUBCASE("Mixed staff types in different areas") {
        SalesArea* salesArea = new SalesArea();
        NurseryArea* nurseryArea = new NurseryArea();
        
        SalesStaff* salesStaff1 = new SalesStaff("SalesA");
        SalesStaff* salesStaff2 = new SalesStaff("SalesB");
        NurseryStaff* nurseryStaff1 = new NurseryStaff("NurseryA");
        NurseryStaff* nurseryStaff2 = new NurseryStaff("NurseryB");
        Manager* manager = new Manager("CrossManager");
        
        salesArea->registerColleague(salesStaff1);
        salesArea->registerColleague(salesStaff2);
        salesArea->registerColleague(manager);
        
        nurseryArea->registerColleague(nurseryStaff1);
        nurseryArea->registerColleague(nurseryStaff2);
        nurseryArea->registerColleague(manager);
        
        salesStaff1->setMessage("Sales update 1");
        CHECK_NOTHROW(salesStaff1->send());
        
        nurseryStaff1->setMessage("Nursery update 1");
        CHECK_NOTHROW(nurseryStaff1->send());
        
        manager->setReceiver(salesArea);
        manager->setMessage("Manager to sales");
        CHECK_NOTHROW(manager->send());
        
        manager->setReceiver(nurseryArea);
        manager->setMessage("Manager to nursery");
        CHECK_NOTHROW(manager->send());
        
        manager->setReceiver(nullptr);
        manager->setMessage("Manager broadcasts");
        CHECK_NOTHROW(manager->send());
        
        delete salesStaff1;
        delete salesStaff2;
        delete nurseryStaff1;
        delete nurseryStaff2;
        delete manager;
        delete salesArea;
        delete nurseryArea;
    }
    
    SUBCASE("Empty mediators receiving messages") {
        SalesArea* salesArea = new SalesArea();
        NurseryArea* nurseryArea = new NurseryArea();
        Manager* manager = new Manager("AloneManager");
        
        salesArea->registerColleague(manager);
        
        manager->setMessage("Talking to empty areas");
        CHECK_NOTHROW(manager->send());
        
        delete manager;
        delete salesArea;
        delete nurseryArea;
    }
}

TEST_CASE("Mediator Pattern - Staff Position Verification") {
    SUBCASE("Verify all staff positions") {
        SalesStaff* salesStaff = new SalesStaff("Sales");
        NurseryStaff* nurseryStaff = new NurseryStaff("Nursery");
        Manager* manager = new Manager("Manager");
        
        CHECK(salesStaff->getPosition() == "Sales staff");
        CHECK(nurseryStaff->getPosition() == "Nursery staff");
        CHECK(manager->getPosition() == "Manager");
        
        delete salesStaff;
        delete nurseryStaff;
        delete manager;
    }
    
    SUBCASE("Position remains consistent after operations") {
        SalesArea* salesArea = new SalesArea();
        Manager* manager = new Manager("Consistent");
        
        CHECK(manager->getPosition() == "Manager");
        
        salesArea->registerColleague(manager);
        CHECK(manager->getPosition() == "Manager");
        
        manager->setMessage("Test");
        manager->send();
        CHECK(manager->getPosition() == "Manager");
        
        manager->deregisterMediator(salesArea);
        CHECK(manager->getPosition() == "Manager");
        
        delete manager;
        delete salesArea;
    }
}

TEST_CASE("Mediator Pattern - Stress and Edge Cases") {
    SUBCASE("Rapid message changes before sending") {
        SalesArea* salesArea = new SalesArea();
        SalesStaff* staff = new SalesStaff("RapidChange");
        
        salesArea->registerColleague(staff);
        
        for (int i = 0; i < 100; i++) {
            staff->setMessage("Message " + to_string(i));
        }
        
        CHECK(staff->getMessage() == "Message 99");
        CHECK_NOTHROW(staff->send());
        
        delete staff;
        delete salesArea;
    }
    
    SUBCASE("Staff with identical names") {
        NurseryArea* nurseryArea = new NurseryArea();
        NurseryStaff* staff1 = new NurseryStaff("John");
        NurseryStaff* staff2 = new NurseryStaff("John");
        NurseryStaff* staff3 = new NurseryStaff("John");
        
        nurseryArea->registerColleague(staff1);
        nurseryArea->registerColleague(staff2);
        nurseryArea->registerColleague(staff3);
        
        staff1->setMessage("First John");
        CHECK_NOTHROW(staff1->send());
        
        staff2->setMessage("Second John");
        CHECK_NOTHROW(staff2->send());
        
        delete staff1;
        delete staff2;
        delete staff3;
        delete nurseryArea;
    }
    
    SUBCASE("Message persistence across multiple sends") {
        SalesArea* salesArea = new SalesArea();
        SalesStaff* staff = new SalesStaff("Persistent");
        
        salesArea->registerColleague(staff);
        
        staff->setMessage("Same message");
        CHECK_NOTHROW(staff->send());
        CHECK_NOTHROW(staff->send());
        CHECK_NOTHROW(staff->send());
        CHECK(staff->getMessage() == "Same message");
        
        delete staff;
        delete salesArea;
    }
}

TEST_CASE("Mediator Pattern - Receive Function Return Values") {
    SUBCASE("Staff receives simple message") {
        SalesStaff* staff = new SalesStaff("Alice");
        string result = staff->receive("Hello");
        CHECK(result == "Alice received message: Hello\n");
        delete staff;
    }
    
    SUBCASE("Staff receives empty message") {
        NurseryStaff* staff = new NurseryStaff("Bob");
        string result = staff->receive("");
        CHECK(result == "Bob received message: \n");
        delete staff;
    }
    
    SUBCASE("Staff receives message with special characters") {
        Manager* manager = new Manager("Charlie");
        string result = manager->receive("Test @#$%^&*()");
        CHECK(result == "Charlie received message: Test @#$%^&*()\n");
        delete manager;
    }
    
    SUBCASE("Staff receives long message") {
        SalesStaff* staff = new SalesStaff("Dave");
        string longMsg(100, 'X');
        string result = staff->receive(longMsg);
        string expected = "Dave received message: " + longMsg + "\n";
        CHECK(result == expected);
        delete staff;
    }
    
    SUBCASE("Staff with empty name receives message") {
        NurseryStaff* staff = new NurseryStaff("");
        string result = staff->receive("Message");
        CHECK(result == " received message: Message\n");
        delete staff;
    }
    
    SUBCASE("Multiple receives from same staff") {
        Manager* manager = new Manager("Eve");
        string result1 = manager->receive("First");
        string result2 = manager->receive("Second");
        string result3 = manager->receive("Third");
        
        CHECK(result1 == "Eve received message: First\n");
        CHECK(result2 == "Eve received message: Second\n");
        CHECK(result3 == "Eve received message: Third\n");
        delete manager;
    }
    
    SUBCASE("Different staff types receive same message") {
        SalesStaff* sales = new SalesStaff("Sales1");
        NurseryStaff* nursery = new NurseryStaff("Nursery1");
        Manager* manager = new Manager("Manager1");
        
        string msg = "Identical message";
        string result1 = sales->receive(msg);
        string result2 = nursery->receive(msg);
        string result3 = manager->receive(msg);
        
        CHECK(result1 == "Sales1 received message: Identical message\n");
        CHECK(result2 == "Nursery1 received message: Identical message\n");
        CHECK(result3 == "Manager1 received message: Identical message\n");
        
        delete sales;
        delete nursery;
        delete manager;
    }
    
    SUBCASE("Receive message with newlines") {
        SalesStaff* staff = new SalesStaff("Frank");
        string result = staff->receive("Line1\nLine2");
        CHECK(result == "Frank received message: Line1\nLine2\n");
        delete staff;
    }
    
    SUBCASE("Receive message with unicode characters") {
        NurseryStaff* staff = new NurseryStaff("Grace");
        string result = staff->receive("Hello 世界 🌱");
        CHECK(result == "Grace received message: Hello 世界 🌱\n");
        delete staff;
    }
    
    SUBCASE("Staff with special name receives message") {
        Manager* manager = new Manager("O'Brien-Smith");
        string result = manager->receive("Test");
        CHECK(result == "O'Brien-Smith received message: Test\n");
        delete manager;
    }
}