#include "doctest.h"
#include "../src/Intern.h"
#include "../src/Manager.h"
#include "../src/SalesStaff.h"
#include "../src/NurseryStaff.h"
#include "../src/Staff.h"

// will add more unit tests later once customer commands in place

TEST_CASE("Chain of Responsibility: Single Handler") {
    Intern intern("Jerry");

    CHECK(intern.getName() == "Jerry");

    intern.handleRequest();
    CHECK(true); //this passes if successful execution without seg fault
}

TEST_CASE("Chain of Responsibility: Partial Chain Stops at Last Handler") {
    Intern intern("Alice");
    Manager manager("Bob");

    intern.setNext(&manager);

    CHECK(intern.getName() == "Alice");

    intern.handleRequest();
    CHECK(true);
}

TEST_CASE("Chain of Responsibility: Full Chain"){
    Intern intern("Rick");
    Manager manager("Morty");
    SalesStaff sales("Beth");
    NurseryStaff nursery("Dave");

    intern.setNext(&manager);
    manager.setNext(&sales);
    sales.setNext(&nursery);

    CHECK(intern.getName() == "Rick");

    intern.handleRequest();
    CHECK(true);
}
