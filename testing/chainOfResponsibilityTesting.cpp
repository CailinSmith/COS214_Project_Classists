#include "doctest.h"
#include <iostream>
#include <vector>
#include <string>
#include "../src/Customer.h"
#include "../src/SalesStaff.h"
#include "../src/NurseryStaff.h"
#include "../src/Rose.h"
#include "../src/Tomato.h"
#include "../src/Manager.h"
#include "../src/AskInfoCommand.h"
#include "../src/CheckStockCommand.h"
#include "../src/RefundCommand.h"
#include "../src/CheckoutCommand.h"
#include "../src/InventoryManager.h"
#include "../src/Nursery.h"


TEST_CASE("CoR + Command: AskInfo") {
    NurseryStaff nursery("Alice");
    Rose rose;
    AskInfoCommand cmd(&nursery, &rose);
    Customer customer("Bob");
    string result = customer.sendCommand(&cmd).first;
    CHECK(result.find("Rose") != string::npos);
}

TEST_CASE("CoR + Command: CheckStock") {
    NurseryStaff nursery("Alice");
    Tomato tomato;
    CheckStockCommand cmd(&nursery, &tomato);
    Customer customer("Bob");
    string result = customer.sendCommand(&cmd).first;
    CHECK(result.find("Tomato") != string::npos);
}

TEST_CASE("CoR + Command: Checkout") {
    SalesStaff sales("Alice");
    Customer customer("Bob");
    Rose rose;
    customer.addToCart(&rose);
    CheckoutCommand cmd(&sales, &customer.getOrder(), nullptr);
    string result = customer.sendCommand(&cmd).first;
    CHECK(result.find("Rose") != string::npos);
}

TEST_CASE("CoR + Command: Refund") {
    Manager manager("Alice");
    Customer customer("Bob");

    Rose* rose = new Rose();
    Tomato* tomato = new Tomato();

    customer.addToCart(rose);
    customer.addToCart(tomato);

    std::vector<bool> flags(2, true);
    RefundCommand cmd(&manager, &customer.getOrder(), &flags);
    auto result = customer.sendCommand(&cmd);

    // Now CHECKs will PASS
    CHECK(result.first.find("Rose") != string::npos);
    CHECK(result.first.find("Tomato") != string::npos);
    CHECK(customer.getOrder().empty());
}

TEST_CASE("CoR + Command: Full Chain Flow") {
    NurseryStaff nursery("Alice");
    SalesStaff sales("Bob");
    Manager manager("Charles");
    nursery.setNext(&sales);
    sales.setNext(&manager);

    Customer customer("Don");
    Rose rose;
    customer.addToCart(&rose);

    // AskInfo
    AskInfoCommand ask(&nursery, &rose);
    CHECK(customer.sendCommand(&ask).first.find("Rose") != string::npos);

    // Checkout
    CheckoutCommand checkout(&nursery, &customer.getOrder(), nullptr);
    CHECK(customer.sendCommand(&checkout).first.find("Rose") != string::npos);
}

