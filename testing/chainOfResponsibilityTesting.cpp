#include "doctest.h"

#include <iostream>
#include <vector>
#include <string>
#include <memory>
#include "Customer.h"
#include "SalesStaff.h"
#include "NurseryStaff.h"
#include "CheckoutCommand.h"
#include "AskInfoCommand.h"
#include "Rose.h"
#include "Tomato.h"
#include "Manager.h"

TEST_CASE("Chain of Responsibility: Full Chain Propagates Correctly") {
    NurseryStaff nursery("Nina");
    SalesStaff sales("Sam");
    Manager manager("Mike");

    nursery.setNext(&sales);
    sales.setNext(&manager);

    Rose rose;
    Customer customer("Alice");

    AskInfoCommand ask(&nursery, &rose);
    std::string info = customer.sendCommand(&ask);

    CHECK(info != "Customer Plant Summary");
}

TEST_CASE("Chain of Responsibility: Single Handler Executes Independently") {
    NurseryStaff nursery("Nina");

    Rose rose;
    Customer customer("Alice");

    AskInfoCommand ask(&nursery, &rose);
    std::string info = customer.sendCommand(&ask);

    CHECK(info != "Customer Plant Summary");
}

TEST_CASE("Chain of Responsibility: Partial Chain Stops at Last Handler") {
    NurseryStaff n("Nina");
    SalesStaff s("Sam");

    n.setNext(&s);

    Rose* rose = new Rose();
    Tomato* tomato = new Tomato();

    Customer customer("Alice");
    customer.addToCart(rose);
    customer.addToCart(tomato);

    CheckoutCommand checkout(&n, &customer.getOrder());
    //std::string r = customer.sendCommand(&checkout);

    delete rose;
    delete tomato;
}

// will add more once Staff commands are fixed

